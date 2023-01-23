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
};

void testcase() {
  int h, w;

  cin >> h;
  cin >> w;

  string msg;
  getline(cin, msg);
  getline(cin, msg);

  graph g(26);
  edge_adder adder(g);
  const vertex_desc source = boost::add_vertex(g);
  const vertex_desc sink = boost::add_vertex(g);

  vector<vector<char>> first_page(h, vector<char>(w));

  for (int hi = 0; hi < h; hi++) {
    for (int wi = 0; wi < w; wi++) {
      cin >> first_page[hi][wi];
    }
  }

  vector<int> letter_counts(26, 0);
  vector<int> letter_pair_counts(26*26, 0);

  for (int hi = 0; hi < h; hi++) {
    for (int wi = 0; wi < w; wi++) {
      char a, b;
      cin >> a;
      b = first_page[hi][w-wi-1];
      int x = min(a, b) - 'A';
      int y = max(a, b) - 'A';
      int pair_index = x*26 + y;
      letter_counts[x]++;
      letter_pair_counts[pair_index]++;
    }
  }

  for (int i = 0; i < 26; i++)
  {
    if (letter_counts[i] != 0) {
      adder.add_edge(source, i, letter_counts[i]);
    }
  }

  for (int i = 0; i < 26*26; i++)
  {
    if (letter_pair_counts[i] != 0) {
      adder.add_edge(i / 26, i % 26, letter_pair_counts[i]);
    }
  }

  vector<int> msg_letter_counts(26, 0);
  for (int i = 0; i < msg.length(); i++)
  {
    msg_letter_counts[msg[i] - 'A']++;
  }
  
  for (int i = 0; i < 26; i++)
  {
    if (msg_letter_counts[i] != 0) {
      adder.add_edge(i, sink, msg_letter_counts[i]);
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
