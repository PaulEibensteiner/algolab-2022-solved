#include <algorithm>
#include <boost/graph/adjacency_list.hpp>
#include <boost/rational.hpp>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

// BGL Graph definitions
// =====================

struct Subtree_info {
  int verts;
  long weightsum;

  Subtree_info(int verts, long weightsum)
      : verts(verts), weightsum(weightsum) {}

  Subtree_info() : verts(0), weightsum(0) {}
};

typedef boost::adjacency_list<
    boost::vecS, boost::vecS, boost::directedS,
    boost::no_property,  // no vertex property
    boost::property<boost::edge_weight_t, unsigned int,
                    boost::property<boost::edge_weight2_t,
                                    Subtree_info>>  // interior edge weight
                                                    // property
    >
    weighted_graph;
typedef boost::property_map<weighted_graph, boost::edge_weight_t>::type
    weight_map;
typedef boost::property_map<weighted_graph, boost::edge_weight2_t>::type
    weight_sum_map;
typedef boost::graph_traits<weighted_graph>::edge_descriptor edge_desc;

typedef boost::graph_traits<weighted_graph>::edge_iterator edge_it;
typedef boost::graph_traits<weighted_graph>::out_edge_iterator out_edge_it;

vector<unsigned int> gold;
weight_map weights;
weight_sum_map weight_sums;
long int sum;
int t;
weighted_graph g;

void priority_dfs(int v) {
  sum += gold[v] - t;

  // sort out edges and call priority_dfs on them in order
  // get out_edge indices
  int n = g.out_edge_list(v).size();
  auto iterators = boost::out_edges(v, g);
  auto list = vector<edge_desc>(n);
  partial_sort_copy(iterators.first, iterators.second, list.begin(), list.end(),
                    [](const edge_desc& e1, const edge_desc& e2) -> bool {
                      return weight_sums[e1].verts * weight_sums[e2].weightsum >
                             weight_sums[e1].weightsum * weight_sums[e2].verts;
                    });
  // call priority_dfs in order
  for (auto it = list.begin(); it != list.end(); it++) {
    t += weights[*it];
    priority_dfs(boost::target(*it, g));
    t += weights[*it];
  }
}

Subtree_info build_dfs(int v) {
  Subtree_info info(1, 0);
  out_edge_it oe_beg, oe_end;
  for (boost::tie(oe_beg, oe_end) = boost::out_edges(v, g); oe_beg != oe_end;
       ++oe_beg) {
    Subtree_info neighbor_info = build_dfs(boost::target(*oe_beg, g));
    weight_sums[*oe_beg] = Subtree_info(
        neighbor_info.verts, neighbor_info.weightsum + weights[*oe_beg]);
    info.verts += neighbor_info.verts;
    info.weightsum += neighbor_info.weightsum + weights[*oe_beg];
  }

  return info;
}

void testcase() {
  int n;
  cin >> n;

  gold = vector<unsigned int>(n + 1, 0);
  for (int i = 1; i < n + 1; i++) {
    cin >> gold[i];
  }

  g = weighted_graph(n + 1);
  weights = boost::get(boost::edge_weight, g);
  weight_sums = boost::get(boost::edge_weight2, g);

  for (int i = 0; i < n; i++) {
    int u, v;
    unsigned int d;
    cin >> u >> v;
    cin >> d;

    edge_desc e = boost::add_edge(u, v, g).first;
    weights[e] = d;
  }

  sum = 0;
  t = 0;

  build_dfs(0);
  priority_dfs(0);

  cout << sum << endl;

  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
