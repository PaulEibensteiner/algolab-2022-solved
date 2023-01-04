#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
// include "prettyprint.hpp";

struct Movement {
	int d,t;
	Movement(int d, int t) : d(d), t(t) { }
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

void testcase() {
	
	return;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
		brute_force();
}
