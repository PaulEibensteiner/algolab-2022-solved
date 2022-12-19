#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
// include "prettyprint.hpp";

vector<vector<int>> dp;
vector<int> coins;
int n;

// start and end inclusive range
int minimum_optimal(int start, int end) {
	// DP Case
	if (dp[start][end] != -1) {
		return dp[start][end];
	}

	bool our_turn = (end-start+1)%2 == n%2;

	// Base case
	if (end == start) {
		if (our_turn) {
			dp[start][end] = coins[start];
			return coins[start];
		} else {
			dp[start][end] = 0;
			return 0;
		}
	}

	// Recurse
	int min_opt;
	if (our_turn) {
		min_opt = max(
			minimum_optimal(start+1, end) + coins[start],
			minimum_optimal(start, end-1) + coins[end]
		);
	} else {
		min_opt = min(
			minimum_optimal(start+1, end),
			minimum_optimal(start, end-1)
		);
	}

	dp[start][end] = min_opt;
	return min_opt;
}

void testcase() {
	cin >> n;

	dp = vector<vector<int>>(n, vector<int>(n, -1));
	coins = vector<int>(n);
	for (int i = 0; i < n; i++)
	{
		cin >> coins[i];
	}

	// minimum score when playing optimally,
	// i.e. we play optimally and so does the oponent
	int minimum_opt = minimum_optimal(0, n-1);

	cout << minimum_opt << endl;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
		testcase();
}
