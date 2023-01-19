#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Triangulation_vertex_base_with_info_2.h>

#include <algorithm>
#include <boost/pending/disjoint_sets.hpp>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Triangulation_vertex_base_with_info_2<int, K> Vb;
typedef CGAL::Triangulation_face_base_2<K> Fb;
typedef CGAL::Triangulation_data_structure_2<Vb, Fb> Tds;
typedef CGAL::Delaunay_triangulation_2<K, Tds> Triangulation;
typedef Triangulation::Edge_iterator Edge_iterator;

using namespace std;
// include "prettyprint.hpp";

void testcase() {
  // read number of points
  int n, r;
  std::cin >> n >> r;
  long r_squared = pow(r, 2);

  std::vector<K::Point_2> pts;
  pts.reserve(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    pts.push_back(K::Point_2(x, y));
  }
  int max_size = 1;
  boost::disjoint_sets_with_storage<> ds(n);
  vector<int> component_sizes(n, 1);
  // construct triangulation
  Triangulation t;
  auto handle = t.insert(pts[n - 1]);
  handle->info() = n - 1;
  for (int i = n - 2; i >= 0; i--) {
    auto handle = t.insert(pts[i]);
    handle->info() = i;
    auto current_bucket = ds.find_set(i);
    Triangulation::Edge_circulator c = t.incident_edges(handle);
    do {
      if (!t.is_infinite(c) && t.segment(c).squared_length() <= r_squared) {
        Triangulation::Vertex_handle neighbor =
            c->first->vertex((c->second + 1) % 3) != handle
                ? c->first->vertex((c->second + 1) % 3)
                : c->first->vertex((c->second + 2) % 3);

        auto neighbor_bucket = ds.find_set(neighbor->info());
        if (neighbor_bucket != current_bucket) {
          ds.link(current_bucket, neighbor_bucket);
          auto new_bucket = ds.find_set(i);
          component_sizes[new_bucket] = component_sizes[neighbor_bucket] +
                                        component_sizes[current_bucket];
          current_bucket = new_bucket;
          max_size = max(max_size, min(component_sizes[new_bucket], i));
        }
      }
    } while (++c != t.incident_edges(handle));
  }

  cout << max_size << endl;

  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
