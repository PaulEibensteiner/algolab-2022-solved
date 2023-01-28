#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> adjacency;
vector<int> cost;
vector<vector<int>> memo;

void testcase() {
  int n;
  cin >> n;

  auto parent = vector<int>(n);
  vector<int> children_left(n, 0);
  auto children = vector<vector<int>>(n);
  for (int ni = 0; ni < n - 1; ni++) {
    int i, j;
    cin >> i >> j;
    parent[j] = i;
    children[i].push_back(j);
    children_left[i]++;
  }

  list<int> endpoints;
  for (int ni = 0; ni < n; ni++) {
    if (children_left[ni] == 0) {
      endpoints.push_back(ni);
    }
  }

  cost = vector<int>(n);
  for (int ni = 0; ni < n; ni++) {
    cin >> cost[ni];
  }

  vector<int> min_v_safe(n, 0);
  vector<int> min_v_unsafe(n, 0);
  vector<int> with_v(n, 0);

  while (!endpoints.empty()) {
    int v = endpoints.front();
    endpoints.pop_front();

    // with v
    with_v[v] = cost[v];
    for (auto &&child : children[v]) {
      with_v[v] += min_v_safe[child];
    }

    // v unsafe
    // without v
    int min_dif = INT32_MAX;
    for (auto &&child : children[v]) {
      min_v_unsafe[v] += min_v_unsafe[child];
      min_dif = min(min_dif, with_v[child] - min_v_unsafe[child]);
    }
    min_v_unsafe[v] += min_dif;
    // with v
    min_v_unsafe[v] = min(min_v_unsafe[v], with_v[v]);

    // v safe
    // without v
    for (auto &&child : children[v]) {
      min_v_safe[v] += min_v_unsafe[child];
    }
    // with v
    min_v_safe[v] = min(min_v_safe[v], with_v[v]);

    if (--children_left[parent[v]] == 0) {
      endpoints.push_back(parent[v]);
    }
  }

  cout << min_v_unsafe[0] << endl;

  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
