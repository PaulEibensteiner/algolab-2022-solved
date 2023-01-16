#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<int> as;
vector<int> bs;
vector<int> sub_as;
vector<int> sub_bs;
vector<vector<int>> best;

int getbest(int start_a, int start_b) {

	if (best[start_a][start_b] != -1)
	{
		return best[start_a][start_b];
	}

	if (start_a == n-1 || start_b == n-1) {
		int result = (sub_as[n] - sub_as[start_a]) * (sub_bs[n] - sub_bs[start_b]);
		return result;
	}

	// sum from [i, j[ = sub[j] - sub[i]
	
	int min = numeric_limits<int>::max();
	for (int i = start_a+1; i < n; i++)
	{
		int j = start_b+1;
		min = std::min(min, (sub_as[i] - sub_as[start_a]) * (sub_bs[j] - sub_bs[start_b]) + getbest(i, j));
	}

	for (int j = start_b+1; j < n; j++)
	{
		int i = start_a+1;
		min = std::min(min, (sub_as[i] - sub_as[start_a]) * (sub_bs[j] - sub_bs[start_b]) + getbest(i, j));
	}

	best[start_a][start_b] = min;
	return min;
}


void testcase() {
	cin >> n;

	as = vector<int>(n);
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		as[i] = a-1;
	}

	bs = vector<int>(n);
	for (int i = 0; i < n; i++)
	{
		int b;
		cin >> b;
		bs[i] = b-1;
	}

	sub_as = vector<int>(n+1, 0);
	sub_bs = vector<int>(n+1, 0);

	for (int i = 1; i < n+1; i++)
	{
		sub_as[i] = sub_as[i-1]+as[i-1];
		sub_bs[i] = sub_bs[i-1]+bs[i-1];
	}
	

	best = vector<vector<int>>(n, vector<int>(n, -1));
	int result = getbest(0, 0);
	cout << result << endl;	
	return;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	// int k = 3*(9+12) + (5+5+7+6+4)*2 + 3*(4+3+5+7) + 7*6;
	// int k1 = 3*(9+12) + (5+5+7)*2 + 6*4 + 4*3 + 3*(5+7) + 7*6;
	// cout << k1;
	// return 0;

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
		testcase();
}
