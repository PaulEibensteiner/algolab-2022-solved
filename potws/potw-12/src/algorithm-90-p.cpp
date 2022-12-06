#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

#include <boost/graph/adjacency_list.hpp>

using namespace std;
// include "prettyprint.hpp";

// BGL Graph definitions
// =====================

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS,
  boost::no_property,                         // no vertex property
  boost::property<boost::edge_weight_t, unsigned int,
  boost::property<boost::edge_weight2_t, long int>>  // interior edge weight property
> weighted_graph;
typedef boost::property_map<weighted_graph, boost::edge_weight_t>::type weight_map;
typedef boost::property_map<weighted_graph, boost::edge_weight2_t>::type weight_sum_map;
typedef boost::graph_traits<weighted_graph>::edge_descriptor            edge_desc;


typedef boost::graph_traits<weighted_graph>::edge_iterator edge_it;
typedef boost::graph_traits<weighted_graph>::out_edge_iterator out_edge_it;

vector<unsigned int> gold;
weight_map weights;
weight_sum_map weight_sums;
long int sum;
int t;
weighted_graph g;

int get_weight_sum(edge_desc edge) {
  if (weight_sums[edge] != -1) {
    return weight_sums[edge];
  }

  long int weight_sum = weights[edge];
  auto target = boost::target(edge, g);
  out_edge_it oe_beg, oe_end;
  for (boost::tie(oe_beg, oe_end) = boost::out_edges(target, g); oe_beg != oe_end; ++oe_beg) {
    weight_sum += get_weight_sum(*oe_beg);
  }
  weight_sums[edge] = weight_sum;
  return weight_sum;
}

void priority_dfs(int v) {
  sum += gold[v] - t;

  // sort out edges and call priority_dfs on them in order
  // get out_edge indices
  int n = g.out_edge_list(v).size();
  auto iterators = boost::out_edges(v, g);
  auto list = vector<edge_desc>(n);
  partial_sort_copy(
    iterators.first, iterators.second, 
    list.begin(), list.end(),
  [](
    const edge_desc& e1, 
    const edge_desc& e2) -> bool {
      return get_weight_sum(e1) < get_weight_sum(e2);
    });
  // call priority_dfs in order
  for (auto it = list.begin(); it != list.end(); it++) {
    t += weights[*it];
    priority_dfs(boost::target(*it, g));
    t += weights[*it];
  }
}

void testcase() {
  int n;
  cin >> n;

  gold = vector<unsigned int>(n+1, 0);
  for (int i = 1; i < n+1; i++)
  {
    cin >> gold[i];
  }

  g = weighted_graph(n+1);
  weights = boost::get(boost::edge_weight, g);
  weight_sums = boost::get(boost::edge_weight2, g);

  for (int i = 0; i < n; i++)
  {
    int u, v;
    unsigned int d;
    cin >> u >> v;
    cin >> d;

    edge_desc e = boost::add_edge(u, v, g).first;
    weights[e] = d;
    weight_sums[e] = -1;
  }

  sum = 0;
  t = 0;

  priority_dfs(0);

  cout << sum << endl;

  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i)
    testcase();
}
