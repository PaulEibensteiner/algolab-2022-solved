#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

// BGL includes
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/cycle_canceling.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>
#include <boost/graph/successive_shortest_path_nonnegative_weights.hpp>
#include <boost/graph/find_flow_cost.hpp>

// Graph Type with nested interior edge properties for Cost Flow Algorithms
typedef boost::adjacency_list_traits<boost::vecS, boost::vecS, boost::directedS> traits;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property,
    boost::property<boost::edge_capacity_t, long,
        boost::property<boost::edge_residual_capacity_t, long,
            boost::property<boost::edge_reverse_t, traits::edge_descriptor,
                boost::property <boost::edge_weight_t, long> > > > > graph; // new! weightmap corresponds to costs

typedef boost::graph_traits<graph>::edge_descriptor             edge_desc;
typedef boost::graph_traits<graph>::out_edge_iterator           out_edge_it; // Iterator

// Custom edge adder class
class edge_adder {
 graph &G;

 public:
  explicit edge_adder(graph &G) : G(G) {}
  void add_edge(int from, int to, long capacity, long cost) {
    auto c_map = boost::get(boost::edge_capacity, G);
    auto r_map = boost::get(boost::edge_reverse, G);
    auto w_map = boost::get(boost::edge_weight, G); // new!
    const edge_desc e = boost::add_edge(from, to, G).first;
    const edge_desc rev_e = boost::add_edge(to, from, G).first;
    c_map[e] = capacity;
    c_map[rev_e] = 0; // reverse edge has no capacity!
    r_map[e] = rev_e;
    r_map[rev_e] = e;
    w_map[e] = cost;   // new assign cost
    w_map[rev_e] = -cost;   // new negative cost
  }
};

using namespace std;

struct Node {
	int index, time;

	Node(int index, int time) : index(index), time(time) { }
};

struct Edge {
	int start, end;
	long cap, cost;
};

void testcase() {
	int N, S;
	cin >> N >> S;


	// auto t = clock();
	auto nodes = vector<map<int, int>>(S); // time->index

	vector<int> start_caps(S);
	long start_cap_sum = 0;
	for (int i = 0; i < S; i++)
	{
		cin >> start_caps[i];
		start_cap_sum += start_caps[i];
	}

	int cur_v_index = 2;
	vector<Edge> edges(N);
	int n_edges = 0;
	long weight_sum = 0;
	for (int i = 0; i < N; i++)
	{
		int s, t, d, a, p;
		cin >> s >> t >> d >> a >> p;
		map<int, int>::iterator start_it, target_it;
		bool inserted;
		std::tie(start_it, inserted) = nodes[s-1].emplace(d, cur_v_index);
		if (inserted) {
			cur_v_index++;
		}
		std::tie(target_it, inserted) = nodes[t-1].emplace(a, cur_v_index);
		if (inserted) {
			cur_v_index++;
		}
		long cost = 100 * (a - d) - p;
		// adder.add_edge(start_it->second, target_it->second, 1, cost);
		edges[i] = { start_it->second, target_it->second, 1, cost };
	}

	graph g(cur_v_index);
	edge_adder adder(g);
	auto source = 0;
	auto sink = 1;

	for (auto &&e : edges)
	{
		n_edges++;
		weight_sum += e.cost;
		adder.add_edge(e.start, e.end, e.cap, e.cost);
	}
	
	for (int i = 0; i < S; i++)
	{
		n_edges++;
		weight_sum += 100*nodes[i].begin()->first;
		adder.add_edge(
			source, 
			nodes[i].begin()->second, 
			start_caps[i], 
			100*nodes[i].begin()->first
		);

		auto cur = nodes[i].begin();
		auto next = nodes[i].begin();
		next++;
		while (next != nodes[i].end()) {
			n_edges++;
			weight_sum += 100 * (next->first - cur->first);
			adder.add_edge(
				cur->second,
				next->second,
				100*S,
				100 * (next->first - cur->first)
			);
			next++;
			cur++;
		}
		n_edges++;
		weight_sum += 100*(100000 - nodes[i].rbegin()->first);
		adder.add_edge(
			nodes[i].rbegin()->second, 
			sink, 
				100*S,
			100*(100000 - nodes[i].rbegin()->first)
		);
	}

	boost::successive_shortest_path_nonnegative_weights(g, source, sink);
	

  long cost = boost::find_flow_cost(g);
	long profit = start_cap_sum * 100000 * 100 - cost;
	
	// t = clock() - t;
	// std::cout << t << ", ";
	// std::cout << "vertices: " << cur_v_index << " edges: " << n_edges << " weight sum: " << weight_sum << endl;
	std::cout << profit << endl;
	return;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
		testcase();
}
