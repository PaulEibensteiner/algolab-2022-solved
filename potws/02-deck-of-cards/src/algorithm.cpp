#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int ti = 0; ti < t; ti++) {
    int n;
    cin >> n;
    int k;
    cin >> k;

    int input[n];
    for (int ni = 0; ni < n; ni++) {
      cin >> input[ni];
    }

    int cur = input[0];
    int start = 0;

    int best = input[0];
    int i = 0;
    int j = 0;

    // cout << n << ", " << k << endl;

    int end = 1;
    while (true) {
      if (abs(k - cur) < abs(k - best)) {
        i = start;
        j = end - 1;
        best = cur;
      }
      if (cur == k) {
        break;
      }
      if (cur > k && start < end - 1) {  // start must have been set
        cur -= input[start];
        start++;
      } else if (end < n) {
        cur += input[end];
        end++;
      } else {
        break;
      }
    }
    cout << i << " " << j << /*" -> " << best <<*/ endl;
  }
}