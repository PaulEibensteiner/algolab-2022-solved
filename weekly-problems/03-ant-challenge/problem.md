---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Ant Challenge

Ants are amongst the most intensively studied forest insects. Especially their genius in the field of carrying stuff does not cease to amaze researchers. No wonder that all the other forest bugs are full of envy. After years of suffering, the forest bugs under the leadership of the termite faction have decided to show the world that they do possess similar logistics genius. For that purpose they have decided to organize a demonstration in which they intend to prove that by working together they can carry a breadcrumb even faster from one end of the forest to another than the ants.

Now that the date of the event is drawing near, some of the insects start to be afraid that they can not meet the termites' expectations. They have asked you for help!

We assume that insects move from tree to tree such that we can model the forest as a graph (not necessarily acyclic) in which vertices correspond to the trees of the forest. There is an edge between two trees, if there is a direct route between them in the forest. The duration of traveling along an edge of this graph differs from species to species. In addition, an insect can only move along edges that are part of its species' private network.

The private network of each species was established years ago during the exploration of the forest: starting from its hive located at a particular tree, each species explored new trees one at a time. The next tree to be explored was always the one fastest to be reached from the already explored territory (you may assume that every edge has a unique travel time for every species, in particular, the next tree to be explored is unique). The private network of every species covers all trees of the forest and consists of all edges that were used during this species' exploration of the forest.

For all species of forest insects, you are provided their hive's location together with the time it takes an insect of this species to travel along each tree-to-tree edge. Given a start tree and a finish tree, you are to find the duration of the fastest route through the combined private networks of all species from start to finish. The different species can alternate carrying the breadcrumb: every edge in the shortest path must be covered by at least one private network and if an edge is covered by multiple networks, you are free to choose the species that can travel the edge fastest for carrying along that edge.

See the figure below for an example with two species: both species need to take over parts of the shortest route.

![](https://cdn.mathpix.com/cropped/2023_01_01_ab4b2c48d124cce32f5eg-1.jpg?height=451&width=794&top_left_y=2036&top_left_x=240)

![](https://cdn.mathpix.com/cropped/2023_01_01_ab4b2c48d124cce32f5eg-1.jpg?height=431&width=686&top_left_y=2052&top_left_x=1142)

**Input **The first line of the input contains the number $t \leqslant 30$ of test cases. Each of the $t$ test cases is described as follows:

- It starts with a line that contains five integers $n, e, s, a, b$, separated by a space, denoting 
  - $n$, the number of trees in the forest $(1 \leqslant n \leqslant 500)$.
  - $e$, the number of edges in the connected, but not necessarily acyclic forest $(1 \leqslant e \leqslant$ $\left.\left(\begin{array}{c}n \\ 2\end{array}\right)\right)$
  - $s$, the number of species living in the forest $(1 \leqslant s \leqslant 10)$.
  - $a$ and $b$, the (zero-based) indices specifying the start tree and finish tree.

- The next $e$ lines each describe one edge of the forest: They are of the form $t_{1} t_{2} w_{0} \ldots$ $w_{s-1}$, meaning there is an edge between the two trees of (zero-based) indices $t_{1}$ and $t_{2}$ and that an insect of species $i$ (zero-based) takes (integer) time $w_{i}, 0 \leqslant w_{i} \leqslant 10^{5}$, to travel along that edge.

- The last line contains the indices of the species' hives $h_{0} h_{1} \ldots h_{s-1}$, separated by a space.

**Output** For every test case output a single line containing the time it will take the insects to transport the breadcrumb from start to finish if they choose an optimal route.

**Points** There are four groups of test sets, which are worth 100 points in total.

1. For the first group of test sets, worth 20 points, you may assume that there is only one species $(s=1)$ and that the forest is as sparse as possible $(e=n-1)$.
2. For the second group of test sets, worth 20 points, you may assume that $e=n-1$.
3. For the third group of test sets, worth 20 points, you may assume that $s=1$.
4. For the fourth group of test sets, worth 40 points, there are no additional assumptions.

Corresponding sample test sets are contained in test $i$. in/out, for $i \in\{1,2,3,4\}$. 