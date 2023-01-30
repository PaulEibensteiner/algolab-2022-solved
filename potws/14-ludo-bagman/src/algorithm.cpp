#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

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

using namespace std;

void testcase() {
  int e, w, m, d;
  cin >> e >> w >> m >> d;

  int p, l;
  cin >> p >> l;
  const long MUCH = pow(2, 15);
  const long MAX = numeric_limits<long>().max();

  int n = 2 * w + 2 * e + 3;
  graph g(n);
  auto source = n - 1;
  auto start = n - 2;
  auto sink = n - 3;
  edge_adder adder(g);
  adder.add_edge(source, start, p, 0);
  auto c_map = boost::get(boost::edge_capacity, g);
  auto r_map = boost::get(boost::edge_reverse, g);
  auto rc_map = boost::get(boost::edge_residual_capacity, g);
  auto w_map = boost::get(boost::edge_weight, g);  // new!

  int off = w + e;
  for (int i = 0; i < w; i++) {
    adder.add_edge(start, i, l, 0);
    adder.add_edge(start, i, MAX, MUCH);
    adder.add_edge(start, i + off, MAX, MUCH);
  }

  for (int i = w; i < w + e; i++) {
    adder.add_edge(i, sink, l, 0);
    adder.add_edge(i, sink, MAX, MUCH);
    adder.add_edge(i + off, sink, MAX, MUCH);
  }

  // Non difficult matches
  for (int i = 0; i < m; i++) {
    int u, v, r;
    cin >> u >> v >> r;
    int l = u + w;
    adder.add_edge(v, l, 1, r);
  }

  // Difficult matches
  for (int i = 0; i < d; i++) {
    int u, v, r;
    cin >> u >> v >> r;
    int l = u + w;
    adder.add_edge(v + off, l + off, 1, r);
  }

  // size_t n = boost::num_vertices(g);
  long flow = boost::push_relabel_max_flow(g, source, sink);
  boost::successive_shortest_path_nonnegative_weights(g, source, sink);
  long cost = boost::find_flow_cost(g);
  assert(flow == p);

  out_edge_it ebeg, eend;
  bool schedule = true;
	
  for (boost::tie(ebeg, eend) = boost::out_edges(boost::vertex(start, g), g);
       ebeg != eend && schedule; ++ebeg) {
    if (boost::target(*ebeg, g) == source) {
      continue;
    }
    //   std::cout << "edge from " << boost::source(*ebeg, g) << " to " <<
    //   boost::target(*ebeg, g)
    //      << " with capacity " << c_map[*ebeg] << " and residual capacity " <<
    //      rc_map[*ebeg] << endl;
    if (c_map[*ebeg] == l && rc_map[*ebeg] != 0) {
      schedule = false;
    } else if (w_map[*ebeg] == MUCH) {
      cost -= MUCH * (c_map[*ebeg] - rc_map[*ebeg]);
    }
  }
	
  for (boost::tie(ebeg, eend) = boost::out_edges(boost::vertex(sink, g), g);
       ebeg != eend && schedule; ++ebeg) {
    // std::cout << "edge from " << boost::target(*ebeg, g) << " to " <<
    // boost::source(*ebeg, g)
    //    << " with capacity " << c_map[r_map[*ebeg]] << " and residual capacity
    //    " << rc_map[r_map[*ebeg]] << endl;
    if (c_map[r_map[*ebeg]] == l && rc_map[r_map[*ebeg]] != 0) {
      schedule = false;
    } else if (w_map[r_map[*ebeg]] == MUCH) {
      cost -= MUCH * (rc_map[*ebeg] - c_map[*ebeg]);
    }
  }
	
  if (!schedule) {
    cout << "No schedule!" << endl;
    return;
  }

  cout << cost << endl;
  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
