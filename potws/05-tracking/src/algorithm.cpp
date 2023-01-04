#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/property_map/property_map.hpp>
#include <boost/config.hpp>

using namespace std;

typedef boost::adjacency_list< boost::listS, boost::vecS, boost::undirectedS, boost::no_property,
  boost::property< boost::edge_weight_t, uint > >
  graph_t;
  
typedef boost::graph_traits< graph_t >::vertex_descriptor vertex_descriptor;

typedef std::pair< uint, uint > Edge;

void testcase() {
  uint n, m, k, x, y;

  cin >> n;
  cin >> m;
  cin >> k;
  cin >> x;
  cin >> y;

  // initialize normal graph
  // initialize list of rivers

  vector<Edge> edge_array;
  edge_array.reserve(k*m);
  vector<uint> edge_weights;
  edge_weights.reserve(k*m);
  
  for (uint mi = 0; mi < m; mi++) {
    // read in edge with weight
    uint a, b, c, d;

    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    

    if (!d) {
      for (uint ki = 0; ki < k+1; ki++) {
        edge_array.push_back(Edge(a+ki*n, b+ki*n));
        edge_weights.push_back(c);
      }
    } else {
      for (uint ki = 0; ki < k; ki++) {
        edge_array.push_back(Edge(a+ki*n, b+(ki+1)*n));
        edge_weights.push_back(c);
        edge_array.push_back(Edge(a+(ki+1)*n, b+ki*n));
        edge_weights.push_back(c);
      }
      // level k
      edge_array.push_back(Edge(a+k*n, b+k*n));
      edge_weights.push_back(c);
    }
  }

  graph_t g(
    edge_array.begin(), 
    edge_array.end(), 
    edge_weights.data(), 
    n*k);
    
  vector<uint> dist(boost::num_vertices(g));
  vertex_descriptor start = vertex(x, g);

  // run dijkstras algorithm

  boost::dijkstra_shortest_paths(
    g,
    start,
        boost::distance_map(
      boost::make_iterator_property_map(
                dist.begin(), get(boost::vertex_index, g)
      )
    )
  );

  cout << dist[y + k*n] << endl;
  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i)
    testcase();

  return 0;
}
