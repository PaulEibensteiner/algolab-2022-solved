#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/pending/indirect_cmp.hpp>
#include <boost/range/irange.hpp>
#include <boost/graph/strong_components.hpp>
#include <iostream>

using namespace boost;
typedef adjacency_list<vecS, vecS, directedS> graph_t;
typedef graph_traits<graph_t>::vertices_size_type size_type;
typedef graph_traits<graph_t>::edge_iterator edge_it;
typedef iterator_property_map<
    std::vector<int>::iterator,
    property_map<graph_t, vertex_index_t>::const_type>
    Weight_map;

class my_dfs_visitor : public default_dfs_visitor {

 public:
  my_dfs_visitor(int* sum, Weight_map map)
      : sum(sum), map(map) {}
  
  void discover_vertex(int u, const graph_t& g) {
    *sum += map[u];
  }
  
  int* sum;
  Weight_map map;
};

void testcase() {
  int n, m;

  cin >> n;
  cin >> m;

  auto weights = vector<int>(n, 0);
  graph_t g(n);

  for (int ni = 0; ni < n; ni++)
  {
    cin >> weights[ni];
  }

  for (int mi = 0; mi < m; mi++)
  {
    int u, v;
    std::cin >> u >> v;
    boost::add_edge(u, v, g);
  }

  auto scc_map = vector<int>(n);
  int nscc = boost::strong_components(
    g,
    boost::make_iterator_property_map(
      scc_map.begin(),
      boost::get(boost::vertex_index, g)
    )
  );

  vector<int> new_weights = vector<int>(nscc, 0);
  graph_t g_new = graph_t(nscc);

  for (int i = 0; i < n; i++)
  {
    new_weights[scc_map[i]] += weights[i];
  }

  edge_it ebeg, eend;
  for (boost::tie(ebeg, eend) = boost::edges(g); ebeg != eend; ++ebeg) {
    int u = boost::source(*ebeg, g), v = boost::target(*ebeg, g);
    int source = scc_map[u];
    int target = scc_map[v];
    if (source != target) {
      // what does it do when adding two times the same edge?
      boost::add_edge(source, target, g_new);
    }
  }

  auto indexmap = boost::get(boost::vertex_index, g);

  int max_weight = 0;
  int* sum = new int(0);
  for (int v = 0; v < nscc; v++) {
    auto colormap = boost::make_vector_property_map<boost::default_color_type>(indexmap);
    Weight_map map(new_weights.begin(), get(vertex_index, g_new));
    my_dfs_visitor myvisitor(sum, map);
    depth_first_visit(g_new, v, myvisitor, colormap);
    max_weight = max(max_weight, *sum);
    *sum = 0;
  }
  delete sum;
  
  if (max_weight == 0) {
    cout << "impossible" << endl;
  } else {
    cout << max_weight << endl;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
