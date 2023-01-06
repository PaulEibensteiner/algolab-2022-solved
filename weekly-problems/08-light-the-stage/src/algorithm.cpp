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
#include <CGAL/Triangulation_vertex_base_with_info_2.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K>  Triangulation;
typedef Triangulation::Vertex_iterator  v_it;

void testcase() {
	int n, m;
	cin >> m >> n;

  // read points
  std::vector<K::Point_2> pts;
  pts.reserve(m);
	vector<int> rs(m);
	vector<int> point_indices(m);
  for (std::size_t i = 0; i < m; ++i) {
    int x, y, r;
    std::cin >> x >> y >> r;
    pts.push_back(K::Point_2(x, y));
		rs[i] = r;
		point_indices[i] = i;
  }

	int h;
	cin >> h;
	int r_c = h;

	vector<K::Point_2> lights;
	lights.reserve(n);
	for (int i = 0; i < n; i++)
	{
    int x, y;
    std::cin >> x >> y;
		lights.push_back(K::Point_2(x, y));
	}
	
  // construct triangulation
	vector<Triangulation::Vertex_handle> handles(n);
  Triangulation t;
	int start = 0;
	int end = n + 1; // so that n can be a target_i
	int target_i = n;
	vector<int> kept;
	vector<int> lower;
	vector<int> higher;
	while(start != end) {
		while (target_i > t.number_of_vertices()) {
			int i = t.number_of_vertices();
			handles[i] = t.insert(lights[i]);
		}
		while (target_i < t.number_of_vertices()) {
			t.remove(handles[t.number_of_vertices() - 1]);
		}

		kept = vector<int>();
		for (int p_i : point_indices) {
			auto v_handle = t.nearest_vertex(pts[p_i]);
			double d_squared = (pts[p_i] - v_handle->point()).squared_length();
			if (d_squared < pow(rs[p_i] + r_c, 2)) {
			} else {
				kept.push_back(p_i);
			}
		}

		if (kept.size() == 0) { // search left half
			higher = kept;
			end = target_i;
		} else { // search right half
			lower = kept;
			start = target_i + 1;
			point_indices = kept;
		}
		target_i = (end - start) / 2 + start;
	}
	
	vector<int> result;
	if (lower.size() == 0) {
		result = higher;
	} else {
		result = lower;
	}

	for (int i : result) {
		cout << i << " ";
	}
	cout << endl;
	return;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
		testcase();
}
