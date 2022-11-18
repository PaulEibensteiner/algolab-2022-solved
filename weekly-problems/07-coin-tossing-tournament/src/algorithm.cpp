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
    Graph;
typedef traits::vertex_descriptor vertex_desc;
typedef traits::edge_descriptor edge_desc;

class Edge_adder {
  Graph &G;

 public:
  explicit Edge_adder(Graph &G) : G(G) {}
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

  auto known_scores = vector<int>(n, 0);

  Graph graph(n + m);
  Edge_adder adder(graph);
  const vertex_desc v_source = boost::add_vertex(graph);
  const vertex_desc v_sink = boost::add_vertex(graph);

  // Vertices of index [0,n[ are players, [n,m[ are games

  for (int i = 0; i < m; i++) {
    int player_a, player_b, outcome;
    cin >> player_a;
    cin >> player_b;
    cin >> outcome;

    if (outcome != 0) {
      int winner_i = outcome == 1 ? player_a : player_b;
      known_scores[winner_i]++;
    } else {
      int game_i = n + i;

      adder.add_edge(game_i, player_a, 1);
      adder.add_edge(game_i, player_b, 1);
      adder.add_edge(v_source, game_i, 1);
    }
  }

  int unknown_scores_sum = 0;
  int scores_sum = 0;

  for (int i = 0; i < n; i++) {
    int score_player_i;
    cin >> score_player_i;
    scores_sum += score_player_i;

    int unknown_score_player_i = score_player_i - known_scores[i];
    if (unknown_score_player_i > 0) {
      unknown_scores_sum += unknown_score_player_i;
      adder.add_edge(i, v_sink, unknown_score_player_i);
    }
  }

  long flow = boost::push_relabel_max_flow(graph, v_source, v_sink);

  if (scores_sum == m && unknown_scores_sum == flow) {
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
