#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

// example: how to solve a simple explicit LP
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpz.h>

// choose input type (input coefficients must fit)
typedef int IT;
// choose exact type for solver (CGAL::Gmpz or CGAL::Gmpq)
typedef CGAL::Gmpq ET;

// program and solution types
typedef CGAL::Quadratic_program<IT> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;

int round_up(const CGAL::Quotient<ET> x) {
	double a = std::floor(CGAL::to_double(x));
	while (a > x) a -= 1;
	while (a+1 <= x) a += 1;
	return (int)a;
}

int round_down(const CGAL::Quotient<ET> x) {
	double a = std::floor(CGAL::to_double(x));
	while (a < x) a += 1;
	while (a-1 >= x) a -= 1;
	return (int)a;
}

void testcase(int p)
{
	int a, b;
	cin >> a >> b;
	Solution s;

	if (p == 1) {
		Program lp(CGAL::SMALLER, true, 0, false, 0);

		const int x = 0;
		const int y = 1;

		lp.set_a(x, 0, 1);
		lp.set_a(y, 0, 1);
		lp.set_b(0, 4);

		lp.set_a(x, 1, 4);
		lp.set_a(y, 1, 2);
		lp.set_b(1, a*b);

		lp.set_a(x, 2, -1);
		lp.set_a(y, 2, 1);
		lp.set_b(2,1);

		lp.set_c(y, -b);
		lp.set_c(x, a);

		s = CGAL::solve_linear_program(lp, ET());
	} else if (p == 2) {
		Program lp(CGAL::LARGER, false, 0, true, 0);

		const int x = 0;
		const int y = 1;
		const int z = 2;

		lp.set_a(x, 0, 1);
		lp.set_a(y, 0, 1);
		lp.set_b(0, -4);

		lp.set_a(x, 1, 4);
		lp.set_a(y, 1, 2);
		lp.set_a(z, 1, 1);
		lp.set_b(1, -a*b);

		lp.set_a(x, 2, -1);
		lp.set_a(y, 2, 1);
		lp.set_b(2, -1);

		lp.set_c(x, a);
		lp.set_c(y, b);
		lp.set_c(z, 1);

		s = CGAL::solve_linear_program(lp, ET());
	} else {
		cout << "wrong p" << endl;
		return;
	}
  
  // output solution
	if (s.is_unbounded()) {
		cout << "unbounded";
	} else if (s.is_infeasible()) {
		cout << "no";
	} else {
		if (p == 1) {
			cout << -round_down(s.objective_value());
		} else {
			cout << round_down(s.objective_value());
		}
	}
	cout << endl;
}


int main() {
	std::ios_base::sync_with_stdio(false);

	int p;
	std::cin >> p;
	while ( p != 0) {
		testcase(p);
		cin >> p;
	}
}
