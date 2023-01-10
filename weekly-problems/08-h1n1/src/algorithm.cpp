#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <assert.h>

#include <boost/heap/fibonacci_heap.hpp>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Triangulation_face_base_with_info_2.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K; 
typedef CGAL::Triangulation_vertex_base_2<K> Vb; 
struct face_info;
typedef CGAL::Triangulation_face_base_with_info_2<face_info*,K> Fb; 
typedef CGAL::Triangulation_data_structure_2<Vb,Fb> Tds;
typedef CGAL::Delaunay_triangulation_2<K,Tds> Triangulation;

struct face_info {
	bool visited;
	long key;
	Triangulation::Face_handle face_handle;
	struct Comp {
		bool operator() (const face_info* f1, const face_info* f2) const {
			return f1->key < f2->key;
		}
	};
	boost::heap::fibonacci_heap<
		face_info*, 
		boost::heap::compare<Comp>>::handle_type handle;

	face_info() : visited(false), key(-1), face_handle(Triangulation::Face_handle()) { }
};


typedef boost::heap::fibonacci_heap<face_info*, boost::heap::compare<face_info::Comp>> Priority_queue;

using namespace std;

void testcase(int n) {
	vector<K::Point_2> points(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		points[i] = K::Point_2(x, y);
	}

	Triangulation t = Triangulation(points.begin(), points.end());

	// Create info fields
	for (auto f = t.all_faces_begin(); f != t.all_faces_end(); ++f) {
		f->info() = new face_info();
		f->info()->face_handle = f;
	}

	auto  face_heap = Priority_queue();
	Triangulation::Face_circulator f = t.incident_faces(t.infinite_vertex());
	do {
		f->info()->key = LONG_MAX;
		f->info()->handle = face_heap.push(f->info());
	} while (++f != t.incident_faces(t.infinite_vertex()));

	while (!face_heap.empty()) {
		face_info* face_info = face_heap.top();
		auto face_handle = face_info->face_handle;
		assert(!face_info->visited);
		
		face_heap.pop();
		face_info->visited = true;
		
		// set all neighbor's keys to the right values
		for (int i = 0; i < 3; i++)
		{
			auto neighbor = face_handle->neighbor(i);
			auto neighbor_edge = Triangulation::Edge(make_pair(face_handle, i));
			if (t.is_infinite(neighbor_edge)) {
				continue;
			}
			long edge_length = t.segment(neighbor_edge).squared_length();
			if (!neighbor->info()->visited) {
				long new_val = min(face_info->key, edge_length);
				if (neighbor->info()->key == -1) {
					neighbor->info()->key = new_val;
					neighbor->info()->handle = face_heap.push(neighbor->info());
				} else if (new_val > neighbor->info()->key) {
					neighbor->info()->key = new_val;
					face_heap.increase(neighbor->info()->handle);
				}
			}
		}
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		auto p = K::Point_2(x, y);
		long d;
		cin >> d;
		assert(d > 0);

		auto it = t.nearest_vertex(p);
		Triangulation::Point_2 v = it->point();
		auto f = it->face();
		auto f1 = t.locate(p);
			
		if (f1->info()->key >= d*4) {
			if ((p-v).squared_length() < d) {
				cout << "n";
			} else {
				cout << "y";
			}
		} else {
			cout << "n";
		}
	}
	
	cout << endl;

	
	for (auto f = t.faces_begin(); f != t.faces_end(); ++f) {
		delete f->info();
	}
	
	return;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int n;
	for (std::cin >> n; n != 0; std::cin >> n)
		testcase(n);
}
