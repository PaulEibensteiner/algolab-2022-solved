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
#include <boost/graph/find_flow_cost.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>
#include <boost/graph/successive_shortest_path_nonnegative_weights.hpp>

// Graph Type with nested interior edge properties for flow algorithms
typedef boost::adjacency_list_traits<boost::vecS, boost::vecS, boost::directedS>
    traits;
typedef boost::adjacency_list<
    boost::vecS, boost::vecS, boost::directedS, boost::no_property,
    boost::property<boost::edge_capacity_t, long,
                    boost::property<boost::edge_residual_capacity_t, long,
                                    boost::property<boost::edge_reverse_t,
                                                    traits::edge_descriptor>>>>
    graph;

typedef traits::vertex_descriptor vertex_desc;
typedef traits::edge_descriptor edge_desc;

// Custom edge adder class, highly recommended
class edge_adder {
  graph &G;

 public:
  explicit edge_adder(graph &G) : G(G) {}

  void add_edge(int from, int to, long capacity) {
    auto c_map = boost::get(boost::edge_capacity, G);
    auto r_map = boost::get(boost::edge_reverse, G);
    const auto e = boost::add_edge(from, to, G).first;
    const auto rev_e = boost::add_edge(to, from, G).first;
    c_map[e] = capacity;
    c_map[rev_e] = 0;  // reverse edge has no capacity!
    r_map[e] = rev_e;
    r_map[rev_e] = e;
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

  long sum = 0;
  for (int ni = 0; ni < n; ni++) {
    int balance;
    cin >> balance;
    if (balance > 0) {
      sum += balance;
      adder.add_edge(source, ni, balance);
    } else if (balance < 0) {
      adder.add_edge(ni, sink, -balance);
    }
  }

  for (int mi = 0; mi < m; mi++) {
    int u, v, d;
    std::cin >> u >> v >> d;
    adder.add_edge(u, v, d);
  }

  // long flow = boost::push_relabel_max_flow(g, source, sink);
  long flow = boost::push_relabel_max_flow(g, source, sink);
  long result = sum - flow;

  cout << (result > 0 ? "yes" : "no") << endl;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
