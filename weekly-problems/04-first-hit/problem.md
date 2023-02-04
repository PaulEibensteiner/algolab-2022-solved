---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - First hit

A laser source shot Phileas Photon into some direction. How far will he have to travel? Where will he end up? The scenery is considered as seen from above, such that obstacle walls appear as line segments and the trajectory of Phileas is described by a ray.

**Input** The input file consists of several test cases. Each of them starts with a line containing one integer $n\left(1 \leqslant n \leqslant 30^{\prime} 000\right)$. The following line describes the ray along which Phileas travels. It contains integers $x\ y\ a\ b$ where $(x, y)$ are the coordinates of the starting point of the ray and $(a, b) \neq(x, y)$ is another point on the ray. The following $n$ lines describe an obstacle line segment each. The $i$-th of these lines contains four integers $r\ s\ t\ u$, where $(r, s)$ and $(t, u)$ are the endpoints of the i-th segment. All the above coordinates are integers that are in absolute value smaller than $2^{51}$. All numbers on a line are separated by a single space. The input is terminated by a single line containing $\theta$ (i.e., an empty testcase).

**Output** The output for each testcase appears on a separate line. This line contains the coordinates of the first intersection of the ray with any obstacle segment ^1^, where both coordinates are rounded ^2^ down to the next integer. If there is no such intersection, the line consists of the word no.

^1^ The obstacles segments are relatively closed, that is, both endpoints are included into consideration.

^2^ That is, for a coordinate a output the unique integer $i$, for which $i \leqslant a<i+1$.