#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Triangulation_vertex_base_with_info_2.h>
#include <CGAL/Triangulation_face_base_2.h>
#include <boost/pending/disjoint_sets.hpp>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>

// Epic kernel is enough, no constructions needed, provided the squared distance
// fits into a double (!)
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
// we want to store an index with each vertex
typedef std::size_t                                            Index;
typedef CGAL::Triangulation_vertex_base_with_info_2<Index,K>   Vb;
typedef CGAL::Triangulation_face_base_2<K>                     Fb;
typedef CGAL::Triangulation_data_structure_2<Vb,Fb>            Tds;
typedef CGAL::Delaunay_triangulation_2<K,Tds>                  Delaunay;

// As edges are not explicitly represented in the triangulation, we extract them
// from the triangulation to be able to sort and process them. We store the
// indices of the two endpoints, first the smaller, second the larger, and third
// the squared length of the edge. The i-th entry, for i=0,... of a tuple t can
// be accessed using std::get<i>(t).
typedef std::tuple<Index,Index,K::FT> Edge;
typedef std::vector<Edge> EdgeV;

using namespace std;

void testcase() {
	int n, m, k;
	long s;
	cin >> n >> m >> s >> k;

	// trees

  EdgeV edges;
  edges.reserve(3*n); // there can be no more in a planar graph
  typedef std::pair<K::Point_2,Index> IPoint;
	Delaunay t;
	
	std::vector<IPoint> points;
	points.reserve(n);
	for (Index i = 0; i < n; ++i) {
		int x, y;
		std::cin >> x >> y;
		points.emplace_back(K::Point_2(x, y), i);
	}

	if (n > 1) {

		t.insert(points.begin(), points.end());
		// extract edges and sort by (squared) length
		// This step takes O(n log n) time (for the sorting).
		for (auto e = t.finite_edges_begin(); e != t.finite_edges_end(); ++e) {
			Index i1 = e->first->vertex((e->second+1)%3)->info();
			Index i2 = e->first->vertex((e->second+2)%3)->info();
			// ensure smaller index comes first
			if (i1 > i2) std::swap(i1, i2);
			edges.emplace_back(i1, i2, t.segment(e).squared_length());
		}
		std::sort(
			edges.begin(),
			edges.end(),
			[](const Edge& e1, const Edge& e2) -> bool {
					return std::get<2>(e1) < std::get<2>(e2);
			}
		);
	}

	// bones
	// distance, closest tree index
	vector<pair<K::FT, Index>> distances(m);
	for (int i = 0; i < m; i++)
	{
    int x, y;
    std::cin >> x >> y;
		auto bone = K::Point_2(x, y);
		K::Point_2 closest_tree;
		Index index;
		if (n > 1) {
			auto it = t.nearest_vertex(bone);
			closest_tree = it->point();
			index = it->info();
		} else {
			tie(closest_tree, index) = points.front();
		}
		K::FT d = (bone - closest_tree).squared_length();
		distances[i] = { 4*d, index };
	}
	sort(
		distances.begin(),
		distances.end()
	);

  // setup and initialize union-find data structure
  boost::disjoint_sets_with_storage<> uf(n);
  vector<int> component_sizes(n, 0);
	int max_cc = 0;

	long a = -1;
	long q = -1;
	auto d_it = distances.begin();
	auto e_it = edges.begin();
	while (a == -1 || q == -1) {
		if (e_it == edges.end() && d_it == distances.end()) {
			assert(q != -1);
			a = max_cc;
			break;
		}
		K::FT d; 
		if (e_it == edges.end() || 
			 (d_it != distances.end() && d_it->first < get<2>(*e_it))) { // next in lists is a distance
			Index i;
			tie(d, i) = *d_it;
			if (d > s && a == -1) {
				a = max_cc;
			}
			Index set = uf.find_set(i);
			d_it++;
			component_sizes[set]++;
			max_cc = max(max_cc, component_sizes[set]);
		} else { // next is an edge
			Index i1, i2;
			tie(i1, i2, d) = *e_it;
			e_it++;
			if (d > s && a == -1) {
				a = max_cc;
			}
			Index c1 = uf.find_set(i1);
			Index c2 = uf.find_set(i2);
			if (c1 != c2) {
				uf.link(c1, c2);
				int new_comp_size = component_sizes[c1] + component_sizes[c2];
				max_cc = max(max_cc, new_comp_size);
				component_sizes[uf.find_set(i1)] = new_comp_size;
			}
		}

		if (q == -1 && max_cc >= k) {
			q = d;
		}
	}

	cout << a << " " << q << endl;
	return;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
		testcase();
}
