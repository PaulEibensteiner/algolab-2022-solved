---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - First steps with BGL

Read a weighted undirected graph, compute the total weight of its minimum spanning tree and the distance from node 0 to a node furthest from it.

**Input** The first line of the input file contains $t \leqslant 100$, the number of test cases. Each test case starts with a line containing $n \leqslant 100, m \leqslant \frac{n \cdot(n-1)}{2}$, the number of vertices and edges of the graph. $m$ lines follow, each defining the two endpoints and weight of an edge. All weights are non-negative integers and at most 1000. The input graph is guaranteed to be connected.

**Output** For each test case output a single line containing $w$, the sum of weights of all edges of a minimum spanning tree, and $d$, the distance from node 0 to a node furthest from it.

Sample Input

$$
\begin{array}{lll}
1 & & \\
5 & 6 & \\
0 & 1 & 1 \\
0 & 2 & 2 \\
1 & 2 & 5 \\
1 & 3 & 1 \\
3 & 2 & 2 \\
2 & 4 & 3
\end{array}
$$

Sample Output
$$
7\ 5
$$
