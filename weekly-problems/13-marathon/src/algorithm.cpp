#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

#include <boost/graph/dijkstra_shortest_paths.hpp>

// BGL include
#include <boost/graph/adjacency_list.hpp>

// BGL flow include *NEW*
#include <boost/graph/push_relabel_max_flow.hpp>

// Graph Type with nested interior edge properties for flow algorithms
typedef boost::adjacency_list_traits<boost::vecS, boost::vecS, boost::directedS> traits;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property,
  boost::property<boost::edge_weight_t, int,
		boost::property<boost::edge_capacity_t, long,
        boost::property<boost::edge_residual_capacity_t, long,
            boost::property<boost::edge_reverse_t, traits::edge_descriptor>>>>> graph;

typedef boost::property_map<graph, boost::edge_weight_t>::type weight_map;

boost::graph_traits<graph>::edge_descriptor            edge_desc;
typedef boost::graph_traits<graph>::vertex_descriptor          vertex_desc;

// Custom edge adder class, highly recommended
class edge_adder {
  graph &G;

 public:
  explicit edge_adder(graph &G) : G(G) {}

  void add_edge(int from, int to, long capacity, int weight) {
    auto c_map = boost::get(boost::edge_capacity, G);
    auto r_map = boost::get(boost::edge_reverse, G);
		auto weights = boost::get(boost::edge_weight, G);
    const auto e = boost::add_edge(from, to, G).first;
    const auto rev_e = boost::add_edge(to, from, G).first;
    c_map[e] = capacity;
    c_map[rev_e] = 0; // reverse edge has no capacity!
    r_map[e] = rev_e;
    r_map[rev_e] = e;
		weights[e] = weight;
  }
};

using namespace std;

int n, m, s, f;

vector<vector<vertex_desc>> paths;

pair<vector<vertex_desc>, int> dijkstra_dist(const graph &g, int s, int t) {
	std::vector<int> dist_map(n);
	std::vector<vertex_desc> pred_map(n);

	boost::dijkstra_shortest_paths(
		g, 
		s, 
		boost::distance_map(
			boost::make_iterator_property_map(
				dist_map.begin(), 
				boost::get(boost::vertex_index, g)
			)
		).predecessor_map(
			boost::make_iterator_property_map(
				pred_map.begin(), 
				boost::get(boost::vertex_index, g)
			)
		)
	);
	
	int cur = t;
	vector<vertex_desc> path;
	path.push_back(cur);
	while (s != cur) {
		cur = pred_map[cur];
		path.push_back(cur);
	}
	std::reverse(path.begin(), path.end());
	return make_pair(path, dist_map[t]);
}


void testcase() {
	cin >> n >> m >> s >> f;

	graph g(n);
	edge_adder adder(g);

	for (int i = 0; i < m; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		adder.add_edge(a, b, c, d);
	}

	graph gn(n);
	edge_adder an(gn);

	
	
	return;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
		testcase();
}
