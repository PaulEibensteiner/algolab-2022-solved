---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Even matrices

You are still part of a team to develop a pseudorandom number generator. Your generator has already passed some simple statistical tests, but now it is time to get serious. You arrange a list of bits produced by the generator in an $n$ by $n$ matrix. If

$$
M=\left(\begin{array}{cccc}
x_{1,1} & x_{1,2} & & x_{1, n} \\
x_{2,1} & x_{2,2} & \cdots & x_{2, n} \\
& \vdots & \ddots & \\
x_{n, 1} & x_{n, 2} & & x_{n, n}
\end{array}\right)
$$

was a truly random matrix of bits, then it would have the property that the sum

$$
\sum_{i^{\prime}=i_{1}}^{i_{2}} \sum_{j^{\prime}=j_{1}}^{j_{2}} x_{i^{\prime}, j^{\prime}}
$$

is even for about half of the quadruples $\left(i_{1}, i_{2}, j_{1}, j_{2}\right), 1 \leqslant i_{1} \leqslant i_{2} \leqslant n$ and $1 \leqslant j_{1} \leqslant j_{2} \leqslant n$.

To check whether this is the case for your generator, you need to be able to count the number of such quadruples.

**Input** The first line of the input contains the number $t \leqslant 15$ of test cases. Each of the t test cases is described as follows.

- It starts with a line that contains an integer $n$ such that $1 \leqslant n \leqslant 200$.

- This is followed by $n$ lines, where the $i$-th line contains the $n$ integers $x_{i, 1} \ldots x_{i, n}$, separated by a space, such that $x_{i, j} \in\{0,1\}$, for all $i \in\{1, \ldots, n\}$ and $j \in\{1, \ldots, n\}$.

**Output** For each test case output a single line that contains the number of quadruples $\left(i_{1}, i_{2}, j_{1}, j_{2}\right)$ where $1 \leqslant i_{1} \leqslant i_{2} \leqslant n$ and $1 \leqslant j_{1} \leqslant j_{2} \leqslant n$ and for which the sum
$$
\sum_{i^{\prime}=i_{1}}^{i_{2}} \sum_{j^{\prime}=j_{1}}^{j_{2}} x_{i^{\prime}, j^{\prime}}
$$

is even.

**Points** There are three groups of test sets, worth 100 points in total.

1. For the first group of test sets, worth 30 points, you may assume that $1 \leqslant n \leqslant 10$.
2. For the second group of test sets, worth 50 points, you may assume that $1 \leqslant n \leqslant 50$.
3. For the third group of test set, worth 20 points, there are no additional assumptions.

Corresponding sample test sets are contained in testi.in/out for $i \in\{1,2,3\}$. 