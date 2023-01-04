---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Tracking

Colonel Moran is on the run after an unsuccessful assasination attempt. With a whole division of Scotland Yard led by inspector Lestrade on his trail, he needs to escape London and get to his hide—out in Dartmoor as quickly as possible. He has a map with travel times between different cities. In order to mask his smell and thereby evade pursuing dogs, he wants to travel some of the legs of the journey along rivers. Help him get to Dartmoor as quickly as possible while walking along a river at least a certain number of times. Roads may be used in either direction and—if desired—the same road may be used multiple times.

**Input** The first line of the input contains the number $t \leqslant 100$ of test cases. Each of the $t$ test cases is described as follows.

- It starts with a line that contains five integers $\mathrm{n} \mathrm{m} \mathrm{k} \times \mathrm{y}$, separated by a space and such that $1 \leqslant n \leqslant 10^{4}, 0 \leqslant m \leqslant 10^{5}, k \in\{1, \ldots, 10\}$, and $x, y \in\{0, \ldots, n-1\}$. Here $n$ denotes the number of cities, $m$ denotes the number of roads between cities, $k$ denotes the minimum number of rivers Moran wants to travel along, $x$ denotes the city that is the starting point, and $y$ denotes the city that is the final destination of the journey.

- The following $m$ lines define the roads. Each road is defined by four integers $a\ b\ c\ d$, separated by a space and such that $a, b \in\{0, \ldots, n-1\}, 1 \leqslant c \leqslant 2^{10}$, and $d \in\{0,1\}$. The corresponding road connects cities $a$ and $b$ within a travel time of $c$ minutes. The last parameter $d$ indicates whether $(d=1)$ or $\operatorname{not}(d=0)$ the road goes along a river.

**Output** For each test case output a line that contains the travel time (in minutes) of a shortest journey between the cities $x$ and $y$ such that at least $k$ legs (edges) of the journey go along a river. You may assume that there is a reachable river edge and that $y$ is reachable from $x$. Using a river edge multiple times counts multiple times towards the target $k$. There are no parallel roads and no roads that arrive at the same town they depart from.

**Points** There are four groups of test sets, worth 100 points in total.

1. For the first group of test sets and the corresponding hidden testcase, worth 15 points and 5 points, you may assume that $n \leqslant 100, k=1$, and that at most one road goes along a river.

2. For the second group of test sets and the corresponding hidden testcase, worth 15 points and 5 points, you may assume that $n \leqslant 500, k=1$, and that at most 10 roads go along a river.

3. For the third group of test sets and the corresponding hidden testcase, worth 25 points and 5 points, there are no additional assumptions.

4. For the fourth group of test sets and the corresponding hidden testcase, worth 25 points and 5 points, there are no additional assumptions.

Corresponding sample test sets are contained in testi. in/out, for $i \in\{1,2,3,4\}$.