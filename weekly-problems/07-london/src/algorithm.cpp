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

const int num_chars = 26;

void testcase() {
  int h, w;

  cin >> h;
  cin >> w;
  int n = h*w;

  string msg;
  getline(cin, msg);
  getline(cin, msg);

  graph g(n + num_chars);
  edge_adder adder(g);
  const vertex_desc source = boost::add_vertex(g);
  const vertex_desc sink = boost::add_vertex(g);

  for (int i = 0; i < n; i++) {
    char l;
    cin >> l;
    int letter = l - 'A';

    adder.add_edge(source, i, 1);
    adder.add_edge(i, n+letter, 1);
  }

  for (int hi = 0; hi < h; hi++)
  {
    for (int wi = 0; wi < w; wi++)
    {
      char l;
      cin >> l;
      int letter = l - 'A';

      adder.add_edge(hi * w + (w-wi-1), n+letter, 1);
    }
  }

  auto c_map = boost::get(boost::edge_capacity, g);
  for (char const& l : msg) {
    int letter = l - 'A';
    auto pair = boost::edge(n+letter, sink, g);
    if (pair.second) { // edge already exists
      // increase capacity of edge by one
      c_map[pair.first]++;
    } else { // edge does not exist yet
        adder.add_edge(n+letter, sink, 1);
    }
  }

  long flow = boost::push_relabel_max_flow(g, source, sink);

  if (flow == msg.length()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
