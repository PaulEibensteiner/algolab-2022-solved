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
  int waterway, num_verts;
  int alt_waterway, alt_num_verts;

  Arm(int w, int n)
      : waterway(w), num_verts(n), alt_waterway(-1), alt_num_verts(-1) {}
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

  // Joint beginning of sums
  auto arms = map<int, Arm>();

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
        auto it = arms.find(sum);
        if (it == arms.end()) {
          arms.insert(make_pair(sum, Arm(wi, end - start)));
        } else {
          // save if bigger than one of already saved
          if (it->second.num_verts < it->second.alt_num_verts) {
            if (it->second.num_verts < end - start) {
              it->second.num_verts = end - start;
              it->second.alt_waterway = wi;
            }
          } else {
            if (it->second.alt_num_verts < end - start) {
              it->second.alt_num_verts = end - start;
              it->second.alt_waterway = wi;
            }
          }
        }
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

  // check for every combination of ways
  auto forward = arms.begin();
  // int target = num_men - start->first - weights[0];
  // auto end = arms.lower_bound(target);
  // assume ascending
  auto backward = arms.rbegin();
  while (forward != arms.end() && backward != arms.rend() &&
         forward->first <= backward->first) {
    int cur_sum = forward->first + backward->first - weights[0];
    if (cur_sum < num_men) {
      forward++;
    } else if (cur_sum > num_men) {
      backward++;
    } else {
      if (forward->second.waterway != backward->second.waterway) {
        max_num = std::max(max_num, forward->second.num_verts +
                                        backward->second.num_verts - 1);
      }
      if (forward->second.alt_waterway != -1 &&
          forward->second.alt_waterway != backward->second.waterway) {
        max_num = std::max(max_num, forward->second.alt_num_verts +
                                        backward->second.num_verts - 1);
      }
      if (backward->second.alt_waterway != -1 &&
          backward->second.alt_waterway != forward->second.waterway) {
        max_num = std::max(max_num, backward->second.alt_num_verts +
                                        forward->second.num_verts - 1);
      }
      if (backward->second.alt_waterway != -1 &&
          forward->second.alt_waterway != -1 &&
          backward->second.alt_waterway != forward->second.alt_waterway) {
        max_num = std::max(max_num, forward->second.alt_num_verts +
                                        backward->second.alt_num_verts - 1);
      }
      forward++;
      backward++;
    }
  }

  cout << max_num << endl;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
