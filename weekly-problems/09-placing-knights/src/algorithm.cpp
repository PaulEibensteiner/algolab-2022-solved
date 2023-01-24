#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

// Algolab BGL Tutorial 2 (Max flow, by taubnert@ethz.ch)
// Flow example demonstrating how to use push_relabel_max_flow using a custom edge adder
// to manage the interior graph properties required for flow algorithms
#include <iostream>

// BGL include
#include <boost/graph/adjacency_list.hpp>

// BGL flow include *NEW*
#include <boost/graph/push_relabel_max_flow.hpp>

// Graph Type with nested interior edge properties for flow algorithms
typedef boost::adjacency_list_traits<boost::vecS, boost::vecS, boost::directedS> traits;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property,
    boost::property<boost::edge_capacity_t, long,
        boost::property<boost::edge_residual_capacity_t, long,
            boost::property<boost::edge_reverse_t, traits::edge_descriptor>>>> graph;

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
    c_map[rev_e] = 0; // reverse edge has no capacity!
    r_map[e] = rev_e;
    r_map[rev_e] = e;
  }
};

using namespace std;


int n;
vector<vector<bool>> viable;

bool inrange(pair<int, int> v) {
	if (v.first < 0 || v.first >= n) {
		return false;
	}
	if (v.second < 0 || v.second >= n) {
		return false;
	}
	return true;
}

void add_edge_if_viable(pair<int, int> u, pair<int, int> v, edge_adder& adder) {
	if (!inrange(u) || !inrange(v)) {
		return;
	}
	if (!viable[u.first][u.second] || !viable[v.first][v.second]) {
		return;
	}
	adder.add_edge(u.first*n+u.second, v.first*n+v.second, 1);
}

void testcase() {
	cin >> n;

	graph g(n*n);
	edge_adder adder(g);
	auto source = boost::add_vertex(g);
	auto sink = boost::add_vertex(g);

	viable = vector<vector<bool>>(n, vector<bool>(n));

	int num_present_fields = 0;
	for (auto &&line : viable)
	{
		for (auto &&field : line)
		{
			int present;
			cin >> present;
			num_present_fields += present;
			field = present == 1 ? true : false;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i % 2; j < n; j += 2)
		{
			adder.add_edge(source, i*n+j, 1);
			pair<int, int> u(i, j);
			add_edge_if_viable(u, make_pair(i-1, j-2), adder);
			add_edge_if_viable(u, make_pair(i-1, j+2), adder);
			add_edge_if_viable(u, make_pair(i+1, j-2), adder);
			add_edge_if_viable(u, make_pair(i+1, j+2), adder);
			add_edge_if_viable(u, make_pair(i-2, j-1), adder);
			add_edge_if_viable(u, make_pair(i-2, j+1), adder);
			add_edge_if_viable(u, make_pair(i+2, j-1), adder);
			add_edge_if_viable(u, make_pair(i+2, j+1), adder);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = (i + 1) % 2; j < n; j += 2)
		{
			adder.add_edge(i*n+j, sink, 1);
		}
	}

  long num_min_vertex_cover = boost::push_relabel_max_flow(g, source, sink);
	long num_max_independet_set = num_present_fields - num_min_vertex_cover;
	cout << num_max_independet_set << endl;
	return;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
		testcase();
}
