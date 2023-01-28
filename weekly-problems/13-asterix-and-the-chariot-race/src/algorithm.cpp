#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> adjacency;
vector<int> cost;
vector<vector<int>> memo;

int cheapest_without_prev(int v);
int cheapest_with_prev(int v);

int cheapest_with_v(int v) {
	if (memo[0][v] != -1) {
		return memo[0][v];
	}

	int min_cost = cost[v];
	for (auto &&neighbor : adjacency[v])
	{
		min_cost += cheapest_with_prev(neighbor);
	}
	
	memo[0][v] = min_cost;
	return min_cost;
}

int cheapest_with_prev(int v) {
	if (memo[1][v] != -1) {
		return memo[1][v];
	}

	// with this one
	int min_cost = cheapest_with_v(v);

	// without this one
	int cur_cost = 0;
	for (auto &&neighbor : adjacency[v])
	{
		cur_cost += cheapest_without_prev(neighbor);
	}
	min_cost = min(min_cost, cur_cost);

	memo[1][v] = min_cost;
	return min_cost;
}

int cheapest_without_prev(int v) {
	if (memo[2][v] != -1) {
		return memo[2][v];
	}

	// with this one
	int min_cost = cheapest_with_v(v);

	// without this one, choose a child
	// includes any combination of children too
	for (auto &&neighbor : adjacency[v])
	{
		int cur_cost = 0;
		for (auto &&n : adjacency[v])
		{
			if (n == neighbor) {
				cur_cost += cheapest_with_v(n);
			} else {
				cur_cost += cheapest_without_prev(n);
			}
		}
		min_cost = min(min_cost, cur_cost);
	}
	
	memo[2][v] = min_cost;
	return min_cost;
}

void testcase() {
	int n;
	cin >> n;

	adjacency = vector<vector<int>>(n);
	for (int ni = 0; ni < n-1; ni++)
	{
		int i, j;
		cin >> i >> j;
		adjacency[i].push_back(j);
	}

	cost = vector<int>(n);
	for (int ni = 0; ni < n; ni++)
	{
		cin >> cost[ni];
	}

	memo = vector<vector<int>>(3, vector<int>(n, -1));
	int min_cost = cheapest_without_prev(0);

	cout << min_cost << endl;
	
	return;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
		testcase();
}
