---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Light the Stage

The following game involves a large number of people standing on a dark stage. In each round of the game a lamp is switched on to illuminate a certain part of the stage. Whoever is hit by the light is out of the game. The winners are those who survive longest.

We model the situation in $\mathrm{R}^{3}$, with the stage $S$ being the $x / y$-plane. The participants appear in $S$ as disks. A lamp is a point $\ell$ that is located in height $h$ above $S$. It illuminates the region within a $90^{\circ}$ cone below, that is, the point vertically below and every point in $S$ that is within an angle of at most $45^{\circ}$ to the vertical line through $\ell$. A participant $p$ is considered hit by a lamp $\ell$ (and thus out of the game) if the part of $p$ that is illuminated by $\ell$ has positive area.

The lamps do not affect each other in terms of blocking light. Rather think of a single movable lamp that is repositioned for each round. As a simplification, we assume that all lamps are positioned at the same height within a single game.

**Input** The first line of the input contains the number $t \leqslant 200$ of test cases. Each of the following $t$ test cases is described as follows.

- It starts with a line that contains two integers $m n\left(5 \leqslant m, n \leqslant 90^{\prime} 000\right)$, separated by a space. Here $m$ denotes the number of participants and $n$ denotes the number of lamps.

- The following $m$ lines describe the participants $p_{0}, \ldots, p_{m-1}$. Each participant is a disk of radius $r$ around $(x, y)$. It is defined by three integer coordinates $x\ y\ r$, separated by a space and so that $|x|,|y|<2^{31}$ and $0<r<2^{24}$.

- The following line contains a single integer $h, 0<h<2^{24}$, that defines the height at which the lamps in this game are positioned.

- The final $n$ lines describe the lamps $\ell_{0}, \ldots, \ell_{n-1}$. Each lamp is defined by two integer coordinates $x y$, separated by a space and so that $|x|,|y|<2^{31}$.

**Output** For every test case the corresponding output appears on a separate line. It consists of the sequence of integers $i_{1}, \ldots, i_{k}$, each followed by a single space, that is sorted in increasing order, such that $p_{i_{1}}, \ldots, p_{i_{k}}$ are the winners of the game in which lamps $\ell_{0}, \ldots, \ell_{n-1}$ are lit in this order.

**Points** There are five groups of test sets. Each group that is solved correctly is awarded with 20 points. So at most 100 points can be achieved in total.

1. For the first three groups of test sets, you may assume that at least one participant is still in the game after all given lamps have been lit.

2. For the remaining groups of test sets, there are no additional assumptions.

