#include <assert.h>

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Query {
  int order, age;
};

struct Solution {
  int order, id;
};

struct Species {
  int id, age;
  string name;
};
vector<Species> species;
vector<vector<int>> adjacency;
vector<vector<Query>> queries;
vector<int> ancestors;
vector<Solution> solutions;

void dfs(int v) {
  ancestors.push_back(v);

  for (auto&& child : adjacency[v]) {
    dfs(child);
  }

  for (auto&& query : queries[v]) {
    auto sol_it =
        lower_bound(ancestors.begin(), ancestors.end(), query.age,
                    [&](int el, int val) { return species[el].age > val; });
    if (sol_it == ancestors.end()) {
      cout << "wtf" << endl;
    }
    solutions.push_back({query.order, *sol_it});
  }

  ancestors.pop_back();
}

void testcase() {
  int n, q;
  cin >> n >> q;

  map<string, int> name_to_id;
  species = vector<Species>(n);
  set<int> parents;
  for (int id = 0; id < n; id++) {
    string s;
    cin >> s;
    name_to_id[s] = id;
    int age;
    cin >> age;
    parents.insert(id);
    species[id] = {id, age, s};
  }

  adjacency = vector<vector<int>>(n);
  for (int i = 0; i < n - 1; i++) {
    string s, p;
    cin >> s >> p;
    int child = name_to_id[s];
    adjacency[name_to_id[p]].push_back(child);
    parents.erase(child);
  }

  assert(parents.size() == 1);

  queries = vector<vector<Query>>(n);
  for (int i = 0; i < q; i++) {
    string s;
    int age;
    cin >> s;
    cin >> age;
    queries[name_to_id[s]].push_back({i, age});
  }

  ancestors = vector<int>();
  ancestors.reserve(n);
  solutions = vector<Solution>();

  dfs(*parents.begin());

  sort(solutions.begin(), solutions.end(),
       [](const Solution& left, const Solution& right) {
         return left.order < right.order;
       });

  auto it = solutions.begin();
  cout << species[it->id].name;
  while (++it != solutions.end()) {
    cout << " " << species[it->id].name;
  }
  cout << endl;

  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
