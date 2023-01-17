#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <boost/pending/disjoint_sets.hpp>

#include <CGAL/Union_find.h>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Triangulation_vertex_base_with_info_2.h>

typedef size_t Index;
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Triangulation_vertex_base_with_info_2<Index, K> Vb;
typedef CGAL::Triangulation_face_base_2<K> Fb;
typedef CGAL::Triangulation_data_structure_2<Vb,Fb> Tds;
typedef CGAL::Delaunay_triangulation_2<K,Tds> Triangulation;
typedef Triangulation::Edge_iterator  Edge_iterator;

typedef boost::vector_property_map<std::string> vpm;

using namespace std;

int num_f(vector<int> n_component_size_i, int k) {
	// This is bullshit
	int result = 0;
	for (int i = k-1; i > 0; i--)
	{
		for (int j = 1; j < i; j++)
		{
			int num = min(n_component_size_i[i], n_component_size_i[j]);
			result += num;
			n_component_size_i[i] -= num;
			n_component_size_i[j] -= num;
		}
		int num = n_component_size_i[i] / ceil((float)k / (float)i);
		result += num;
		n_component_size_i[i] -= num * ceil((float)k / (float)i);
	}
	int sum = 0;
	for (int i = 0; i < k; i++)
	{
		sum += n_component_size_i[i];
	}
	if (sum >= k) {
		cout << "Error" << endl;
	}
	
	return result;
}

void testcase() {
	int n, k, f;
	long s;
	cin >> n >> k >> f;
	cin >> s;
	std::vector<pair<K::Point_2, Index>> pts;
  pts.reserve(n);
  for (Index i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    pts.push_back(make_pair(K::Point_2(x, y), i));
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

	vector<Triangulation::Edge>::iterator it;
	int n_components = n;
	int n_components_geq_k = k > 1 ? 0 : n;
	int cur_f = n_components_geq_k;
	vector<int> n_component_size_i(k, 0);
	n_component_size_i[1] = n;
	// map from set handle to size
	vector<int> sizes(n, 1);
	boost::disjoint_sets_with_storage<> ds(n);
	long max_s = -1;
	int max_f = -1;
	for (it = edges.begin(); it != edges.end() && (max_s == -1 || max_f == -1); ++it) {
		if (t.segment(*it).squared_length() >= s && max_f == -1) {
			max_f = cur_f;
		}

		// union current minimum edge's vertices
		Triangulation::Vertex_handle v1 = it->first->vertex((it->second + 1) % 3);
		Triangulation::Vertex_handle v2 = it->first->vertex((it->second + 2) % 3);
		Index i1 = ds.find_set(v1->info());
		Index i2 = ds.find_set(v2->info());

		if (i1 != i2) {
			n_components--;

			int i1_size = sizes[i1];
			if (i1_size >= k) {
				n_components_geq_k--;
			} else {
				n_component_size_i[i1_size]--;
			}
			int i2_size = sizes[i2];
			if (i2_size >= k) {
				n_components_geq_k--;
			} else {
				n_component_size_i[i2_size]--;
			}
			
			ds.link(i1, i2);
			
			Index i3 = ds.find_set(v1->info());
			sizes[i3] = i1_size + i2_size;
			if (sizes[i3] >= k) {
				n_components_geq_k++;
			} else {
				n_component_size_i[sizes[i3]]++;
			}
		}

		// assuming sizes are correct:
		cur_f = n_components_geq_k + num_f(n_component_size_i, k);

		if (cur_f < f && max_s == -1) {
			max_s = t.segment(*it).squared_length();
			cur_f = n_components_geq_k + num_f(n_component_size_i, k);
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
