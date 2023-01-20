#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

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


void testcase() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> vs(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vs[i];
	}
	
	int col_size = n+1;
	graph g(col_size*m);
	edge_adder adder(g);
	auto source = boost::add_vertex(g);
	auto sink = boost::add_vertex(g);

	for (int col = 0; col < m; col++)
	{
		for (int i = 0; i < n; i++)
		{
			int from = col*col_size+i;
			int to = col*col_size+i+1;
			adder.add_edge(from, to, 1, 0);
		}
	}
	adder.add_edge(source, 0, 1, 0);

	int start = 0;
	int end = 0;
	int sum = 0;
	while (end < n+1) {
		if (sum == k) {
			int cost = n-(end-start);
			int col;
			for (col = 0; col < m-1; col++)
			{
				int from = col*col_size+start;
				int to = (col+1)*col_size+end;
				adder.add_edge(
					from, 
					to, 
					1, 
					cost);
			}
			int from = col*col_size+start;
			adder.add_edge(
				from, 
				sink, 
				1, 
				cost);
			sum += vs[end];
			end++;
			sum -= vs[start];
			start++;
		} else if (sum < k) {
			sum += vs[end];
			end++;
		} else if (sum > k) {
			sum -= vs[start];
			start++;
		}
	}

	boost::successive_shortest_path_nonnegative_weights(g, source, sink);
  long cost = boost::find_flow_cost(g);
	long result = m*n - cost;

	cout << (cost > 0 ? to_string(result) : "fail") << endl;

	return;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
		testcase();
}
