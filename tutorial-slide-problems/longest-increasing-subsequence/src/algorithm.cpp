#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
// include "prettyprint.hpp";

void testcase() {
	int n;
	cin >> n;

	// descending map
	map<int, int, greater<int>> sequence;

	int maximum = 1;
	for (size_t ni = 0; ni < n; ni++)
	{
		int key;
		cin >> key;
		auto it = sequence.lower_bound(key);
		if (it != sequence.end()) { // key is not smallest
			int value = 1;
			if (it->first == key) { // value already exists
				if (++it != sequence.end()) {
					value += it->second;
					it--;
				}
				it->second = value;
			} else {
				value += it->second;
				sequence.insert(it, {key, value});
			}
			maximum = max(maximum, value);
		} else { // key is new smallest
			sequence.insert(it, {key, 1});
		}		
	}
	cout << maximum << endl;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		testcase();
}
