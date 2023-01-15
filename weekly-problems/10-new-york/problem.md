---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - New York

The morning after missing his connection from New York to Liverpool, Phileas finds himself walking along the banks of the Hudson river looking for ships that are about to depart. He is already losing hope when he notices a trading ship preparing for departure-the Henrieta. He rushes straight to the captain, a peculiar person under the name of Andrew Speedy, and enquires about the journey, departure time, destination, etc. After some convincing (involving a non-trivial amount of money), Captain Speedy agrees to take Phileas and his party aboard. However, the currents are strong at this time of the year and the weather is unkind. Before setting sail, Captain Speedy insists to have a proper schedule for the journey in place.

The journey across the Atlantic Ocean passes through a sequence of critical points. New York is the origin, critical point 0 , and the remaining critical points $1, \ldots, n-1$, are scattered across the ocean. From every critical point, there may be several routes to sail to other critical points, or-if no such route exists - the critical point is considered to be secure and the journey may continue without obstructions from there on. Every route can be sailed in one direction only, never backwards. A sequence $s_{0}, \ldots, s_{\ell-1}$ of critical points such that there is a route from $s_{j-1}$ to $s_{j}$, for all $j \in\{1, \ldots, \ell-1\}$, is called a trip of length $\ell$. The routes are arranged in such a way that for every critical point $s$ there exists exactly one trip from New York to $s$.

Captain Speedy has decided on an optimal trip length $\mathrm{m}$ and on a maximum risk $\mathrm{k}$ that he is willing to take during every single day. On every day of the journey, the ship must make a feasible trip. A trip is feasible if it is of length exactly $\mathrm{m}$ and it is safe, as defined next. To determine the safety of a trip, every critical point $i \in\{0, \ldots, n-1\}$ is labelled with a number $h_{i} \geqslant 0$, denoting the temperature at $i$. The risk of a trip is the difference between the maximum and minimum temperature of all critical points on the trip, since passing through two points with too big of a difference in temperature within a single day may damage the ship. Thus, a trip is considered safe if it has risk at most $k$.

As a first step to eventually determine an optimal and safe schedule for the journey from New York to Liverpool, the captain asks Phileas to find all critical points that a feasible trip can be started from.

**Input** The first line of the input contains the number $t \leqslant 30$ of test cases. Each of the $t$ test cases is described as follows.

- It starts with a line that contains three integers $n\ m\ k$, separated by a space. They denote
  - $n$, the number of critical points $\left(1 \leqslant n \leqslant 10^{5}\right)$;

  - $m$, the optimal trip length for a single day $\left(2 \leqslant m \leqslant 10^{4}\right)$;

  - $k$, the maximum risk Captain Speedy is willing to take $\left(0 \leqslant k \leqslant 10^{4}\right)$.


- The following line defines the temperature at the critical points. It contains $n$ integers $h_{0} \ldots h_{n-1}$, separated by a space, and such that $0 \leqslant h_{i}<2^{31}$, for $i \in\{0, \ldots, n-1\}$. Here $h_{i}$ denotes the temperature at the $i$-th critical point.
- The following $n-1$ lines define the routes. Each line consists of two integers $u\ v$, separated by a space, and such that $u, v \in\{0, \ldots, n-1\}$. This means that there exists a route to sail from the critical point $u$ to the critical point $v$.

**Output** For each test case output a single line with a sequence of all critical points, separated by a space and listed in increasing order, for which there exists a feasible trip starting there. If there is no such critical point, output a single line with 'Abort mission'.

**Points** There are four groups of test sets, worth 100 points in total.

1. For the first group of test sets, worth 20 points, you may assume that at every critical point there is at most one route starting from it. Furthermore, $n \leqslant 10^{3}$ and $m, k \leqslant 10^{2}$.

2. For the second group of test sets, worth 20 points, you may assume that at every critical point there is at most one route starting from it.

3. For the third group of test sets, worth 20 points, you may assume that $n \leqslant 10^{3}$ and $m, k \leqslant 10^{2}$.

4. For the fourth group of test sets, worth 40 points, there are no additional assumptions. Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3,4\}$.

