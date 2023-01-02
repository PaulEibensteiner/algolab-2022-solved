#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

// BGL includes
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

using namespace std;

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,
  boost::no_property, boost::property<boost::edge_weight_t, int> >      weighted_graph;
typedef boost::graph_traits<weighted_graph>::edge_iterator edge_it;
typedef boost::property_map<weighted_graph, boost::edge_weight_t>::type weight_map;
typedef boost::graph_traits<weighted_graph>::edge_descriptor            edge_desc;
typedef boost::graph_traits<weighted_graph>::vertex_descriptor          vertex_desc;

int dijkstra_dist(const weighted_graph &G, int s, int t) {
  int n = boost::num_vertices(G);
  vector<int> dist_map(n);

  boost::dijkstra_shortest_paths(G, s,
    boost::distance_map(boost::make_iterator_property_map(
      dist_map.begin(), boost::get(boost::vertex_index, G))));

  return dist_map[t];
}


void testcase() {
	int n, e, s, a, b;

	cin >> n >> e >> s >> a >> b;

	auto complete_graphs = vector<weighted_graph>(s, weighted_graph(n));

	for (int ei = 0; ei < e; ei++)
	{
		int u, v;
		cin >> u >> v;

		for (weighted_graph& g : complete_graphs) {
			edge_desc e = boost::add_edge(u, v, g).first;
			weight_map weights = boost::get(boost::edge_weight, g);
			cin >> weights[e];
		}
	}

	auto hive_locations = vector<int>(s);
	for (int si = 0; si < s; si++)
	{
		cin >> hive_locations[si];
	}
	

	auto msts = vector<vector<edge_desc>>(s);
	for (int si = 0; si < s; si++) {
  	boost::kruskal_minimum_spanning_tree(complete_graphs[si], back_inserter(msts[si]));
	}
	for (int si = 0; si < s; si++) {
		sort(msts[si].begin(),msts[si].end(),
        [&](const edge_desc& e1, const edge_desc& e2){
            return boost::source(e1, complete_graphs[si]) < boost::source(e2, complete_graphs[si]) || 
									 (boost::source(e1, complete_graphs[si]) == boost::source(e2, complete_graphs[si]) && 
									 boost::target(e1, complete_graphs[si]) < boost::target(e2, complete_graphs[si]));
    });
	}

	auto all_edges = vector<edge_desc>(boost::edges(complete_graphs[0]).first, boost::edges(complete_graphs[0]).second);
	sort(all_edges.begin(), all_edges.end(),
			[&](const edge_desc& e1, const edge_desc& e2){
					return boost::source(e1, complete_graphs[0]) < boost::source(e2, complete_graphs[0]) || 
									(boost::source(e1, complete_graphs[0]) == boost::source(e2, complete_graphs[0]) && 
									boost::target(e1, complete_graphs[0]) < boost::target(e2, complete_graphs[0]));
	});
	
	auto master_graph = weighted_graph(n);
	weight_map master_weights = boost::get(boost::edge_weight, master_graph);
	// for edge in complete_graphs[0]
	auto its = vector<vector<edge_desc>::iterator>();
	auto iterators = vector<tuple<vector<edge_desc>::iterator, vector<edge_desc>::iterator, weighted_graph>>();
	for (int si = 0; si < s; si++) {
		auto g = complete_graphs[si];
		its.push_back(msts[si].begin());
		iterators.push_back(make_tuple(msts[si].begin(), msts[si].end(), g));
	}
	for (edge_desc& edge : all_edges) {
		// get minimum weight edge from all msts
		int min_weight = numeric_limits<int>::max();
		auto source = boost::source(edge, complete_graphs[0]);
		auto target = boost::target(edge, complete_graphs[0]);
		for (auto& mine : iterators) {
			vector<edge_desc>::iterator& cur = get<0>(mine);
			vector<edge_desc>::iterator& end = get<1>(mine);
			weighted_graph& g = get<2>(mine);
			// tie(cur, end, g) = mine;
			if (cur != end &&
					(boost::source(*cur, g) == source) &&
					(boost::target(*cur, g) == target)) {
				weight_map weights = boost::get(boost::edge_weight, g);
				if (weights[*cur] < min_weight) {
					min_weight = weights[*cur];
				}
				cur++;
			}
		}
		// if exists, add edge to master_graph
		if (min_weight < numeric_limits<int>::max()) {
			edge_desc e = boost::add_edge(source, target, master_graph).first;
			master_weights[e] = min_weight;
		}
	}

	// do shortest path algorithm on master_graph from a to b
	int d = dijkstra_dist(master_graph, a, b);
	cout << d << endl;
}

int main() {
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		testcase();
}
