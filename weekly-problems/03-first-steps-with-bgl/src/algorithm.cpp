#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

// BGL includes
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,
                              boost::no_property,
                              boost::property<boost::edge_weight_t, int> >
    weighted_graph;
typedef boost::property_map<weighted_graph, boost::edge_weight_t>::type
    weight_map;
typedef boost::graph_traits<weighted_graph>::edge_descriptor edge_desc;
typedef boost::graph_traits<weighted_graph>::vertex_descriptor vertex_desc;

using namespace std;

void testcase() {
  int n, m;

  cin >> n >> m;

  weighted_graph G(n);
  weight_map weights = boost::get(boost::edge_weight, G);

  for (int mi = 0; mi < m; mi++) {
    int u, v, w;
    cin >> u >> v >> w;

    edge_desc e = boost::add_edge(u, v, G).first;
    weights[e] = w;
  }

  // Maximum distance
  std::vector<int> dist_map(n);
  boost::dijkstra_shortest_paths(
      G, 0,
      boost::distance_map(boost::make_iterator_property_map(
          dist_map.begin(), boost::get(boost::vertex_index, G))));
  int d = *max_element(dist_map.begin(), dist_map.end());

  // MST
  std::vector<edge_desc>
      mst;  // vector to store MST edges (not a property map!)
  boost::kruskal_minimum_spanning_tree(G, std::back_inserter(mst));

  int mst_sum = 0;
  for (auto edge : mst) {
    mst_sum += weights[edge];
  }

  cout << mst_sum << " " << d << endl;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
