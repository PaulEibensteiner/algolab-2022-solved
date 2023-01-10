---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - H1N1

In times of an epidemic, it is important to stick to strict hygienic rules and to keep distance to infected individuals.

An influential pharmaceutical company has decided to develop a ground-breaking device to prevent its users from coming into contact with infected people. You are asked to develop part of the software for its central server. Your program has coordinates of all known infected individuals at its disposal. It is supposed to answer queries whether a given user of the device is able to escape the contaminated area, assuming that all infected individuals stay at their current location. In order to escape, the user must be able to get arbitrarily far from all infected people, without ever coming closer than a given distance $d$ to any of them.

**Input** We consider the situation as seen from above, such that people appear as points in the plane. The input contains several test cases. Each of them is described as follows.

- It starts with a line that contains a single integer $n\left(2 \leqslant n \leqslant 6 \cdot 10^{4}\right)$, denoting the number of infected people in the area.

- The next $n$ lines contain their integer coordinates $x$ y separated by a space and so that $|x|,|y|<2^{24}$.

- The following line contains a single integer $m\left(1 \leqslant m \leqslant 4 \cdot 10^{4}\right)$ denoting the number of users asking for an escape route. These are to be checked one by one separately, that is, they should be considered separate queries. None of them is infected.

- Finally, each of the subsequent $m$ lines describes a user who wants to escape. Each user is specified by three integer coordinates $x, y$, and $d$, separated by space and such that $|x|,|y|<2^{24}$ and $0 \leqslant d<2^{49}$. The person is located at position $(x, y)$ and wants to keep distance at least $\sqrt{d}$ from the infected (i.e., $\sqrt{d}$ is still allowed).

The input is terminated by a line containing a single value 0 .

**Output** For every test case the corresponding output appears on a single line consisting of $m$ characters `y` or `n` (one letter per query). Output the letter `y`, if there is a way to escape, and `n`, otherwise.

**Points** There are five groups of test sets, each worth 20 points.

1. For the first group of test sets, you may assume that $n, m \leqslant 500$.

2. For the second group of test sets, you may assume that $n, m \leqslant 3^{\prime} 000$.

3. For the third group of test sets, you may assume that $n, m \leqslant 10^{4}$.

4. For the fourth and fifth group of test sets, there are no additional assumptions.

There is only one single group of sample test sets, whose specification matches the one for the third group of test sets.
