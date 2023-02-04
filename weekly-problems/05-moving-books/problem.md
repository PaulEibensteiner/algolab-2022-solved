---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Moving books

Simone owns many books, and now she is moving to a new apartment! Luckily her books are already neatly packed away in cardboard boxes and ready to move. However, each box must still be moved from her second-floor apartment to the moving van parked in the street.

For this purpose, $n$ friends have volunteered their service. Each friend is of a certain strength, expressed by a number $s_{i}$ corresponding to the weight of the heaviest box that $s /$ he can lift. The boxes are designed in such a way that each friend can lift only one box at a time; additionally it is impossible for two friends to lift a box together.

Given that the time to move a box from the apartment to the van is exactly two minutes (regardless of the strength of the friend), and that the time to get back upstairs after moving a box is one minute, what is the least amount of time in which all the boxes can be moved to the van? Initially all friends are upstairs, but it is not necessary for all friends to be back upstairs at the end.

You can assume that an unlimited number of friends can use the stairs at the same time without bumping into each other. You can also assume that Simone is busy carrying other things and does not help with the boxes.

**Input** The first line of the input contains the number $t \leqslant 20$ of test cases. Each of the $t$ test cases is described as follows.

- It starts with a line that contains two integers $\mathrm{n} \mathrm{m}$, separated by a space, denoting the number of friends $\left(1 \leqslant n \leqslant 3 \cdot 10^{5}\right)$ and of boxes $\left(1 \leqslant m \leqslant 3 \cdot 10^{5}\right)$.

- The following line defines the strengths of the friends. It contains $n$ integers $s_{0} \ldots s_{n-1}$, separated by a space, and such that $1 \leqslant s_{i} \leqslant 5 \cdot 10^{5}$, for all $i \in\{0, \ldots, n-1\}$. Here $s_{i}$ denotes the strength of the $i$-th friend.

- The following line defines the weights of the boxes. It contains $m$ integers $w_{0} \ldots w_{m-1}$, separated by a space, and such that $1 \leqslant w_{i} \leqslant 5 \cdot 10^{5}$, for all $i \in\{0, \ldots, m-1\}$. Here $w_{i}$ denotes the weight of the $i$-th box.

**Output** For each test case output a single line with the minimal time needed to move all the boxes from the apartment to the van. If the friends are not sufficiently strong to move the boxes, output a single line with `impossible`.

**Points** There are three groups of test sets, worth 100 points in total.

1. For the first group of test sets, worth 20 points, you may assume that $1 \leqslant n, m \leqslant 5000$ and that $w_{i}, s_{i} \leqslant 100$ for all $i$.

2. For the second group of test sets, worth 40 points, you may assume that $w_{i}, s_{i} \leqslant 100$ for all $i$.

3. For the third group of test sets, worth 40 points, there are no additional assumptions.

Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3\}$.