---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Hiking Maps

Alice and Bob want to go for a hike. They have carefully planned a scenic route for a full-day trip and now they are looking for a map of the region that they can use to navigate. It turns out that this is not as easy as thought: Instead of a single large map, the publisher decided to offer a large number of small triangular parts. Each of these parts is cheap to buy, but because they are so small, Alice and Bob need to buy lots of parts to cover the region for their trip. Thankfully there is an option to bulk-purchase parts. But the choices are limited: The map parts are numbered $t_{0}, \ldots, t_{n-1}$, and you can select $b, e \in\{0, \ldots, n\}$ to bulk-purchase for $e-b$ CHF all of $t_{b}, t_{b+1}, \ldots, t_{e-1}$. So Alice and Bob decide that they will purchase one single such sequence.

Other than costs Alice and Bob are also concerned with practical aspects. They have to change between map parts during their trip, but at least every single leg of their hike should be contained on a single map part. Fortunately that appears to be possible. How many map parts should they buy?

**Input** The first line of the input contains the number $c \leqslant 60$ of test cases. Each of the following c test cases is described as follows.

- It starts with a line that contains two integers $m \mathrm{n}\left(2 \leqslant m, n \leqslant 2^{\prime} 000\right)$, separated by a space. Here $m-1$ denotes the number of legs on their hike and $n$ denotes the number of map parts available.

- The following $m$ lines describe the hiking path $p_{0}, \ldots, p_{m-1}$. Each $p_{i}$ is defined by two integer coordinates $x y$, separated by a space and so that $|x|,|y|<2^{31}$. The hiking path is formed by the $m-1$ legs $p_{i}, p_{i+1}$, for $i \in\{0, \ldots, m-2\}$, each of which we model as a straight path from $p_{i}$ to $p_{i+1}$.

- The final $n$ lines describe the map parts $t_{0}, \ldots, t_{n-1}$. Each part is a triangle $t$ that is defined by six pairwise distinct points $q_{0}, \ldots, q_{5}$ as follows: The pair $q_{0}, q_{1}$ lies on the first edge, the pair $q_{2}, q_{3}$ lies on the second edge, and the pair $q_{4}, q_{5}$ lies on the third edge of $t$. None of $q_{0}, \ldots, q_{5}$ is a vertex of $t$, that is, all points lie in the relative interior of an edge. Each $q_{i}$ is defined by two integer coordinates $x y$, separated by a space and so that $|x|,|y|<2^{31}$.

We consider the map parts as closed sets, that is, each map part also covers its boundary edges and vertices. You may assume that every instance is solvable by selecting all map parts. However, such a solution is not optimal in general.

**Output** For every test case the corresponding output appears on a separate line. It consists of the minimum costs $\mathrm{k}$ in CHF that are needed to cover the whole hiking path. In other words, there are some $b, e \in\{0, \ldots, n\}$ with $k=e-b$ such that the path $p_{0}, \ldots, p_{m-1}$ is covered by the map $\bigcup_{i=b}^{e-1} t_{i}$ and such that each leg $p_{i-1} p_{i}$, for $i \in\{1, \ldots, m-1\}$, is completely contained in at least one $t_{j}$, for $j \in\{b, \ldots, e-1\}$.

**Points** There are five groups of test sets. Each group that is solved correctly is awarded with 20 points. So at most 100 points can be achieved in total.

1. For the first two groups of test sets, you may assume that $m, n \leqslant 100$. Corresponding example test sets are contained in the files hiking-maps-1.in/out.

2. For the remaining groups of test sets, there are no additional assumptions. Corresponding example test sets are contained in the files hiking-maps-2.in/out.


