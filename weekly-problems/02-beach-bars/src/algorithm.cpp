/// 1
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void addIndex(int start, int end, vector<int>& indices) {
  int sum = start + end;
  // floor
  int index1 = sum / 2 - (sum % 2 != 0 && (sum < 0));
  indices.push_back(index1);
  if (sum % 2 != 0) {
    // ceil
    int index2 = index1 + 1;
    indices.push_back(index2);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  int t;
  cin >> t;

  for (int ti = 0; ti < t; ti++) {
    int n;
    cin >> n;

    vector<int> input;
		input.reserve(n);
    int c;
    for (int ni = 0; ni < n; ni++) {
      cin >> c;
      input.push_back(c);
    }
		sort(input.begin(), input.end());

    auto start = input.begin();
    auto end = input.begin();
    int cur_n_elements = 1;

    int max_n_elements = 1;
    int min_longest_distance = 0;  // fuck division, its end - start
    vector<int> indices;

    while (true) {
      if ((*end - *start) > 200) {  // start must have been set
        cur_n_elements--;
        start++;
        continue;
      }

      if (cur_n_elements > max_n_elements) {
        max_n_elements = cur_n_elements;
        indices.clear();
        addIndex(*start, *end, indices);
        int sum = *end - *start;
        min_longest_distance = sum / 2 + (sum % 2 != 0);
      } else if (cur_n_elements == max_n_elements) {
        int sum = *end - *start;
        int distance = sum / 2 + (sum % 2 != 0);
        if (distance < min_longest_distance) {
          indices.clear();
          addIndex(*start, *end, indices);
          min_longest_distance = distance;
        } else if (distance == min_longest_distance) {
          addIndex(*start, *end, indices);
        }
      }

      cur_n_elements++;
      end++;
      if (end == input.end()) {
        break;
      }
    }
		
    cout << max_n_elements << " " << min_longest_distance << endl;
    for (int index : indices) {
      cout << index << ' ';
    }
    cout << endl;
  }
}