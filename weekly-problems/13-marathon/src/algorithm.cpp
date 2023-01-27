#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>

#include <boost/graph/dijkstra_shortest_paths.hpp>

#include <boost/graph/adjacency_list.hpp>
// BGL flow include *NEW*
#include <boost/graph/push_relabel_max_flow.hpp>

// Graph Type with nested interior edge properties for flow algorithms
typedef boost::adjacency_list_traits<boost::vecS, boost::vecS, boost::directedS> traits;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property,
    boost::property<boost::edge_capacity_t, long,
        boost::property<boost::edge_residual_capacity_t, long,
            boost::property<boost::edge_reverse_t, traits::edge_descriptor>>>> graph;

// Custom edge adder class, highly recommended
class edge_adder {
  graph &G;

 public:
  explicit edge_adder(graph &G) : G(G) {}

  bool add_edge(int from, int to, long capacity) {
    auto c_map = boost::get(boost::edge_capacity, G);
    auto r_map = boost::get(boost::edge_reverse, G);
		boost::graph_traits<graph>::edge_descriptor e;
		bool success;
    tie(e, success) = boost::add_edge(from, to, G);
    const auto rev_e = boost::add_edge(to, from, G).first;
    c_map[e] = capacity;
    c_map[rev_e] = 0; // reverse edge has no capacity!
    r_map[e] = rev_e;
    r_map[rev_e] = e;
		return success;
  }
};

// Dijkstra's

typedef boost::adjacency_list<boost::setS, boost::vecS, boost::undirectedS, boost::no_property,
	boost::property<boost::edge_weight_t, int,
		boost::property<boost::edge_capacity_t, long> > >     weighted_graph;
typedef boost::property_map<weighted_graph, boost::edge_weight_t>::type weight_map;
typedef boost::graph_traits<weighted_graph>::edge_descriptor            edge_desc;
typedef boost::graph_traits<weighted_graph>::vertex_descriptor          vertex_desc;
typedef boost::graph_traits<weighted_graph>::out_edge_iterator out_edge_it;

using namespace std;

void testcase() {
	int n, m, s, f;
	cin >> n >> m >> s >> f;

	weighted_graph g(n);
  auto c_map = boost::get(boost::edge_capacity, g);
	auto w_map = boost::get(boost::edge_weight, g);

	for (int i = 0; i < m; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		if (a == b) {
			continue; // because weight > 0 a loop can never be part of the shortest path
		}
		bool success;
		edge_desc e;
		tie(e, success) = boost::add_edge(a, b, g);
		if (success) {
			c_map[e] = c;
			w_map[e] = d;
		} else {
			if (w_map[e] > d) { // Equal start/end edges with higher weight cant be part of shortest path
				c_map[e] = c;
				w_map[e] = d;
			} else if (w_map[e] == d) {
				c_map[e] += c;
			}
		}
	}

	// modified dijstra's
	vector<int> d(n, INT_MAX);
	vector<bool> visited(n, false);
	vector<list<int>> predecesors(n);
	priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> q;

	d[s] = 0;
	q.emplace(0, s);

	// Do dijkstra's while keeping multiple predecessors if they have same distance
	while (!q.empty()) {
		int u, cur_d;
		tie(cur_d, u) = q.top();
		q.pop();
		if (visited[u]) {
			continue;
		}

		out_edge_it edge_it, oe_end;
		for (boost::tie(edge_it, oe_end) = boost::out_edges(u, g);edge_it != oe_end; ++edge_it) {
			vertex_desc v = boost::target(*edge_it, g);
			if (w_map[*edge_it] + d[u] < d[v]) {
				d[v] = w_map[*edge_it] + d[u];
				predecesors[v] = list<int>(1, u);
				q.emplace(d[v], v);
			} else if (w_map[*edge_it] + d[u] == d[v]) {
				predecesors[v].push_back(u);
			}
		}
		visited[u] = true;
	}

	graph gn(n);
	edge_adder an(gn);
	// add all edges, that are part of a minimum length path to s, to max flow graph
	visited = vector<bool>(n, false);
	list<int> vertices_on_path(1, f);
	while (!vertices_on_path.empty())
	{
		int v = vertices_on_path.front();
		vertices_on_path.pop_front();
		if (visited[v]) {
			continue;
		}
		for (auto &&u : predecesors[v])
		{
			auto e = boost::edge(u, v, g).first;
			long cap = c_map[e];
			an.add_edge(u, v, cap);
			vertices_on_path.push_back(u);
		}
		visited[v] = true;
	}
	
	long flow = boost::push_relabel_max_flow(gn, s, f);
	cout << flow << endl;
	
	return;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
		testcase();
}
