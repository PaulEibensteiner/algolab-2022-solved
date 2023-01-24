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

  vector<Biker> bikers;
  vector<bool> dead(n, false);

  for (int ni = 0; ni < n; ++ni) {
    long a, b, y;
    cin >> y;
    cin >> b;
    cin >> a;
    a -= y;
    bikers.push_back(Biker(y, a, b, ni));
  }
  
  sort(
    bikers.begin(),
    bikers.end(),
    [](const Biker& p1, const Biker& p2) -> bool { return p1.y < p2.y; }
  );

  boost::rational<long> closest_angle_to_zero = boost::rational<long>(LONG_MAX, 1);

  // Go through bikers from small y starting position to big y starting position
  // If current biker is angled downwards and there is a biker before, whos angle is closer to 0
  // then delete the current biker
  for (auto current_biker = bikers.begin();current_biker != bikers.end(); current_biker++) {
    if (current_biker->slope < 0 && boost::abs(current_biker->slope) > boost::abs(closest_angle_to_zero)) { 
      dead[current_biker->i] = true;
    } else if (current_biker->slope < 0 && current_biker->slope == -closest_angle_to_zero) {
      dead[current_biker->i] = true;
    } else if (boost::abs(current_biker->slope) < boost::abs(closest_angle_to_zero)) {
      closest_angle_to_zero = current_biker->slope;
    } else if (boost::abs(current_biker->slope) == boost::abs(closest_angle_to_zero)) {
      closest_angle_to_zero = max(current_biker->slope, closest_angle_to_zero);
    }
  }
  
  closest_angle_to_zero = boost::rational<long>(LONG_MAX, 1);
  for (auto current_biker = bikers.rbegin();current_biker != bikers.rend(); current_biker++) {
    if (current_biker->slope > 0 && boost::abs(current_biker->slope) > boost::abs(closest_angle_to_zero)) {
      dead[current_biker->i] = true;
    } else if (boost::abs(current_biker->slope) < boost::abs(closest_angle_to_zero)) {
      closest_angle_to_zero = current_biker->slope;
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (!dead[i]) {
      cout << i << " ";
    }
  }
  
  cout << endl;

  return;
}

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i)
    testcase();
}
