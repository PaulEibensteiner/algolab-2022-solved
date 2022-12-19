#include <algorithm>
#include <boost/heap/fibonacci_heap.hpp>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <queue>
#include <string>
#include <vector>

// Does not work:
// 11110
// 11111
// 11111
// 11110

using namespace std;
// include "prettyprint.hpp";

struct Option {
  int x, y;
  int num_preventing;

  struct OptionCompare {
    bool operator()(const Option& o1, const Option& o2) const {
      return o1.num_preventing > o2.num_preventing;
    }
  };

  Option(int x, int y) : x(x), y(y), num_preventing(0) {}
};

typedef boost::heap::fibonacci_heap<Option,
                                    boost::heap::compare<Option::OptionCompare>>
    PriorityQueue;
typedef PriorityQueue::handle_type handle_type;

void testcase() {
  int h, w;
  cin >> h >> w;

  auto floor_plan = vector<vector<int>>(h + 2, vector<int>(w + 2, 0));

  for (int y = 1; y < h + 1; y++) {
    for (int x = 1; x < w + 1; x++) {
      cin >> floor_plan[y][x];
    }
  }

  auto options_plan = vector<vector<handle_type>>(
      h + 2, vector<handle_type>(w + 2, handle_type()));

  // auto queue = priority_queue<Option*, std::vector<Option*>, OptionLess>();
  auto queue = PriorityQueue();

  for (int y = 2; y < h + 1; y++) {
    for (int x = 2; x < w + 1; x++) {
      if (floor_plan[y][x] && floor_plan[y + 1][x] && floor_plan[y][x + 1] &&
          floor_plan[y + 1][x + 1]) {
        options_plan[y][x] = queue.push(Option(x, y));
      }
    }
  }

  for (int y = 2; y < h + 1; y++) {
    for (int x = 2; x < w + 1; x++) {
      if (options_plan[y][x].node_ != NULL) {
        auto current = options_plan[y][x];
        for (int y_ = -1; y_ <= 1; y_++) {
          for (int x_ = -1; x_ <= 1; x_++) {
            if (!(x_ == 0 && y_ == 0) &&
                options_plan[y + y_][x + x_].node_ != NULL) {
              (*current).num_preventing++;
            }
          }
        }
        queue.decrease(current);  // decrease priority because value is higher
      }
    }
  }

  int count = 0;
  while (!queue.empty()) {
    /* for (auto it = queue.ordered_begin(); it != queue.ordered_end(); it++)
    {
            cout << it->x << "/" << it->y << ": " << it->num_preventing << endl;
    }
    cout << endl; */

    auto min_el = queue.top();

    // delete all squares the are not available any more
    // and update the squares that would have prevented them
    for (int x1 = -1; x1 <= 1; x1++) {
      for (int y1 = -1; y1 <= 1; y1++) {
				int x = min_el.x + x1;
				int y = min_el.y + y1;
        if (options_plan[y][x].node_ != NULL) {
          // update all neighboring
          for (int x2 = -1; x2 <= 1; x2++) {
            for (int y2 = -1; y2 <= 1; y2++) {
							int x = min_el.x + x1 + x2;
							int y = min_el.y + y1 + y2;
              if ((abs(x1 + x2) == 2 || abs(y1 + y2) == 2) &&
                  options_plan[y][x].node_ != NULL) {
                (*options_plan[y][x]).num_preventing--;
                queue.increase(options_plan[y][x]);  // TODO replace with increase
              }
            }
          }
          // Erase and invalidate
          queue.erase(options_plan[y][x]);
          options_plan[y][x].node_ = NULL;
        }
      }
    }
    count++;
  }

  cout << count << endl;
  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
