#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K> Triangulation;
typedef Triangulation::Edge_iterator Edge_iterator;

#include <CGAL/Gmpz.h>
#include <CGAL/QP_functions.h>
#include <CGAL/QP_models.h>

typedef CGAL::Gmpq Input;
typedef CGAL::Gmpq ET;
typedef CGAL::Quadratic_program<Input> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;

using namespace std;

struct W {
  int k, a;
  W(int k, int a) : k(k), a(a) {}
};

struct S {
  int d, u;
  S(int d, int u) : d(d), u(u) {}
};

double floor_to_double(const CGAL::Quotient<CGAL::Gmpq> &x) {
  auto s = CGAL::to_double(x);
  double a = std::floor(s);
  while (a > x) a -= 1;
  while (a + 1 <= x) a += 1;
  return a;
}

void testcase() {
  // Read input
  int n, m, c;
  cin >> n >> m >> c;

  vector<W> warehouses;
  warehouses.reserve(n);
  vector<K::Point_2> w_points;
  w_points.reserve(n);

  for (int i = 0; i < n; i++) {
    int x, y, k, a;
    cin >> x >> y >> k >> a;
    warehouses.emplace_back(k, a);
    w_points.emplace_back(x, y);
  }

  vector<S> stadions;
  stadions.reserve(m);
  vector<K::Point_2> s_points;
  w_points.reserve(m);

  for (int i = 0; i < m; i++) {
    int x, y, d, u;
    cin >> x >> y >> d >> u;
    stadions.emplace_back(d, u);
    s_points.emplace_back(x, y);
  }

  auto revenues = vector<vector<Input>>(n, vector<Input>(m));
  for (int w = 0; w < n; w++) {
    for (int s = 0; s < m; s++) {
      long revenue;
      cin >> revenue;
      revenues[w][s] = Input(revenue);
    }
  }

  // Find relevant circles

  Triangulation t;
  t.insert(s_points.begin(), s_points.end());
  t.insert(w_points.begin(), w_points.end());
  vector<K::Circle_2> circles;

  for (int ci = 0; ci < c; ci++) {
    int x, y, r;
    cin >> x >> y >> r;

    auto center = K::Point_2(x, y);
    auto squared_radius = pow(r, 2);
    auto distance =
        (t.nearest_vertex(center)->point() - center).squared_length();
    if (distance < squared_radius) {
      circles.push_back(K::Circle_2(center, squared_radius));
    }
  }

  // Calculate ts

  int w = 0;
  for (auto &&a : w_points) {
    int s = 0;
    for (auto &&b : s_points) {
      for (auto &&circle : circles) {
        bool a_inside = circle.has_on_bounded_side(a);
        bool b_inside = circle.has_on_bounded_side(b);
        if (a_inside != b_inside) {
          revenues[w][s] -= Input(1, 100);
        }
      }
      s++;
    }
    w++;
  }

  // Solve linear program

  Program lp(CGAL::SMALLER, true, 0, false, 0);
  // my variables
  auto variables = vector<vector<int>>(n, vector<int>(m));
  for (int w = 0; w < n; w++) {
    for (int s = 0; s < m; s++) {
      variables[w][s] = w * m + s;
    }
  }
  // objective function
  for (int w = 0; w < n; w++) {
    for (int s = 0; s < m; s++) {
      lp.set_c(variables[w][s], -revenues[w][s]);
    }
  }
  // constraint for all warehouses to not exceed supply
  int inequality_index = 0;
  for (int w = 0; w < n; w++) {
    for (int s = 0; s < m; s++) {
      lp.set_a(variables[w][s], inequality_index, 1);
    }
    lp.set_b(inequality_index, warehouses[w].k);
    inequality_index++;
  }
  // constraints for all stadions
  for (int s = 0; s < m; s++) {
    for (int w = 0; w < n; w++) {
      lp.set_a(variables[w][s], inequality_index, 1);
    }
    lp.set_b(inequality_index, stadions[s].d);
    inequality_index++;
    for (int w = 0; w < n; w++) {
      lp.set_a(variables[w][s], inequality_index, -1);
    }
    lp.set_b(inequality_index, -stadions[s].d);
    inequality_index++;
  }
  for (int s = 0; s < m; s++) {
    for (int w = 0; w < n; w++) {
      lp.set_a(variables[w][s], inequality_index, Input(warehouses[w].a, 100));
    }
    lp.set_b(inequality_index, stadions[s].u);
    inequality_index++;
  }

  Solution s = CGAL::solve_linear_program(lp, ET());

  cout << (s.is_infeasible()
               ? "RIOT!"
               : std::to_string((int)floor_to_double(-s.objective_value())))
       << endl;

  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
