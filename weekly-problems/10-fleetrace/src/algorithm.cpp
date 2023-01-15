#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

// Includes
// ========
#include <iostream>
// BGL includes
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/cycle_canceling.hpp>
#include <boost/graph/find_flow_cost.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>
#include <boost/graph/successive_shortest_path_nonnegative_weights.hpp>

// Graph Type with nested interior edge properties for Cost Flow Algorithms
typedef boost::adjacency_list_traits<boost::vecS, boost::vecS, boost::directedS>
    traits;
typedef boost::adjacency_list<
    boost::vecS, boost::vecS, boost::directedS, boost::no_property,
    boost::property<
        boost::edge_capacity_t, long,
        boost::property<
            boost::edge_residual_capacity_t, long,
            boost::property<boost::edge_reverse_t, traits::edge_descriptor,
                            boost::property<boost::edge_weight_t, long> > > > >
    graph;  // new! weightmap corresponds to costs

typedef boost::graph_traits<graph>::edge_descriptor edge_desc;
typedef boost::graph_traits<graph>::out_edge_iterator out_edge_it;  // Iterator

// Custom edge adder class
class edge_adder {
  graph &G;

 public:
  explicit edge_adder(graph &G) : G(G) {}
  void add_edge(int from, int to, long capacity, long cost) {
    auto c_map = boost::get(boost::edge_capacity, G);
    auto r_map = boost::get(boost::edge_reverse, G);
    auto w_map = boost::get(boost::edge_weight, G);  // new!
    const edge_desc e = boost::add_edge(from, to, G).first;
    const edge_desc rev_e = boost::add_edge(to, from, G).first;
    c_map[e] = capacity;
    c_map[rev_e] = 0;  // reverse edge has no capacity!
    r_map[e] = rev_e;
    r_map[rev_e] = e;
    w_map[e] = cost;       // new assign cost
    w_map[rev_e] = -cost;  // new negative cost
  }
};

void testcase() {
  int b, s, p;
  cin >> b >> s >> p;

  graph G(s + b);
  edge_adder adder(G);
  auto source = boost::add_vertex(G);
  auto sink = boost::add_vertex(G);

  for (int bi = 0; bi < b; bi++) {
    adder.add_edge(source, bi, 1, 0);
    adder.add_edge(bi, sink, 1, 50);
  }

  for (int si = b; si < s + b; si++) {
    adder.add_edge(si, sink, 1, 0);
  }

  for (int i = 0; i < p; i++) {
    int bi, si, ci;
    cin >> bi >> si >> ci;
    int u = bi;
    int v = si + b;

    adder.add_edge(u, v, 1, 50 - ci);
  }

  // Run the algorithm
  boost::successive_shortest_path_nonnegative_weights(G, source, sink);
  int cost2 = boost::find_flow_cost(G);
  int spectacle_sum = 50 * b - cost2;

  cout << spectacle_sum << endl;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
