#include <algorithm>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

typedef boost::adjacency_list_traits<boost::vecS, boost::vecS, boost::directedS>
    traits;
typedef boost::adjacency_list<
    boost::vecS, boost::vecS, boost::directedS, boost::no_property,
    boost::property<boost::edge_capacity_t, int,
                    boost::property<boost::edge_residual_capacity_t, int,
                                    boost::property<boost::edge_reverse_t,
                                                    traits::edge_descriptor>>>>
    Graph;
typedef traits::vertex_descriptor vertex_desc;
typedef traits::edge_descriptor edge_desc;

class edge_adder {
  Graph &G;

 public:
  explicit edge_adder(Graph &G) : G(G) {}

  void add_edge(int from, int to, int capacity) {
    auto c_map = boost::get(boost::edge_capacity, G);
    auto r_map = boost::get(boost::edge_reverse, G);
    const auto e = boost::add_edge(from, to, G).first;
    const auto rev_e = boost::add_edge(to, from, G).first;
    c_map[e] = capacity;
    c_map[rev_e] = 0;
    r_map[e] = rev_e;
    r_map[rev_e] = e;
  }
};

int m, n;

int getID(int row, int col, bool out) {
  return out ? row * (m + 2) + col : (m + 2) * (n + 2) + row * (m + 2) + col;
}

void testcase() {
  int k, c;

  std::cin >> m;
  std::cin >> n;
  std::cin >> k;
  std::cin >> c;

  Graph graph(2 * m * n + k);
  edge_adder adder(graph);

  for (int row = 1; row <= n; row++) {
    for (int col = 1; col <= m; col++) {
      int cur_out = getID(row, col, true);
      int cur_in = getID(row, col, false);

      adder.add_edge(cur_out, getID(row - 1, col, false), 1);
      adder.add_edge(cur_out, getID(row, col - 1, false), 1);
      adder.add_edge(cur_out, getID(row, col + 1, false), 1);
      adder.add_edge(cur_out, getID(row + 1, col, false), 1);

      adder.add_edge(cur_in, cur_out, c);
    }
  }

  const vertex_desc v_source = boost::add_vertex(graph);
  const vertex_desc v_sink = boost::add_vertex(graph);

  for (int ki = 0; ki < k; ki++) {
    int col, row;
    std::cin >> col;
    std::cin >> row;
    col++;
    row++;

    adder.add_edge(v_source, getID(row, col, false), 1);
  }

  // add sink to last and first row
  for (int i = 1; i <= m; i++) {
    adder.add_edge(getID(0, i, false), v_sink, std::numeric_limits<int>::max());
    adder.add_edge(getID(n + 1, i, false), v_sink,
                   std::numeric_limits<int>::max());
  }

  // add sink to last and first column
  for (int i = 1; i <= n; i++) {
    adder.add_edge(getID(i, 0, false), v_sink, std::numeric_limits<int>::max());
    adder.add_edge(getID(i, m + 1, false), v_sink,
                   std::numeric_limits<int>::max());
  }

  int flow = boost::push_relabel_max_flow(graph, v_source, v_sink);

  std::cout << flow << std::endl;

  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
