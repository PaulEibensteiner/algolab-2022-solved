#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <assert.h>

using namespace std;
vector<int> q;

int digits_for_k;
int m;
vector<vector<vector<vector<int>>>> memo;

int unique(vector<int>& li) {
	vector<int> post_li(li.end() - min((int)li.size(), m), li.end());
	sort(post_li.begin(), post_li.end());
	return unique(post_li.begin(), post_li.end()) - post_li.begin();
}

int index(vector<int>& li) {
	vector<int> post_li(li.end() - min((int)li.size(), m), li.end());
	int i = 0;
	int digit = 0;
	for (auto &&el : post_li)
	{
		i += (el + 1) * pow(2, digit*digits_for_k);
		digit += 1;
	}
	return i;
}

vector<int> nq;
vector<int> sq;

int dfs(vector<int>& curq) {
	int cur_d;
	int i1;
	int i2;

	if (nq.size() > sq.size()) {
		i1 = index(nq);
		i2 = index(sq);
		cur_d = nq.size() - sq.size();
	} else {
		i1 = index(sq);
		i2 = index(nq);
		cur_d = sq.size() - nq.size();

	}
	int cur_i = nq.size() + sq.size();

	int cur_excitement = unique(curq)*1000 - pow(2, abs(cur_d));
	if (cur_excitement < 0) {
		return -2;
	}
	
	if (cur_i == q.size()) {
		return cur_excitement;
	}

	int* cur_memo = &memo[cur_i - 1][cur_d][i1][i2];
	if (*cur_memo != -1) {
		return *cur_memo + cur_excitement;
	}

	// recurse
	int max_next_excit = -1;

	nq.push_back(q[cur_i]);
	max_next_excit = max(max_next_excit, dfs(nq));
	nq.pop_back();

	sq.push_back(q[cur_i]);
	max_next_excit = max(max_next_excit, dfs(sq));
	sq.pop_back();

	*cur_memo = max_next_excit;
	return cur_excitement + max_next_excit;

}

void testcase() {
	int n;
	short k;
	cin >> n >> k >> m;

	q = vector<int>(n);
	for (int i = 0; i < n; i++)
	{
		cin >> q[i];
	}

	digits_for_k = (int)floor(log2(k)) + 1;
	int mod = pow(2, digits_for_k * m);
	// int mod = pow(2, 6);


	nq = vector<int>();
	sq = vector<int>();
	memo = vector<vector<vector<vector<int>>>>(n, 
					vector<vector<vector<int>>>(12,
						vector<vector<int>>(mod, 
						vector<int>(mod, 
						-1))));
	nq.push_back(q[0]);

	cout <<  dfs(nq) << endl;
	
	return;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
		testcase();
}
