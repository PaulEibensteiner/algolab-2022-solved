#include <CGAL/Gmpz.h>
#include <CGAL/QP_functions.h>
#include <CGAL/QP_models.h>
#include <CGAL/Quotient.h>

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "printlp.hpp"

using namespace std;

typedef CGAL::Gmpq ET;
// typedef CGAL::Gmpq Rational;
typedef CGAL::Gmpq IT;

// program and solution types
typedef CGAL::Quadratic_program<IT> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;

struct Point {
  IT x, y;

  Point(IT x, IT y) : x(x), y(y) {}
};

double ceil_to_double(const CGAL::Quotient<ET>& x) {
  double a = std::ceil(CGAL::to_double(x));
  while (a < x) a += 1;
  while (a - 1 >= x) a -= 1;
  return a;
}

double floor_to_double(const CGAL::Quotient<ET>& x) {
  double a = std::floor(CGAL::to_double(x));
  while (a > x) a -= 1;
  while (a + 1 <= x) a += 1;
  return a;
}

void testcase() {
  int n, m, h, w;
  cin >> n >> m >> h >> w;

  auto ns = vector<Point>();
  auto ms = vector<Point>();
  ns.reserve(n);
  ms.reserve(m);

  for (int i = 0; i < n; i++) {
    int x_orig, y_orig;
    cin >> x_orig;
    cin >> y_orig;
    ns.push_back(Point(x_orig, y_orig));
  }

  for (int i = 0; i < m; i++) {
    int x_orig, y_orig;
    cin >> x_orig;
    cin >> y_orig;
    ms.push_back(Point(x_orig, y_orig));
  }

  Program lp(CGAL::SMALLER, true, 1, false, 0);

  // My variables a_i go from 0 to n, with the corresponding center Point

  int i = 0;
  for (int ai = 0; ai < n; ai++) {
    auto Point1 = ns[ai];
    for (int aj = ai + 1; aj < n; aj++) {
      auto Point2 = ns[aj];
      if (CGAL::abs(Point1.x - Point2.x) / w >
          CGAL::abs(Point1.y - Point2.y) / h) {
        lp.set_a(ai, i, w);
        lp.set_a(aj, i, w);
        lp.set_b(i, 2 * CGAL::abs(Point1.x - Point2.x));
      } else {
        lp.set_a(ai, i, h);
        lp.set_a(aj, i, h);
        lp.set_b(i, 2 * CGAL::abs(Point1.y - Point2.y));
      }
      i++;
    }

    IT min_dist = IT(LONG_MAX);
    for (int mi = 0; mi < m; mi++) {
      auto Point2 = ms[mi];
      min_dist = min(min_dist, max(CGAL::abs(Point1.x - Point2.x) / w,
                                   CGAL::abs(Point1.y - Point2.y) / h));
    }
    lp.set_u(ai, true, 2 * min_dist - 1);
  }

  // set objective, max sum_i(a_i)

  for (int ai = 0; ai < n; ai++) {
    lp.set_c(ai, -1);
  }
	cout << lp << endl;
  auto s = CGAL::solve_linear_program(lp, ET()).objective_value();

  s = 2 * (w + h) * (-s);
  cout << (long)ceil(CGAL::to_double(s)) << endl;

  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
