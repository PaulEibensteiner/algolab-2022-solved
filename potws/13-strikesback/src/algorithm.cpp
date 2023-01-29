#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

// example: how to solve a simple explicit LP
#include <CGAL/Gmpq.h>
#include <CGAL/QP_functions.h>
#include <CGAL/QP_models.h>

// choose input type (input coefficients must fit)
typedef CGAL::Gmpq IT;
// choose exact type for solver (CGAL::Gmpz or CGAL::Gmpq)
typedef CGAL::Gmpq ET;

// program and solution types
typedef CGAL::Quadratic_program<IT> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;

#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K> Triangulation;

using namespace std;

struct A {
  K::Point_2 p;
  int k;
};

void testcase() {
  int na, ns, nb;
  cin >> na >> ns >> nb;

  int e_sum;
  cin >> e_sum;

  vector<A> asteroids(na);
  for (int i = 0; i < na; i++) {
    int x, y, d;
    cin >> x >> y >> d;
    asteroids[i] = {K::Point_2(x, y), d};
  }

  vector<K::Point_2> shots(ns);
  // lp indices
  vector<int> e(ns);
  for (int s = 0; s < ns; s++) {
    int x, y;
    cin >> x >> y;
    shots[s] = K::Point_2(x, y);
    e[s] = s;
  }

  vector<K::Point_2> bounty(nb);
  for (int s = 0; s < nb; s++) {
    int x, y;
    cin >> x >> y;
    bounty[s] = K::Point_2(x, y);
  }

  // construct triangulation
  Triangulation t;
  t.insert(bounty.begin(), bounty.end());

  Program lp(CGAL::LARGER, true, 0, false, 0);
  int eq_i = 0;

  // Calculate radii (= max radii)
  const int MAXR = pow(2, 30);
  vector<long> r(ns);
  for (int s = 0; s < ns; s++) {
    if (nb == 0) {
      r[s] = MAXR;
    } else if (nb == 1) {
      K::FT d = (bounty.front() - shots[s]).squared_length();
      r[s] = d;
    } else {
      auto closest_it = t.nearest_vertex(shots[s]);
      K::FT d = (closest_it->point() - shots[s]).squared_length();
      r[s] = d;
    }
  }

  // edge sum
  for (int s = 0; s < ns; s++) {
    lp.set_a(e[s], eq_i, -1);
  }
  lp.set_b(eq_i, -e_sum);
  eq_i++;

  // destroy every asteroid
  for (auto &&a : asteroids) {  // only 30 so this might be feasible
    bool inrange = false;
    for (int s = 0; s < ns; s++) {
      long d = (a.p - shots[s]).squared_length();
      if (d <= r[s]) {
        inrange = true;
        IT factor = IT(1, max(1l, d));
        lp.set_a(e[s], eq_i, factor);
      }
    }
    if (!inrange) {
      cout << "n" << endl;
      return;
    }
    lp.set_b(eq_i, a.k);
    eq_i++;
  }

  Solution s = CGAL::solve_linear_program(lp, ET());

  cout << (s.is_infeasible() ? "n" : "y") << endl;
  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
