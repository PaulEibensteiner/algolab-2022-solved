#include <iostream>
using namespace std;

int O_of_four() {
  int t;
  cin >> t;
  
  for (int ti = 0; ti < t; ti++) {
    int n;
    cin >> n;
    int ns[n+1][n+1] = {};
    
    // read all in, 1-indexed
    for (int i = 0; i < n+1; i++) {
      for (int j = 0; j < n+1; j++) {
        if (j == 0 || i == 0) {
          ns[i][j] = 0;
          continue;
        }
        cin >> ns[i][j];
      }
    }
    
    
    // create all sums
    int sums[n+1][n+1] = {};
    for (int i = 0; i < n+1; i++) {
      for (int j = 0; j < n+1; j++) {
        if (j == 0 || i == 0) {
          sums[i][j] = 0;
          continue;
        }
        sums[i][j] = sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] + ns[i][j];
      }
    }

    int evens = 0;
    
    for (int i = 1; i < n+1; i++) {
      for (int j = 1; j < n+1; j++) {
        for (int k = 0; k < i; k++) {
          for (int l = 0; l < j; l++) {
            int sum = sums[i][j] - sums[i][l] - sums[k][j] + sums[k][l];
            if (sum%2 == 0) {
              evens++;
            }
          }
        }
      }
    }
    
    
    
    cout << evens << endl;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i)
    testcase();

  return 0;
}
