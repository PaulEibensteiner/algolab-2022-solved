#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

struct Boat {
  int l, p;
  Boat(int l, int p) : l(l), p(p) {}
};

void testcase() {
  int n;
  cin >> n;

  auto boats = vector<Boat>();
  boats.reserve(n);

  for (int ni = 0; ni < n; ni++) {
    int l, p;
    cin >> l >> p;
    boats.push_back(Boat(l, p));
  }

  std::sort(boats.begin(), boats.end(),
            [](const Boat& b1, const Boat& b2) { return b1.p < b2.p; });

  int i = 1;
  int num_boats = 1;
  int current_end = boats[0].p;
  while (i < n) {
    int next_best = std::max(current_end + boats[i].l, boats[i].p);
    i++;
    while (i < n && boats[i].p < next_best) {
      int next_end = std::max(current_end + boats[i].l, boats[i].p);
      next_best = std::min(next_best, next_end);
      i++;
    }
    current_end = next_best;
    num_boats++;
  }

  cout << num_boats << endl;

  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
