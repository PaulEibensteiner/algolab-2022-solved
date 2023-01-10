#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K>  Triangulation;
typedef Triangulation::Edge_iterator  Edge_iterator;

void testcase(int n) {
  // read points
  std::vector<K::Point_2> pts;
  pts.reserve(n);
  for (std::size_t i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    pts.push_back(K::Point_2(x, y));
  }
  // construct triangulation
  Triangulation t;
  t.insert(pts.begin(), pts.end());

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
    int x, y;
    std::cin >> x >> y;
		auto potential_position = K::Point_2(x, y);
		Triangulation::Vertex_handle vertex_handle = t.nearest_vertex(potential_position);
		auto a = potential_position.x();
		auto b = vertex_handle->point().y();
		auto dist = (long)(potential_position - vertex_handle->point()).squared_length();

		cout << dist << endl;
	}
	
	return;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int n;
	std::cin >> n;
	while (n > 0) {
		testcase(n);
		std::cin >> n;
	}
}
