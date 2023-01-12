---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Casino Royale

To cope with the latest round of budget cuts, MI6 asks its agents to use the railway system as their main means of transportation. With many upcoming missions in Central and Eastern Europe, travel planning has become intricate. Since $Q$ is on leave, you have been asked to prepare a schedule for agents traveling on the Pendolino train from Switzerland to Montenegro.

Some missions are deemed more important than others. Therefore every mission has an assigned priority. Higher priority missions are to be handled preferentially. Each mission has been assigned exactly one agent. To execute a mission, the assigned agent has to enter the train at the given stop and leave it at her/his mission destination. Furthermore, agents should travel inconspicuously. If too many agents are on the train at the same time, the large consumption of drinks (Château Angelus 1981 and Vesper Martini) may raise suspicion. There is a single train. It starts at a station $t_{0}$. It passes through $t_{1}, t_{2}, \ldots$ in that order and ends at $t_{n-1}$.

Your task is to come up with a travel schedule by selecting a subset of missions to be executed. The non-selected missions are deferred. The goal is to maximize the sum of priorities of the executed missions, while respecting the specified limit on the number of agents simultaneously on the train between any two consecutive stops. (Agents that enter the train at a station do not interfere with those leaving the train at that station.)

**Input** The first line of the input contains the number $t \leqslant 30$ of test cases. Each of the $t$ test cases is described as follows:

- It starts with a line that contains three integers $n\ m\ l$, separated by a space. They denote 
  - $n$, the number of train stops $t_{0}, t_{1}, \ldots, t_{n-1}\left(2 \leqslant n \leqslant 3 \cdot 10^{2}\right)$.

  - $m$, the number of missions $\left(1 \leqslant m \leqslant 10^{5}\right)$.

  - $\ell$, the maximum number of agents that can be on the train between any two consecutive stops $\left(1 \leqslant \ell \leqslant 10^{2}\right)$.

- The following $m$ lines describe the missions. Each mission is described by three integers $x\ y\ q$, separated by a space and such that $0 \leqslant x<y \leqslant n-1$ and $1 \leqslant q \leqslant 2^{7}$. This means that the assigned agent wants to travel from $t_{x}$ to $t_{y}$ and that the mission has priority $q$.

**Output** For each test case output a line with one integer $k$ that is the maximum achievable priority, defined as follows. A priority $k$ is achievable, if there is a set of missions whose priorities sum up to $k$ and such that no more than $\ell$ agents are on the train between any two consecutive stops.

**Points** There are four groups of test sets, which are worth 100 points in total.

1. For the first group of test sets, worth 30 points, you may assume that there are no more than $3 \cdot 10^{2}$ missions $\left(\mathrm{m} \leqslant 3 \cdot 10^{2}\right)$.

2. For the second group of test sets, worth 30 points, you may assume that all missions have the same unit priority $(q=1)$.

3. For the third group of test sets, worth 40 points, there are no additional assumptions.

Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3\}$.