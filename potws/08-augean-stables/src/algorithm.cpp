/// 1

#include <CGAL/Gmpz.h>
#include <CGAL/QP_functions.h>
#include <CGAL/QP_models.h>

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

typedef int IT;
typedef CGAL::Gmpz ET;
typedef CGAL::Quadratic_program<IT> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;

void testcase() {
  int n;
  cin >> n;
  auto fs = vector<int>(n);
  auto cs = vector<int>(n);
  auto ks = vector<int>(n);
  auto ls = vector<int>(n);
  auto ms = vector<int>(n);

  for (int ni = 0; ni < n; ni++) {
    cin >> fs[ni];
    cin >> cs[ni];
    cin >> ks[ni];
    cin >> ls[ni];
    cin >> ms[ni];
  }

  auto as = vector<int>(25, 0);
  auto ps = vector<int>(25, 0);
  for (size_t i = 1; i < 25; i++) {
    int a_i;
    cin >> a_i;
    as[i] = as[i - 1] + a_i;
  }
  for (size_t i = 1; i < 25; i++) {
    int p_i;
    cin >> p_i;
    ps[i] = ps[i - 1] + p_i;
  }

  bool feasible = false;
  int max_per_trench = 24;
  int min_sum = max_per_trench * 2;
  int ai = max_per_trench;
  int pi = 0;
  while (ai >= 0 && pi <= max_per_trench) {
    int a = pow(as[ai], 2);
    int b = pow(ps[pi], 2);
    int c = as[ai] * ps[pi];

    Program lp(CGAL::LARGER, true, 0, true, 1);
    const int h_1 = 0;
    const int h_2 = 1;
    const int h_3 = 2;

    for (int j = 0; j < n; j++) {
      lp.set_a(h_1, j, ks[j] + a);
      lp.set_a(h_2, j, ls[j] + b);
      lp.set_a(h_3, j, ms[j] + c);

      lp.set_b(j, fs[j] - cs[j]);
    }

    Solution s = CGAL::solve_linear_program(lp, ET());

    if (s.is_infeasible()) {
      pi++;
    } else {
      feasible = true;
      min_sum = min(min_sum, ai + pi);
      ai--;
    }
  }

  if (feasible) {
    cout << min_sum << endl;
  } else {
    cout << "Impossible!" << endl;
  }

  return;
}

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
