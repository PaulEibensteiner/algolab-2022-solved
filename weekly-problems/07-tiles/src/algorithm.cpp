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

using namespace std;

void testcase() {
  int w, h;
  cin >> w >> h;

  int n = 0;
  // the layout with an extra 1 tile margin
  auto to_tile = vector<vector<int>>(h + 2, vector<int>(w + 2, -1));
  auto to_tile_p = vector<pair<int, int>>();
  for (int hi = 1; hi < h + 1; hi++) {
    for (int wi = 1; wi < w + 1; wi++) {
      char field;
      cin >> field;
      if (field == '.') {
        to_tile[hi][wi] = n;
        to_tile_p.push_back(make_pair(hi, wi));
        n++;
      } else if (field != 'x') {
        cout << "wrong char" << endl;
        return;
      }
    }
  }

  if (n % 2 == 1) {
    cout << "no" << endl;
    return;
  }

  graph g(n);
  edge_adder adder(g);
  const vertex_desc v_source = boost::add_vertex(g);
  const vertex_desc v_sink = boost::add_vertex(g);

  int ni = 0;
  for (auto position : to_tile_p) {
    int h, w;
    tie(h, w) = position;
    if ((h % 2 + w % 2) % 2 == 0) {
      adder.add_edge(ni, v_sink, 1);
    } else {
      adder.add_edge(v_source, ni, 1);
    }
    ni++;
  }

  // possible second spot occupied by a tile positioned at zero
  vector<pair<int, int>> deltas = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
  // Add connections defining the second spot a tile put at h,w occupies
  for (int hi = 1; hi < h + 1; hi++) {
    int res = hi % 2;  // iterate every white field in a chess board
    for (int wi = 1 + res; wi < w + 1; wi += 2) {
      int ni = to_tile[hi][wi];
      if (ni > -1) {
        for (auto delta : deltas) {
          int d_h, d_w;
          tie(d_h, d_w) = delta;
          int mi = to_tile[hi + d_h][wi + d_w];
          if (mi > -1) {
            adder.add_edge(ni, mi, 1);
          }
        }
      }
    }
  }

  long flow = boost::push_relabel_max_flow(g, v_source, v_sink);
  if (flow == n / 2) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
