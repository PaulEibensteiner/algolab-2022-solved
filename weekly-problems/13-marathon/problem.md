---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Marathon

Once a year, the big marathon of Algoland takes place. Simone is in charge of organizing this marathon. At first, she slightly underestimated this task. She fixed the position of the start and finish line for the race and on a sunny morning, she took her running shoes and GPS watch and checked that the race from start to finish has the desired length (42.195 kilometers for a proper marathon, but that is not important here since Algoland uses a different unit of length).

She thought that this is all she had to prepare. But once the registration website was up, people started to sign up like crazy and she suddenly got worried that they might not all fit onto the streets. Maybe she can find another path from start to finish that has exactly the same length so that more runners could participate? She also figured that she should check that she did not miss any shortcut that would make the race shorter for some but not all of the athletes. She got her hands on a complete street map of Algoland and got down to work.

This map lists all the intersections and the streets between pairs of intersections across Algoland. All streets are two-way streets (the runners would not pay attention to the direction of a one-way street anyways) and all runners stick to those roads, noone cuts across the country. For every street, the map states its length (how far the runners have to run between the two intersections) and its width (how many runners can fit on this street when running right next to each other).

Simone makes the following two simplifying assumptions: (1) The runners pass through the intersections instantaneously. In particular, any possible difference of length in crossing the intersection and any possible interaction between the runners is ignored. (2) The length of each street is exactly the same for all runners. In particular, any possible difference in path length along curves (inside track versus outside track) is ignored.

Since Algoland's marathon is hugely popular, there are always more runners willing to participate than can actually fit on the streets along the track. So the final thing Simone has to prepare is to compute the number of runners that she wants to admit to the race. In the hope to fit as many athletes as possible, she decided that the race should not follow a fixed track this year, but that every runner can pick his/her own path. Of course, none of the runners is willing to take a detour, so they will each pick some shortest path from start to finish. Also, all the runners start at the same time. Simone really wants to be prepared for the worst case: she assumes that all the athletes run at exactly the same (unknown) speed, meaning that all the runners that take the same road have to fit next to each other. The runners are very clever: they will coordinate among themselves who picks which path. Your task is to compute the maximum number of participants that can be admitted to the race.

**Input** The first line of the input contains the number $t \leqslant 30$ of test cases. Each of the $t$ test cases is described as follows.

- It starts with a line that contains four integers $n\ m\ s\ f$, separated by a space. They denote
  - $n$, the number of intersections $p_{0}, \ldots, p_{n-1}$ in Algoland $\left(2 \leqslant n \leqslant 10^{3}\right)$

  - $m$, the number of streets in Algoland $\left(0 \leqslant m \leqslant 5 \cdot 10^{3}\right)$

  - $s$, the number of the intersection $p_{s}$ where the race starts $(0 \leqslant s \leqslant n-1)$;

  - $f$, the number of the intersection $p_{f}$ where the race finishes $(0 \leqslant f \leqslant n-1$ and $s \neq f)$.


- The following $m$ lines define the streets of Algoland. Each line contains four integers integers $a\ b\ c\ d$, separated by a space and such that $0 \leqslant a \leqslant n-1,0 \leqslant b \leqslant n-1$, $1 \leqslant c \leqslant 10^{4}$, and $1 \leqslant d \leqslant 10^{4}$. Such a line describes a street of width $c$ and length $d$ that connects intersections $p_{a}$ and $p_{b}$.

You can assume that there is a path from $p_{s}$ to $p_{f}$ in each test case.

Note: There may be streets with $a = b$ and there may be several streets between the same pair of intersections.

**Output** For each test case output one line with a single integer that denotes the maximum number of runners that can be admitted to the race.

**Points** There are four groups of test sets, each of which is worth 25 points.

1. For the first group of test sets, you may assume that (1) every street lies on a shortest path from $p_{s}$ to $p_{f}$ and $(2)$ for each street $p_{a} p_{b}$ the distance from $p_{s}$ to $p_{a}$ is shorter than the distance from $p_{s}$ to $p_{b}$.

2. For the second group of test sets, you may assume that the shortest path from $p_{s}$ to $p_{f}$ is unique.

3. For the third group of test sets, you may assume that every intersection, except for $p_{s}$ and $p_{f}$, is the endpoint of exactly two streets.

4. For the fourth group of test sets, there are no additional assumptions.

Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3,4\}$. 