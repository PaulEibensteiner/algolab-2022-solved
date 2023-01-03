#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Arm {
  int sum, waterway, num_verts;

  Arm(int s, int w, int n) : sum(s), waterway(w), num_verts(n) {}
};

void testcase() {
  int num_islands, num_men, num_ways;
  cin >> num_islands;
  cin >> num_men;
  cin >> num_ways;

  auto weights = vector<int>(num_islands);
  for (int ni = 0; ni < num_islands; ni++) {
    cin >> weights[ni];
  }

  auto ways = vector<vector<int>>(num_ways);
  for (int wi = 0; wi < num_ways; wi++) {
    int l;
    cin >> l;
    ways[wi] = vector<int>(l);
    for (int li = 0; li < l; li++) {
      cin >> ways[wi][li];
      if (!(ways[wi][li] < num_islands)) {
        cout << "tf" << endl;
      }
    }
  }

  // save the beginning sums
  auto sums = vector<Arm>();
  sums.reserve(num_ways);

  int max_num = 0;
  int wi = 0;
  // sliding window for every arm
  for (const vector<int>& way : ways) {
    int start = 0;
    int end = 1;
    int sum = weights[way[0]];

    while (true) {
      // If we're at the beginning then this part could be combined with another
      // one
      if (start == 0 && end > 1 && sum < num_men) {
        sums.push_back(Arm(sum, wi, end - start));
      }

      if (sum < num_men) {
        if (end >= way.size()) {
          break;
        }
        sum += weights[way[end]];
        end++;
      } else if (sum > num_men) {
        sum -= weights[way[start]];
        start++;
      } else if (sum == num_men) {
        if ((int)(end - start) > max_num) {
          max_num = end - start;
        }
        if (end >= way.size()) {
          break;
        }
        sum -= weights[way[start]];
        start++;
        sum += weights[way[end]];
        end++;
      }
    }
    wi++;
  }

  std::sort(sums.begin(), sums.end(), [](const Arm& arm1, const Arm& arm2) {
    if (arm1.sum < arm2.sum) {
      return true;
    }
    if (arm1.sum == arm2.sum) {
      return arm1.num_verts > arm2.num_verts;
    }
    return false;
  });

  for (Arm& arm1 : sums) {
    int pyke_weight = weights[0];
    int missing_sum = pyke_weight + num_men - arm1.sum;

    auto it = std::lower_bound(
        sums.begin(), sums.end(), arm1,
        [missing_sum, num_men](const Arm& arm2, const Arm& arm1) {
          if (arm2.sum < missing_sum) {
            return true;
          }
          if (arm2.sum == missing_sum) {
            return arm1.waterway == arm2.waterway;
          }
          return false;
        });
    if (it != sums.end() && it->sum == missing_sum) {
      max_num = max(max_num, it->num_verts + arm1.num_verts - 1);
    }
  }

  std::cout << max_num << endl;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
