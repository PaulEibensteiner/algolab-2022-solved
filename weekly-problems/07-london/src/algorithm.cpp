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
    boost::property<
        boost::edge_capacity_t, long,
        boost::property<boost::edge_residual_capacity_t, long,
                        boost::property<boost::edge_reverse_t,
                                        traits::edge_descriptor> > > >
    graph;
typedef traits::vertex_descriptor vertex_desc;
typedef traits::edge_descriptor edge_desc;

class edge_adder {
  graph &G;
  boost::adj_list_edge_property_map<
      boost::directed_tag, long, long &, unsigned long,
      boost::property<
          boost::edge_capacity_t, long,
          boost::property<
              boost::edge_residual_capacity_t, long,
              boost::property<boost::edge_reverse_t,
                              boost::detail::edge_desc_impl<boost::directed_tag,
                                                            unsigned long>,
                              boost::no_property> > >,
      boost::edge_capacity_t>
      c_map;
  boost::adj_list_edge_property_map<
      boost::directed_tag,
      boost::detail::edge_desc_impl<boost::directed_tag, unsigned long>,
      boost::detail::edge_desc_impl<boost::directed_tag, unsigned long> &,
      unsigned long,
      boost::property<
          boost::edge_capacity_t, long,
          boost::property<
              boost::edge_residual_capacity_t, long,
              boost::property<boost::edge_reverse_t,
                              boost::detail::edge_desc_impl<boost::directed_tag,
                                                            unsigned long>,
                              boost::no_property> > >,
      boost::edge_reverse_t>
      r_map;

 public:
  explicit edge_adder(graph &G) : G(G) {
    c_map = boost::get(boost::edge_capacity, G);
    r_map = boost::get(boost::edge_reverse, G);
  }

  void add_edge(int from, int to, long capacity) {
    const auto e = boost::add_edge(from, to, G).first;
    const auto rev_e = boost::add_edge(to, from, G).first;
    c_map[e] = capacity;
    c_map[rev_e] = 0;  // reverse edge has no capacity!
    r_map[e] = rev_e;
    r_map[rev_e] = e;
  }

  bool add_or_increase(int from, int to, long capacity) {
    auto pair = boost::edge(from, to, G);
    if (pair.second) {  // edge already exists
      // increase capacity of edge
      c_map[pair.first] += capacity;
      return false;
    } else {  // edge does not exist yet
      add_edge(from, to, capacity);
      return true;
    }
  }
};

const int num_chars = 26;
const int num_combinations = 325;  // 26 choose 2

int getIndex(char a, char b) {
  int x = min(a, b) - 'A';
  int y = max(a, b) - 'A';
  // a*n - ((a-1)^2 + (a-1) / 2) + (b-a) = a*n - sum_(i=0)^(a-1)i + (b-a) = sum_(i=26-1)^(26-a) i  + (b-a)
  int index = x * num_chars - ((x - 1) * (x - 1) + (x - 1)) / 2 + (y - x);
  assert(index >= 0);
  return index;
}

void testcase() {
  int h, w;

  cin >> h;
  cin >> w;
  int n = h * w;

  string msg;
  getline(cin, msg);
  getline(cin, msg);

  graph g(num_combinations + num_chars); // 26 choose 2 + |{AA, BB, CC, DD, ...}|
  edge_adder adder(g);
  const vertex_desc source = boost::add_vertex(g);
  const vertex_desc sink = boost::add_vertex(g);

  vector<char> first_page;

  for (int i = 0; i < n; i++) {
    char l;
    cin >> l;
    first_page.push_back(l);
  }

  for (int hi = 0; hi < h; hi++) {
    for (int wi = 0; wi < w; wi++) {
      char a, b;
      cin >> a;
      b = first_page[hi * w + (w - wi - 1)];
      int index = getIndex(a, b);
      bool created = adder.add_or_increase(source, index, 1);
      if (created) {
        int index_a = getIndex(a, a);
        int index_b = getIndex(b, b);
        adder.add_edge(index, index_a, numeric_limits<long>::max());
        adder.add_edge(index, index_b, numeric_limits<long>::max());
      }
    }
  }

  for (char const &l : msg) {
    int index = getIndex(l, l);
    adder.add_or_increase(index, sink, 1);
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
