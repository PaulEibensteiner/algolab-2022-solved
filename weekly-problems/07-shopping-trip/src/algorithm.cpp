#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
// BGL include
#include <boost/graph/adjacency_list.hpp>
// BGL flow include *NEW*
#include <boost/graph/push_relabel_max_flow.hpp>

using namespace std;
// include "prettyprint.hpp";

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
  int n, m, s;
  cin >> n;
  cin >> m;
  cin >> s;

  graph g(n);
  edge_adder adder(g);
  int source = 0;
  const vertex_desc sink = boost::add_vertex(g);

  for (int si = 0; si < s; si++) {
    int store;
    cin >> store;
    adder.add_edge(store, sink, 1);
  }

  for (int mi = 0; mi < m; mi++) {
    int u, v;
    cin >> u;
    cin >> v;
	auto pair = boost::edge(u, v, g);
	if (pair.second) { // edge already exists
		// increase capacity of edge by one
		auto c_map = boost::get(boost::edge_capacity, g);
		c_map[pair.first]++;
	} else { // edge does not exist yet
    	adder.add_edge(u, v, 1);
	}
  }

  long flow = boost::push_relabel_max_flow(g, source, sink);

  if (flow == s) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }

  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
