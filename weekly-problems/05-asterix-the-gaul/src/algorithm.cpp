#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct Movement {
	int d,t;
	Movement(int d, int t) : d(d), t(t) { }
};

struct Subsum {
	long d, t;
	int n;
};

void brute_force() {
	int n, m;
	cin >> n >> m;
	long D, T;
	cin >> D >> T;

	auto movs = vector<Movement>();
	movs.reserve(n);
	auto add_d = vector<long>();
	add_d.reserve(m);

	for (int i = 0; i < n; i++)
	{
		long d, t;
		cin >> d >> t;
		movs.push_back(Movement(d, t));
	}

	for (int i = 0; i < m; i++)
	{
		long s;
		cin >> s;
		add_d.push_back(s);
	}

	int min_potions = m+1;
	int max_mask = 2 << (n - 1);
	for (int mask = 1; mask < max_mask; mask++)
	{
		long d_sum = 0;
		long t_sum = 0;
		for (int i = 0; i < n; i++)
		{
			if ((mask >> i) % 2 ) {
				d_sum += movs[i].d;
				t_sum += movs[i].t;
			}
		}
		
		if (t_sum < T) {
			if (d_sum >= D) {
				cout << 0 << endl;
				return;
			} else {
				double bits = (double)__builtin_popcount(mask);

				long s_target = (long)std::ceil((double)(D - d_sum) / bits);

				auto it = std::lower_bound(add_d.begin(), add_d.end(), s_target);
				if (it != add_d.end()) {
					// get iterator index
					int i = it - add_d.begin();
					min_potions = min(min_potions, i+1);
				}
			}
		}
	}
	
	if (min_potions == m+1) {
		cout << "Panoramix captured" << endl;
	} else {
		cout << min_potions << endl;
	}
}

void split_and_list() {
	int n, m;
	cin >> n >> m;
	long D, T;
	cin >> D >> T;

	auto movs = vector<Movement>();
	movs.reserve(n);
	auto potions = vector<long>();
	potions.reserve(m+1);

	for (int i = 0; i < n; i++)
	{
		long d, t;
		cin >> d >> t;
		movs.push_back(Movement(d, t));
	}

	potions.push_back(0);
	for (int i = 0; i < m; i++)
	{
		long s;
		cin >> s;
		potions.push_back(s);
	}

	// binary search for right amount of potions
	// use split and list in each search step to figure out if feasible

	// prepare split and list
	vector<Subsum> first_half;
	int first_half_length = (int)floor((double)n / 2.0);
	int max_mask = 1 << first_half_length;
	first_half.reserve(max_mask);
	for (int mask = 0; mask < max_mask; mask++)
	{
		long d_sum = 0;
		long t_sum = 0;
		int n_cur = 0;
		for (int i = 0; i < n; i++)
		{
			if ((mask >> i) % 2 ) {
				d_sum += movs[i].d;
				t_sum += movs[i].t;
				n_cur++;
			}
		}
		
		if (t_sum < T) {
			if (d_sum >= D) {
				cout << 0 << endl;
				return;
			} else {
				first_half.push_back({d_sum, t_sum, n_cur});
			}
		}
	}

	
	vector<Subsum> second_half;
	max_mask = 1 << (int)ceil((double)n / 2.0);
	second_half.reserve(max_mask);
	for (int mask = 0; mask < max_mask; mask++)
	{
		long d_sum = 0;
		long t_sum = 0;
		int n_cur = 0;
		for (int i = 0; i < n; i++)
		{
			if ((mask >> i) % 2 ) {
				d_sum += movs[i+first_half_length].d;
				t_sum += movs[i+first_half_length].t;
				n_cur++;
			}
		}
		
		if (t_sum < T) {
			if (d_sum >= D) {
				cout << 0 << endl;
				return;
			} else {
				second_half.push_back({d_sum, t_sum, n_cur});
			}
		}
	}

	long gulp_i = 0;
	long high = m;
	long low = 0;
	while (true)
	{
		long cur_s = potions[gulp_i];
		sort(
			second_half.begin(),
			second_half.end(),
			[&cur_s] (const Subsum& left, const Subsum& right) {
				return left.d + left.n * cur_s < right.d + right.n * cur_s;
			}
		);

		vector<Subsum> proper;
		proper.reserve(max_mask);
		long cur_min_t = second_half.rbegin()->t + 1;
		for (auto it = second_half.rbegin(); it != second_half.rend(); it++)
		{
			if (cur_min_t > it->t) { // guarantees, that higher effective d <=> higher t
				proper.push_back(*it);
				cur_min_t = it->t;
			}
		}
		reverse(proper.begin(), proper.end());

		bool success = false;
		for (auto &&subsum : first_half)
		{
			auto it = upper_bound(
				proper.begin(),
				proper.end(),
				subsum,
				[&] (const Subsum& el, const Subsum& val) {
					return el.d + el.n * cur_s + val.d + val.n *cur_s >= D;
				}
			);
			if (it != proper.end() && subsum.t + it->t < T) {
				success = true;
				break;
			}
		}
		
		if (success) {
			if (gulp_i == low) {
				cout << gulp_i << endl;
				return;
			}
			high = gulp_i;
		} else {
			if (gulp_i == high) {
				if (gulp_i == m) {
					cout << "Panoramix captured";
				} else {
					cout << gulp_i;
				}
				cout << endl;
				return;
			}
			low = gulp_i + 1;
		}
		gulp_i = low + (high - low) / 2;
	}
	
	
	return;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
		split_and_list();
}
