#include <iostream>
using namespace std;

// Idea: Number of pairs in sequence is small Gauss of n-1

int main() {
  int t;
  cin >> t;
  
  for (int ti = 0; ti < t; ti++) {
    int n;
    cin >> n;
    
    int ev = 0;
    int nev = 0;
    
    int cur;
    int sum = 0;
    for (int ni = 0; ni < n; ni++) {
      cin >> cur;
      sum += cur;
      if (sum%2 == 0) {
        ev++;
      } else {
        nev++;
      }
    }
    
    // I could just use the choose formua here to
    int pairs = 0;
    pairs += ev;
    ev--;
    nev--;
    pairs += (ev*ev +ev) / 2;
    pairs += (nev*nev + nev) / 2;
    
    cout << pairs << endl;
    
  }
}