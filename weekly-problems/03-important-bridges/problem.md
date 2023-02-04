---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Important Bridges

Scatteredalot is a small country, that consists of many inhabited islands connected with bidirectional bridges, so that you can get from any island to any other (possibly using several bridges). Every bridge connects two different islands and for any pair of islands there is at most one bridge that connects them.

Of course it happens from time to time that one of these bridges has to be repaired and the Scatterlotian people cannot use it during this time. Usually this is not a problem because there are so many bridges that most of the times they can use another path leading to the same destination they are heading to. Unfortunately this is not always the case. If repairing a single bridge causes some two islands to be inaccesible from each other, we will call such a bridge critical.

Scatteredalot's prime minister, who would like to be re-elected, asks you to find all critical bridges.

Can you help him?

**Input** The first line of the input file will contain an integer giving the number $c \leqslant 30$ of test cases following.

Each test case starts with a line containing $n$, the number of islands and $m$, the number of bridges $\left(0 \leqslant n \leqslant 3 \cdot 10^{4}, 0 \leqslant m \leqslant 3 \cdot 10^{4}\right)$. After that, you will find $m$ lines, the $i$-th of them containing two space-separated integers $e_{i_{1}} e_{i_{2}}$, with $0 \leqslant e_{i_{1}}, e_{i_{2}}<n$ and $e_{i_{1}} \neq e_{i_{2}}$, describing the numbers of the two islands that the $i$-th bridge connects (the islands are numbered from 0 to $n-1)$. You will never find two bridges connecting the same pair of islands.

**Output** For each test case write first $k$, the amount of critical bridges, in a single line, followed by $k$ lines containing the island numbers $e_{i_{1}} e_{i_{2}}$ that the $i$-th critical bridge connects.

Please make sure that the list of bridges is ordered in such a way that $e_{i_{1}}$ is always smaller then $e_{i_{2}}$, and that for all $i, j$ with $i<j$ holds that $e_{i_{1}} \leqslant e_{j_{1}}$ and if $e_{i_{1}}=e_{j_{1}}$ then also $e_{i_{2}}<e_{j_{2}}$. (Which means that the output should be ordered lexicographically.) In this way, it will be easier for the prime minister to check the list you have created.

**Points** There are three groups of test sets, worth 100 points in total.

1. For the first group of test sets, worth 40 points, you may assume that $m \leqslant 500$.

2. For the second and third group of test sets, there are no additional assumptions.

Corresponding sample test sets are contained in test $i$. in/out, for $i \in\{1,2\}$. 

