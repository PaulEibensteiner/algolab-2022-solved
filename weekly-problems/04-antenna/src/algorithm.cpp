#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

#include <CGAL/Exact_predicates_exact_constructions_kernel_with_sqrt.h>
#include <CGAL/Min_circle_2.h>
#include <CGAL/Min_circle_2_traits_2.h>

typedef CGAL::Exact_predicates_exact_constructions_kernel_with_sqrt EPECK;

typedef CGAL::Min_circle_2_traits_2<EPECK> Traits;
typedef CGAL::Min_circle_2<Traits> Min_circle;

long ceil_to_double(const EPECK::FT& x) {
  long a = std::ceil(CGAL::to_double(x));
  while (a < x) a += 1;
  while (a - 1 >= x) a -= 1;
  return a;
}

void testcase(int n) {
  auto points = vector<EPECK::Point_2>();
  points.reserve(n);
  for (int i = 0; i < n; i++) {
    long int x, y;
    cin >> x >> y;
    points.push_back(EPECK::Point_2(x, y));
  }

  Min_circle min_circle(points.begin(), points.end(), true);

  EPECK::FT radius = min_circle.circle().squared_radius();
  EPECK::FT radius_sqrt = CGAL::sqrt(radius);

  cout << ceil_to_double(radius_sqrt) << endl;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;
  while (n != 0) {
    testcase(n);
    cin >> n;
  }
}
