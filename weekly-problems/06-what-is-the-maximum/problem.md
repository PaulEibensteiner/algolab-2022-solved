---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Maximize it!

Your company often needs to solve simple optimization problems of two types.

$$
\begin{aligned}
\max &\ b \cdot y-a \cdot x \\
\text { s.t. } & x, y \geqslant 0 \\
& x+y \leqslant 4 \\
& 4 x+2 y \leqslant a b \\
& -x+y \leqslant 1
\end{aligned}
$$

$$
\begin{align}
\min &\ a \cdot x+b \cdot y+z \\
\text { s.t. } & x, y, z \leqslant 0 \\
& x+y \geqslant-4 \\
& 4 x+2 y+z \geqslant-a b \\
& -x+y \geqslant-1
\end{align}
$$

For any values of parameters $a$ and $b$, find the optimal value.

**Input** The input consists of several test sets. Each test set appears on a separate line, consisting of three integers $p$ a b, where $p$ is the type of the problem to solve $(p \in\{1,2\})$ and $a, b$ are the values of the parameters $(0 \leqslant a \leqslant 100,-100 \leqslant b \leqslant 100)$. The input is terminated by a line containing only 0 .

**Output** For each test set, write on a separate line the optimal value of the problem of type $p$ with parameters $a, b$, rounded down to the next integer for the maximization problem, and rounded up to the next integer for the minimization problem. If there is no solution, write no, and if there are solutions of arbitrarily high value (arbitrarily low for minimization), then output unbounded.

Sample Input

$$
\begin{array}{lll}1 & 1 & 1 \\ 1 & 3 & -3 \\ 2 & 1 & 1 \\ 2 & 2 & 1 \\ 0 & & \end{array}
$$
Sample Output
$$
0 \\
\text{no} \\
-1 \\
-2
$$


