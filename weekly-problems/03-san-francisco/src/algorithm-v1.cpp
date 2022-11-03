#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>

using namespace std;
// include "prettyprint.hpp";

struct Edge
{
	unsigned int destination, weight;

	Edge(unsigned int d, unsigned int w) : destination(d), weight(w) {};
};

struct Vertex {
	unsigned int v, k;
	Vertex(unsigned int v, unsigned int k) : v(v), k(k) {};
};

// at vertex i_1, we need 
vector<vector<long>> memo;
vector<vector<Edge>> adjacency;
long x;
unsigned int k;
unsigned int n, m;

// How many points can I get from vertex v with 1...k moves?
// = max: edge i + how many points can I get from neighbor i with 0...k-1 moves
// base case: How many points can I get from v with 0 moves? 0
// second base case: How many points can I get while points_already > x ? infty

// what is the minimum number of moves to get weight x?
// min vk, vk-1, ... where points > x

// Problem with DFS: Might arrive at a point earlier with a smaller remaining k and then only 
// compute too little ks
// Problem with pure DFS: does not include endpoints of circles

stack<Vertex> bfs(unsigned int v_0) {
	vector<bool> visited(n, false);
	visited[v_0] = true;
	stack<Vertex> output;
	int ki = k;

	auto cur_queue = new queue<int>();
	cur_queue->push(v_0);
	auto next_queue = new queue<int>();

	while(!cur_queue->empty() && ki >= 0)
	{
		while (!cur_queue->empty()) {
			int cur = cur_queue->front();
			output.push(Vertex(cur, ki));
			cur_queue->pop();

			for (auto edge: adjacency[cur])
			{
				if (!visited[edge.destination])
				{
					visited[edge.destination] = true;
					next_queue->push(edge.destination);
				}
			}
		}
		ki--;
		swap(cur_queue, next_queue);
	}
	delete cur_queue;
	delete next_queue;
	return output;
}

// calculates the maximum points achieveable in 0...k turns starting at v
void max_points(unsigned int v, unsigned int k_cur) {
	// if we already computed this return
	// but if we're going in a circle we might
	// have computed to few k's yet
	if (memo[v].size() > k_cur) {
		return;
	}
	
	// If available turns are zero we can't get points
	if (k_cur <= 0) {
		memo[v] = { 0 };
		return;
	}

	// If child's memos don't exist (probably a circle) go dfs
	for (Edge edge : adjacency[v]) {
		if (memo[edge.destination].size() < k_cur) {
			max_points(edge.destination, k_cur - 1);
		}
	}

	// then simply calculate
	memo[v].reserve(k_cur+1);
	for (size_t ki = memo[v].size(); ki <= k_cur; ki++)
	{
		if (ki == 0) {
			memo[v].push_back(0);
			continue;
		}
		long maximum = -1;
		for (Edge edge : adjacency[v]) {
			maximum = max(maximum, edge.weight + memo[edge.destination][ki-1]);
		}
		memo[v].push_back(maximum);
	}
}



// Idee: BFS mit ki mitzählen, wenn ich bei k angelangt bin, dann memo[v][]
// dabei knoten auf den stack pushen

void testcase() {
    cin >> n;
		cin >> m;
		cin >> x;
		cin >> k;

		memo = vector<vector<long>>(n);
		adjacency = vector<vector<Edge>>(n);

		for (size_t mi = 0; mi < m; mi++)
		{
			unsigned int u, v, p;
			cin >> u;
			cin >> v;
			cin >> p;

			adjacency[u].push_back(Edge(v, p));
		}
		// Add out-edges of starting vertex to ones without any out-edges
		for (auto& edges : adjacency) {
			if (edges.empty()) {
				edges = adjacency[0];
			}
		}

		auto bfs_stack = bfs(0);
		
		while (!bfs_stack.empty()) {
			auto cur = bfs_stack.top();
			bfs_stack.pop();
			max_points(cur.v, cur.k);
		}

		unsigned int num_turns = 0;
		for (size_t ki = 0; ki <= k; ki++)
		{
			if (memo[0][ki] >= x) {
				num_turns = ki;
				break;
			}
		}
		// cout << memo[0][num_turns] << " points can be reached in num turns: ";
		cout << (num_turns > 0 ? to_string(num_turns) : "Impossible") << endl;
    
	return;
}

int main() {
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		testcase();
}
