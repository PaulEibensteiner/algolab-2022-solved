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
vector<vector<Edge>> adjacency;
long x;
unsigned int k;
unsigned int n, m;



// Idee: BFS mit ki mitzählen, wenn ich bei k angelangt bin, dann memo[v][]
// dabei knoten auf den stack pushen

void testcase() {
  cin >> n;
  cin >> m;
  cin >> x;
  cin >> k;

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

  // stores the maximum weight sum with current range range
  auto cur_range = vector<long>(n, 0);
  auto prev_range = vector<long>(n, 0);

  bool impossible = true;
  int range;
  for (range = 1; range <= k; range++) {
    int i = 0;
    for (auto const& neighborhood : adjacency) {
      long maximum = 0;
      for (Edge edge : neighborhood) {
        maximum = max(maximum, prev_range[edge.destination] + edge.weight);
      }
      cur_range[i] = maximum;
      i++;
    }
    if (cur_range[0] >= x) {
      impossible = false;
      break;
    }
    cur_range.swap(prev_range);
  }

  cout << (impossible ? "Impossible" : to_string(range));
	return;
}

int main() {
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		testcase();
}
