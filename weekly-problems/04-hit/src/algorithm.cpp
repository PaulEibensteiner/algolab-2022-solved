#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/intersections.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel epick;


void testcase(int n) {
	long int x, y, a, b;
	cin >> x >> y >> a >> b;

  epick::Point_2 p(x,y), q(a,b);
	epick::Ray_2 ray(p, q);

	bool intersecting = false;
	int ni = 0;
	for (ni = 0; ni < n; ni++)
	{
		long int r, s, t, u;
		cin >> r >> s >> t >> u;

		epick::Point_2 p(r,s), q(t, u);
		epick::Segment_2 segment(p, q);

		if (CGAL::do_intersect(ray, segment)) {
			intersecting = true;
			break;
		}
	}
	// read rest of input
	for (ni++; ni < n; ni++) {
		long int r, s, t, u;
		cin >> r >> s >> t >> u;
	}
	
	cout << (intersecting ? "yes" : "no") << endl;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	while (n != 0) {
		testcase(n);
		cin >> n;
	}
}
