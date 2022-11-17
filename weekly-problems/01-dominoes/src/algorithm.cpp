///1
#include <iostream>
using namespace std;

int main() {
  int tn;
  cin >> tn;
  
  for (int t = 0; t < tn; t++) {
    int n;
    cin >> n;
    
    int cur;
    int max = 0;
    int count = 0;
    do {
      cin >> cur;
      if (max < cur) {
        max = cur;
      }
      max--;
      count++;
    } while (max > 0 && count < n);
    cout << count << endl;
    // consume rest
    for (int j = 0; j < n - count; j++) {
      cin >> cur;
    }
  }
  
}