#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <assert.h>

using namespace std;
int n;
int m;
int k;
vector<int> weights;
vector<vector<int>> neighbors;
set<int> result;

list<int> node_indices;
multiset<int> heap;
vector<multiset<int>::iterator> iterators;
void dfs(int cur) {
	// Add node to data structures
	node_indices.push_back(cur);
	iterators[cur] = heap.insert(weights[cur]);

	// Remove from data structures
	int to_remove_i = -1;
	multiset<int>::iterator to_remove_it;
	if (node_indices.size() > m) {
		to_remove_i = node_indices.front();
		node_indices.pop_front();
		heap.erase(iterators[to_remove_i]);
	}
	
	// check if we found a solution
	if ((node_indices.size() == m) &&  // TODO does this work?
	    (*--heap.end() - *heap.begin() <= k)) {
		result.insert(node_indices.front());
	}

	// recurse into tree
	for (int neighbor: neighbors[cur]) {
		dfs(neighbor);
	}

	// readd removed 
	if (to_remove_i != -1) {
		node_indices.push_front(to_remove_i);
		iterators[to_remove_i] = heap.insert(weights[to_remove_i]);
	}
	
	// remove added
	assert(node_indices.back() == cur);
	node_indices.pop_back();
	heap.erase(iterators[cur]);
}



void testcase() {
	// ll of node indices
	// vector: index -> iterator in heap
	// when adding to ll, add to heap and add iterator to vector O(log heapsize)
	// when removing from ll, remove from heap and remove iterator O(1)
	// get min and max from heap O(1), get index to output from ll
	cin >> n;
	cin >> m;
	cin >> k;
	weights = vector<int>(n);
	neighbors = vector<vector<int>>(n, vector<int>());

	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}
	

	for (int i = 0; i < n-1; i++)
	{
		int u, v;
		cin >> u;
		cin >> v;
		neighbors[u].push_back(v);
	}

	// initialize all data structures
	result = set<int>();
	node_indices = list<int>();
	heap = multiset<int>();
	iterators = vector<multiset<int>::iterator>(n);

	dfs(0);

	if (result.size() != 0) {
	for (auto el : result)
	{
		cout << el << " ";
	}
	} else {
		cout << "Abort mission";
	}
	cout << endl;
	return;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
		testcase();
}
