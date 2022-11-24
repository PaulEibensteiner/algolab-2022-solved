#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpq.h>
#include <CGAL/Quotient.h>

using namespace std;

typedef CGAL::Gmpq ET;
typedef CGAL::Gmpq Rational;

// program and solution types
typedef CGAL::Quadratic_program<Rational> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;

struct Point {
	Rational x, y;

	Point(Rational x, Rational y) : x(x), y(y) {}
};

void testcase() {
	int n, m, h, w;

	cin >> n;
	cin >> m;
	cin >> h;
	cin >> w;

	auto ns = vector<Point>();
	auto ms = vector<Point>();
	ns.reserve(n);
	ms.reserve(m);

	for (int i = 0; i < n; i++)
	{
		int x_orig,y_orig;
		cin >> x_orig;
		cin >> y_orig;

		Rational x, y;
		x = Rational(2*x_orig, w);
		y = Rational(2*y_orig, h);
		ns.push_back(Point(x, y));
	}

	for (int i = 0; i < m; i++)
	{
		int x_orig,y_orig;
		cin >> x_orig;
		cin >> y_orig;

		Rational x, y;
		x = Rational(2*x_orig, w);
		y = Rational(2*y_orig, h);
		ms.push_back(Point(x, y));
	}

	Program lp(CGAL::SMALLER, true, 1, false, 0);

	// My variables a_i go from 0 to n, with the corresponding center Point

	int i = 0;
	for (int ai = 0; ai < n; ai++) {
		auto Point1 = ns[ai];
		for (int aj = ai; aj < n; aj++)
		{
			if (ai == aj) {
				continue;
			}
			auto Point2 = ns[aj];

			Rational zi, zj;

			if (CGAL::abs(Point1.x - Point2.x) > CGAL::abs(Point1.y - Point2.y)) {
				zi = Point1.x;
				zj = Point2.x;
			} else {
				zi = Point1.y;
				zj = Point2.y;
			}
			lp.set_a(ai, i, 1);
			lp.set_a(aj, i, 1);
			if (zi < zj) {
				lp.set_b(i, zj - zi);
				//cout << "a" << ai << " + " << "a" << aj << " <= " << zj-zi << endl;
			} else {
				lp.set_b(i, zi - zj);
				//cout << "a" << ai << " + " << "a" << aj << " <= " << zi-zj << endl;
			}
			i++;
		}

		for (int mi = 0; mi < m; mi++) {
			auto Point2 = ms[mi];

			Rational zi, zj;

			if (CGAL::abs(Point1.x - Point2.x) > CGAL::abs(Point1.y - Point2.y)) {
				zi = Point1.x;
				zj = Point2.x;
			} else {
				zi = Point1.y;
				zj = Point2.y;
			}

			if (zi < zj) {
				lp.set_u(ai, true, zj-zi-1);
				//cout << "a" << ai << " <= " << zj-zi-1 << endl;
			} else {
				lp.set_u(ai, true, zi-zj-1);
				//cout << "a" << ai << " <= " << zi-zj-1 << endl;
			}
		}

	}

	// set objective, max sum_i(a_i)

	for (int ai = 0; ai < n; ai++)
	{
		lp.set_c(ai, -1);
	}

	auto s = CGAL::solve_linear_program(lp, ET()).objective_value();

	// auto s = solution.objective_value().numerator() / solution.objective_value().denominator();

	int rounded = round((s.numerator().numerator().to_double() * s.denominator().denominator().to_double()) / (s.numerator().denominator().to_double() * s.denominator().numerator().to_double()));

	std::cout << s << "->" << rounded << endl;
	std::cout << 2 * (w+h) * -rounded << endl;

	return;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
		testcase();
}
