---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - The Hand's Tourney

> "King Robert had staged it in her father's honor. High lords and fabled champions had come from all over the realm to compete, and the whole city had turned out to watch. She remembered the splendor of it: the field of pavilions along the river with a knight's shield hung before each door, the long rows of silken pennants waving in the wind, the gleam of sunlight on bright steel and gilded spurs. The days had rung to the sounds of trumpets and pounding hooves, and the nights had been full of feasts and song. Those had been the most magical days of her life, but they seemed a memory from another age now."

*Thoughts of Sansa Stark, A Song of Ice and Fire by George R. R. Martin*

King Robert Baratheon hosts a tournament to celebrate Lord Eddard Stark's appointment as the new Hand of the King. For the joust alone, the record sum of sixty thousand gold dragons will be awarded. Every noble family of Westeros plans to attend—and some not so noble ones as well. It is a major logistic effort to provide accommodation for all the visitors. As the capacities within the city of King's Landing are limited, a large campground with thousands of tents has been prepared outside of the city.

You are tasked to prepare an assignment that assigns every tent to a family. Obviously, there are some considerations to take into account. For once, every family needs to get some number $k$ of tents. Also, unfortunately, the different families dislike and distrust each other. So tents assigned to different families must not be too close.

The number and placement of the tents and the number $k$ are considered as fixed. Then the other two parameters, the number of families and the minimum distance, are tied to one another. More precisely, an assignment is $(f, s)$-reasonable if it satisfies the following criteria.

- Every tent is assigned to exactly one of $f$ families.

- To each of the $f$ families, at least $k$ tents are assigned.

- Whenever two tents are assigned to different families, they are at squared Euclidean distance at least $s$.

You have to answer the following two questions:

1. For given $f_{0}$, what is the largest $s$ such that there exists an $\left(f_{0}, s\right)$-reasonable assignment?

2. For given $s_{0}$, what is the largest $f$ such that there exists an $\left(f, s_{0}\right)$-reasonable assignment?

**Input** The first line of the input contains the number $t \leqslant 30$ of test cases. Each of the $t$ test cases is described as follows.

- It starts with a line containing four integers $n\ k\ f_{0}\ s_{0}$, separated by a space. They denote
  - $n$, the number of tents on the campground $\left(2 \leqslant n \leqslant 9 \cdot 10^{4}\right)$;

  - $k$, the minimum number of tents that must be assigned to every family $(1 \leqslant k \leqslant 4)$;

  - $f_{0}$, the given number of families for the first question $\left(f_{0} \geqslant 2\right.$ and $\left.k f_{0} \leqslant n\right)$; and

  - $s_{0}$, the given minimum squared distance for the second question $\left(0 \leqslant s_{0} \leqslant 2^{50}\right)$.


- The following $n$ lines define the positions of the tents on the campground.

Each position is described by two integers $x y$, separated by a space and such that $|x|,|y|<2^{24}$. You may assume that the $n$ positions of the tents are pairwise distinct.

**Output** The output for each test case consists of a separate line containing two integers $s\ f$, separated by a space. They denote

- $s$, the maximum squared distance for which there exists an $\left(f_{0}, s\right)$-reasonable assignment and

- $f$, the maximum number of families for which there exists an ( $\left.f, s_{0}\right)$-reasonable assignment.

**Points** There are four groups of test sets, worth 100 points in total.

1. For the first group of test sets, worth 30 points, you may assume that there are only few tents $\left(n \leqslant 10^{3}\right)$, that families may get only one tent $(k=1)$, and that there are many families $\left(f_{0}=n\right)$.

2. For the second group of test sets, worth 30 points, you may assume that families may get only one tent $(k=1)$ and that there are many families $\left(f_{0}=n\right)$.

3. For the third group of test sets, worth 20 points, you may assume that families may get only one tent $(k=1)$.

4. For the fourth group of test sets, worth 20 points, there are no additional assumptions.

Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3,4\}$.