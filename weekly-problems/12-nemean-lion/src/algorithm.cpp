#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Gmpq.h>

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
typedef Triangulation::Finite_faces_iterator Face_iterator;

using namespace std;
Triangulation t;
typedef CGAL::Gmpq rational;

bool adjacentIsObtuse(Triangulation::Edge e) {
  if (t.is_infinite(e.first)) {
    return true;
  }

  rational c(t.segment(e).squared_length());
  rational a(
      t.segment(Triangulation::Edge(e.first, Triangulation::cw(e.second)))
          .squared_length());
  rational b(
      t.segment(Triangulation::Edge(e.first, Triangulation::ccw(e.second)))
          .squared_length());

  return a + b > c;
}

rational getSquaredRadius(Triangulation::Face_handle f) {
  if (t.is_infinite(f)) {
    return rational(numeric_limits<long>().max(), 1l);
  }
  rational a((f->vertex(0)->point() - f->vertex(1)->point()).squared_length());
  rational b((f->vertex(1)->point() - f->vertex(2)->point()).squared_length());
  rational c((f->vertex(2)->point() - f->vertex(0)->point()).squared_length());
  rational A = 4 * a * b - (a + b - c) * (a + b - c);

  auto radius_squared = (a * b * c) / A;
  return radius_squared;
}

void testcase() {
  std::size_t n;
  std::cin >> n;
  long x;
  cin >> x;
  auto s = x;
  int h;
  cin >> h;
  // read points
  std::vector<K::Point_2> pts;
  pts.reserve(n);
  for (std::size_t i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    pts.push_back(K::Point_2(x, y));
  }
  // construct triangulation
  t = Triangulation();
  t.insert(pts.begin(), pts.end());

  int a_2 = 0;
  int a_s = 0;
  auto set_minima = vector<rational>();
  auto set_maxima = vector<rational>();

  auto min_radius_squared_2 = rational(numeric_limits<long>().max(), 1l);
  for (Edge_iterator e = t.finite_edges_begin(); e != t.finite_edges_end();
       ++e) {
    auto e1 = *e;
    auto e2 = t.mirror_edge(*e);
    rational min_radius_squared;
    if (!adjacentIsObtuse(e1) || !adjacentIsObtuse(e2)) {  // blocked
      min_radius_squared =
          min(getSquaredRadius(e1.first), getSquaredRadius(e2.first));
    } else {
      long diameter_squared = t.segment(e1).squared_length();
      min_radius_squared = rational(diameter_squared, 4l);
    }

    if (min_radius_squared < min_radius_squared_2) {
      min_radius_squared_2 = min_radius_squared;
      a_2 = 1;
    } else if (min_radius_squared == min_radius_squared_2) {
      a_2++;
    }

    rational max_radius_squared =
        max(getSquaredRadius(e1.first), getSquaredRadius(e2.first));

    if (s >= min_radius_squared && s <= max_radius_squared) {
      a_s++;
    }

    set_maxima.push_back(max_radius_squared);
    set_minima.push_back(min_radius_squared);
  }

  int a_3 = 0;
  auto min_radius_squared_3 = getSquaredRadius(t.finite_faces_begin());

  for (Face_iterator f = t.finite_faces_begin(); f != t.finite_faces_end();
       ++f) {
    auto radius_squared = getSquaredRadius(f);
    if (radius_squared < min_radius_squared_3) {
      min_radius_squared_3 = radius_squared;
      a_3 = 1;
    } else if (radius_squared == min_radius_squared_3) {
      a_3++;
    }
  }

  sort(set_minima.begin(), set_minima.end());
  sort(set_maxima.begin(), set_maxima.end());
  auto plus_it = set_minima.begin();
  auto minus_it = set_maxima.begin();
  int current = 0;
  int a_max = 0;
  while (true) {
    if (plus_it != set_minima.end() && *plus_it <= *minus_it) {
      current++;
      a_max = max(a_max, current);
      plus_it++;
    } else if (minus_it != set_maxima.end()) {
      current--;
      minus_it++;
    } else {
      break;
    }
  }

  cout << a_2 << " " << a_3 << " " << a_s << " " << a_max << endl;

  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
