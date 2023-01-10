#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
// include "prettyprint.hpp";
#include <CGAL/Exact_predicates_exact_constructions_kernel_with_sqrt.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Exact_predicates_exact_constructions_kernel_with_sqrt KE;
typedef CGAL::Delaunay_triangulation_2<K>  Triangulation;
typedef Triangulation::Edge_iterator  Edge_iterator;

int ceil_to_int(const KE::FT& x) {
	double a = std::ceil(CGAL::to_double(x));
	while (a < x) a += 1;
	while (a-1 >= x) a -= 1;
	return (int)a;
}

int r_to_t(double r_x4_sqrd) {
	auto r_sqrd = KE::FT(r_x4_sqrd) / 4.0;
	// cout << r_sqrd << ", ";
	auto r = CGAL::sqrt<KE::FT>(r_sqrd);
	if (r <= 0.5) {
		return 0;
	}
	auto t = CGAL::sqrt<KE::FT>(r - KE::FT(0.5));
	// cout << t << endl;
	return ceil_to_int(t);
}

void testcase(int n) {
	int x_0, x_1, y_0, y_1;
	cin >> x_0 >> y_0 >> x_1 >> y_1;
	auto points = vector<K::Point_2>(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		points[i] = K::Point_2(x, y);
	}

	auto death_radius_sqrd_x4 = vector<double>();
	death_radius_sqrd_x4.reserve(n);

	Triangulation t(points.begin(), points.end());

	for (auto it = t.finite_vertices_begin(); it != t.finite_vertices_end(); it++) {
		double min_r_sqrd_x4 = numeric_limits<double>::max();
		int x = t.point(it).x();
		int y = t.point(it).y();
		
		min_r_sqrd_x4 = min(min_r_sqrd_x4, pow(x - x_0, 2)*4);
		min_r_sqrd_x4 = min(min_r_sqrd_x4, pow(y - y_0, 2)*4);
		min_r_sqrd_x4 = min(min_r_sqrd_x4, pow(x_1 - x, 2)*4);
		min_r_sqrd_x4 = min(min_r_sqrd_x4, pow(y_1 - y, 2)*4);

		if (n > 1) {
			Triangulation::Edge_circulator c = t.incident_edges(it);
			do {
				if (t.is_infinite(c)) {
					continue;
				}
				double r_squared_x4 = t.segment(c).squared_length();
				min_r_sqrd_x4 = min(min_r_sqrd_x4, r_squared_x4);
			} while (++c != t.incident_edges(it));
		}

		if (min_r_sqrd_x4 < 0) {
			cout << "error" << endl;
			return;
		}
		
		death_radius_sqrd_x4.push_back(min_r_sqrd_x4);
	}

	std::sort(death_radius_sqrd_x4.begin(), death_radius_sqrd_x4.end());

	double r_0 = death_radius_sqrd_x4[0];
	double r_m = death_radius_sqrd_x4[std::floor((double)n / 2.0)];
	double r_l = death_radius_sqrd_x4[n-1];

	cout << r_to_t(r_0) << " " << r_to_t(r_m) << " " << r_to_t(r_l) << endl;
	return;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int n;
	
	for (std::cin >> n; n != 0; std::cin >> n)
		testcase(n);
}
