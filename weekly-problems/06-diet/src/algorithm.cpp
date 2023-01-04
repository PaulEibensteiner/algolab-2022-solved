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

int round_down(const CGAL::Quotient<ET> x) {
	double a = std::floor(CGAL::to_double(x));
	while (a > x) a -= 1;
	while (a+1 <= x) a += 1;
	return (int)a;
}

void testcase(int n, int m) {
	vector<int> mins(n);
	vector<int> maxs(n);

	for (int i = 0; i < n; i++)
	{
		cin >> mins[i];
		cin >> maxs[i];
	}

	auto cs = vector<vector<int>>(n, vector<int>(m));
	vector<int> ps(m);

	for (int mi = 0; mi < m; mi++)
	{
		cin >> ps[mi];
		for (int ni = 0; ni < n; ni++)
		{
			cin >> cs[ni][mi];
		}
	}

	Program lp(CGAL::SMALLER, true, 0, false, 0);

	// min p^T x
	for (int j = 0; j < m; j++)
	{
		lp.set_c(j, ps[j]);
	}

	// s.t. C x < max && C x > min

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			lp.set_a(j, i, cs[i][j]);
		}
		lp.set_b(i, maxs[i]);
		
		for (int j = 0; j < m; j++)
		{
			lp.set_a(j, i+n, -cs[i][j]);
		}
		lp.set_b(i+n, -mins[i]);
	}
	
	auto s = CGAL::solve_linear_program(lp, ET());

	if (s.is_infeasible()) {
		cout << "No such diet." << endl;
	} else {
		cout << round_down(s.objective_value()) << endl;
	}
	
	return;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int n, m;
	std::cin >> n >> m;
	while (n != 0 || m != 0) {
		testcase(n, m);
		std::cin >> n >> m;
	}
}
