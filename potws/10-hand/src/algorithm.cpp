#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

#include <CGAL/Union_find.h>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Triangulation_vertex_base_with_info_2.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Triangulation_vertex_base_with_info_2<CGAL::Union_find<int>::handle, K> Vb;
typedef CGAL::Triangulation_face_base_2<K> Fb;
typedef CGAL::Triangulation_data_structure_2<Vb,Fb> Tds;
typedef CGAL::Delaunay_triangulation_2<K,Tds> Triangulation;
typedef Triangulation::Edge_iterator  Edge_iterator;

typedef boost::vector_property_map<std::string> vpm;

using namespace std;

void testcase() {
	int n, k, f;
	long s;
	cin >> n >> k >> f;
	cin >> s;
	std::vector<pair<K::Point_2, CGAL::Union_find<int>::handle>> pts;
  pts.reserve(n);
	CGAL::Union_find<int> ds;
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
		auto handle = ds.make_set(i);
    pts.push_back(make_pair(K::Point_2(x, y), handle));
  }
  // construct triangulation
  Triangulation t;
  t.insert(pts.begin(), pts.end());

	// sort edges
	vector<Triangulation::Edge> edges;
	for (auto it = t.finite_edges_begin(); it != t.finite_edges_end(); ++it) {
		edges.push_back(*it);
	}


	sort(
		edges.begin(), 
		edges.end(), 
		[&t] (const Triangulation::Edge& e1, const Triangulation::Edge& e2) {
			return t.segment(e1).squared_length() < t.segment(e2).squared_length();
		}
	);
/* 
	cout << endl;
	for (auto edge : edges) {
		cout << t.segment(edge).squared_length() << " ";
	}
	cout << endl;
 */

	// Every union might remove one set
	int min_num_sets = n;
	vector<Triangulation::Edge>::iterator it;
	long max_s = -1;
	int max_f = -1;
	for (it = edges.begin(); it != edges.end() && (max_s == -1 || max_f == -1); ++it) {
		if (t.segment(*it).squared_length() >= s && max_f == -1) {
			max_f = ds.number_of_sets();
		}

		// union current minimum edge's vertices
		Triangulation::Vertex_handle v1 = it->first->vertex((it->second + 1) % 3);
		Triangulation::Vertex_handle v2 = it->first->vertex((it->second + 2) % 3);
		ds.unify_sets(v1->info(), v2->info());

		min_num_sets--;

		if (min_num_sets < f && max_s == -1) {
			int actual_num_sets = ds.number_of_sets();
			if (actual_num_sets < f) {
				max_s = t.segment(*it).squared_length();
			}
			min_num_sets = actual_num_sets;
		}
	}

	if (max_f == -1) {
		max_f = 1;
	}

	
	
	cout << max_s << " " << max_f << endl;
	
	return;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
		testcase();
}
