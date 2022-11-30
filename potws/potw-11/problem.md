---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22 Department of Computer Science Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Ceryneian Hind

After Hercules successfully slayed the Nemean Lion and the Lernaean Hydra, Eurystheus finally realized that our hero was too good at fighting monsters. Therefore, Eurystheaus decided on a more difficult task for the third labor: capturing the Ceryneian Hind, a beast so fast that it could outpace a deadly arrow.

Hercules knew that despite being a demigod, he could not match the speed of the Hind. Therefore, he made a cunning plan: he would chase the Hind to a semi-dead end S, a district without any path leaving it. Then Hercules would run after the Hind in this district incessantly until the beast was exhausted and Hercules could capture it.

To choose where to chase the hind to, Hercules has a map of ancient Europe. This map can be regarded as a directed graph, whose vertices correspond to locations (forests, mountains, meadows, etc.) and whose edges correspond to paths that connect these locations. Furthermore, not all locations are ideal for capturing a sleeping beast, for instance, doing so in a swamp is more challenging than on an open field. To account for this, Hercules carefully scored each location on the map according to how convenient it is to conduct the capture there.

To maximize the chance of success, Hercules hence needs to find a semi-dead end $S$ with a maximum convenience score. Formally, a semi-dead end is a non-empty subset $S$ of vertices such that no edge leaves $S$. The convenience score of a semi dead-end $S$ is the sum of the convenience scores of all the vertices in S. It may happen that no suitable semi-dead end exists: if there is no semi-dead end with a positive convenience score, then Hercules will give up the current plan and try to find another solution.

Input The first line of the input contains the number $t \leqslant 30$ of test cases. Each of the $t$ test cases is described as follows.

- It starts with a line containing two integers $n$ m, separated by a space. They denote
- $n$, the number of locations on the $\operatorname{map}(2 \leqslant n \leqslant 500)$

- $m$, the number of directed paths on the map $(1 \leqslant m<250,000)$.

- The following line contains $n$ integers, separated by a space. The $i$-th integer $s_{i}$ denotes the convenience score of the $i$-th location $\left(\left|s_{i}\right| \leqslant 2^{10}\right)$.

- The following $m$ lines describe the directed paths. Each of the lines contains two integers u v, separated by a space. They denote

$-u$, the starting location of the path $(0 \leqslant u \leqslant n-1)$; $-\mathrm{v}$, the ending location of the path $(0 \leqslant v \leqslant n-1$ and $v \neq \mathrm{u})$

Output For each test case the corresponding output appears on a separate line. If the map does not contain any semi-dead end with a strictly positive convenience score, the output is "impossible". Otherwise, the output is the maximum convenience score over all semi-dead ends on the map.

Points There are four groups of test sets. For each group there is also a corresponding hidden test set, each worth 5 points. Overall, you can achieve 100 points.

1. For the first group of test sets, worth 25 points, you may assume that the map is a polytree ${ }^{1}$.

2. For the second group of test sets, worth 25 points, you may assume the convenience score of any location is either $-1$ or 1 , and all paths are oriented from a location with a positive score to a location with a negative score.

3. For the third group of test sets, worth 15 points, you may assume all locations have nonzero convenience scores, and that there are no paths between two locations with both positive scores nor between two locations with both negative scores.

4. For the fourth group of test sets, worth 15 points, there are no additional assumptions. Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3,4\}$.

${ }^{1}$ A polytree is a directed acyclic graph whose underlying undirected graph is a tree. Namely, if we turn each edge of a polytree into an undirected one, the resulting graph is both connected and acyclic.