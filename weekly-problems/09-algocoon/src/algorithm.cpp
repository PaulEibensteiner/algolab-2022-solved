#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
// BGL include
#include <boost/graph/adjacency_list.hpp>
// BGL flow include *NEW*
#include <boost/graph/push_relabel_max_flow.hpp>

// Graph Type with nested interior edge properties for flow algorithms
typedef boost::adjacency_list_traits<boost::vecS, boost::vecS, boost::directedS> traits;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property,
boost::property<boost::edge_capacity_t, long,
boost::property<boost::edge_residual_capacity_t, long,
boost::property<boost::edge_reverse_t, traits::edge_descriptor>>>> graph;
typedef traits::vertex_descriptor vertex_desc;
typedef traits::edge_descriptor edge_desc;
typedef boost::graph_traits<graph>::edge_iterator edge_it;

using namespace std;
// include "prettyprint.hpp";

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
    c_map[rev_e] = 0; // reverse edge has no capacity!
    r_map[e] = rev_e;
    r_map[rev_e] = e;
    }

  void clear_residuals() {
    auto rc_map = boost::get(boost::edge_residual_capacity, G);
    edge_it e_beg, e_end;
    for (boost::tie(e_beg, e_end) = boost::edges(G); e_beg != e_end; ++e_beg) {
      rc_map[*e_beg] = 0;
    }
  }

  void print_all() {
    auto c_map = boost::get(boost::edge_capacity, G);
    auto r_map = boost::get(boost::edge_reverse, G);
    auto rc_map = boost::get(boost::edge_residual_capacity, G);
    edge_it e_beg, e_end;
    for (boost::tie(e_beg, e_end) = boost::edges(G); e_beg != e_end; ++e_beg) {
      cout << boost::source(*e_beg, G) << "->" << boost::target(*e_beg, G) << ": " << "c:" << c_map[*e_beg] << " r: " << r_map[*e_beg] << " rc:" << rc_map[*e_beg] << endl;
    }
    cout << endl;
  }

};

void testcase() {
  int n, m;
  cin >> n >> m;

  graph g(n);
  edge_adder adder(g);

  for (int mi = 0; mi < m; mi++)
  {
    int a,b,c;
    cin >> a >> b >> c;
    adder.add_edge(a, b, c);
  }

  unsigned int min_flow = -1;
  for (int v = 1; v < n; v++)
  {
    // adder.print_all();
    long flow = boost::push_relabel_max_flow(g, 0, v);
    if (flow < min_flow) {
      min_flow = flow;
    }
    adder.clear_residuals();

    
    flow = boost::push_relabel_max_flow(g, v, 0);
    if (flow < min_flow) {
      min_flow = flow;
    }
    adder.clear_residuals();

  }
  cout << min_flow << endl;    
  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i)
    testcase();
}
