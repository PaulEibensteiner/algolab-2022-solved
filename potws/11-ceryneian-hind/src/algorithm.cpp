#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

#include <iostream>
// BGL includes
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/cycle_canceling.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>
#include <boost/graph/successive_shortest_path_nonnegative_weights.hpp>
#include <boost/graph/find_flow_cost.hpp>

// Graph Type with nested interior edge properties for Cost Flow Algorithms
typedef boost::adjacency_list_traits<boost::vecS, boost::vecS, boost::directedS> traits;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property,
    boost::property<boost::edge_capacity_t, long,
        boost::property<boost::edge_residual_capacity_t, long,
            boost::property<boost::edge_reverse_t, traits::edge_descriptor,
                boost::property <boost::edge_weight_t, long> > > > > graph; // new! weightmap corresponds to costs

typedef boost::graph_traits<graph>::edge_descriptor             edge_desc;
typedef boost::graph_traits<graph>::out_edge_iterator           out_edge_it; // Iterator

// Custom edge adder class
class edge_adder {
 graph &G;

 public:
  explicit edge_adder(graph &G) : G(G) {}
  void add_edge(int from, int to, long capacity, long cost) {
    auto c_map = boost::get(boost::edge_capacity, G);
    auto r_map = boost::get(boost::edge_reverse, G);
    auto w_map = boost::get(boost::edge_weight, G); // new!
    const edge_desc e = boost::add_edge(from, to, G).first;
    const edge_desc rev_e = boost::add_edge(to, from, G).first;
    c_map[e] = capacity;
    c_map[rev_e] = 0; // reverse edge has no capacity!
    r_map[e] = rev_e;
    r_map[rev_e] = e;
    w_map[e] = cost;   // new assign cost
    w_map[rev_e] = -cost;   // new negative cost
  }
};

void testcase() {
  int n, m;

  cin >> n;
  cin >> m;

  graph g(n);
  edge_adder adder(g);
  auto source = boost::add_vertex(g);
  auto sink = boost::add_vertex(g);

  auto weights = vector<int>(n, 0);
  for (int ni = 0; ni < n; ni++)
  {
    int score;
    cin >> score;
    if (score > 0) {
      adder.add_edge(source, ni, score, 0);
    } else if (score < 0) {
      adder.add_edge(ni, sink, -score, 0);
    }
    adder.add_edge(ni, sink, LONG_MAX, 1);
  }

  for (int mi = 0; mi < m; mi++)
  {
    int u, v;
    std::cin >> u >> v;
    adder.add_edge(u, v, LONG_MAX, 0);
  }

  // long flow = boost::push_relabel_max_flow(g, source, sink);
  boost::successive_shortest_path_nonnegative_weights(g, source, sink);
  int cost = boost::find_flow_cost(g);

  cout << (cost > 0 ? to_string(cost) : "impossible") << endl;

}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
