///4
#include <boost/rational.hpp>
#include <list>
#include<iostream>
#include <vector>

using namespace std;

struct Biker {
  boost::rational<long> slope;
  long y;
  int i;

  Biker(long y_, long a_, long b_, int x_) : slope(a_, b_), y(y_), i(x_) { }
};

void testcase() {
  int n;
  cin >> n;

  list<Biker> bikers;

  vector<int> array = { 1, 4, 9, 11, 17, 25, 33, 37, 56, 58, 65, 77, 128 };

  for (int ni = 0; ni < n; ++ni) {

    long a, b, y;
    cin >> y;
    cin >> b;
    cin >> a;
    a -= y;
    bikers.push_back(Biker(y, a, b, ni));
  }

  bikers.sort([](const Biker& p1, const Biker& p2) -> bool { return p1.y < p2.y; });

  for (auto b : bikers) {
    cout << b.i << ": " << b.y << ", " << boost::rational_cast<double>(b.slope)  << endl;
  }
  cout << endl;

  // up -> if alpha < 0 && alpha < alpha_min => delete biker
  // if |alpha| < alpha_min => alpha_min = |alpha|
  
  auto i = bikers.begin();
  boost::rational<long> alpha_min = i->slope;
  while (i != bikers.end()) {
    if (i->slope < 0 && boost::abs(i->slope) > boost::abs(alpha_min)) {
      bikers.erase(i++);
    } else if (i->slope < 0 && i->slope == alpha_min * -1) {
      // cout << i->slope << " == " << alpha_min << ", ";
      bikers.erase(i++);
    } else if (boost::abs(i->slope) < boost::abs(alpha_min)) {
      alpha_min = i->slope;
      i++;
    } else {
      i++;
    }
  }

  // down
  bikers.reverse();
  
  auto y = bikers.begin();
  alpha_min = boost::abs(y->slope);
  while (y != bikers.end()) {
    if (y->slope > 0 && y->slope > alpha_min) {
      bikers.erase(y++);
    } else if (boost::abs(y->slope) < alpha_min) {
      alpha_min = boost::abs(y->slope);
      y++;
    } else {
      y++;
    }
  }
  
  /*
  */

  bikers.sort([](const Biker& p1, const Biker& p2) -> bool { return p1.i < p2.i; });

  for (auto b : bikers) {
    cout << b.i << " "; // << ":" << b.y << ":" << b.slope << " ";
      
  }
  cout << endl;
  // 1 11 25 128

  return;
}

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i)
    testcase();
}
