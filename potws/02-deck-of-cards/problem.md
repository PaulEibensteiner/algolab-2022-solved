---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Deck of Cards

You are given a deck of $n$ custom made cards, denoted by $0, \ldots, n-1$ going from the top of the deck to the bottom. Each card $i$ has a number $v_{i}$ which represents its value. You play a strange game with your younger brother, where he tells you his favourite number $k$ and you need to find cards $i$ and $j$ such that $i \leqslant j$ and $\sum_{\ell=i}^{j} v_{\ell}=k$. Since you are older than your brother, you know that finding such a subset of the deck won't always be possible. Thus, you want to write a program which finds two cards $i$ and $j$ such that the sum $\sum_{\ell=i}^{j} v_{\ell}$ is as close as possible to $k$. If there are multiple candidates for the solution, find the one which is lexicographically smallest.

**Input** The first line of the input contains the number $t \leqslant 80$ of test cases. Each of the $t$ test cases is described as follows.

- It starts with a line that contains two integers $n\ k$, separated by a space, where $n$ denotes the number of cards, and such that $1 \leqslant n \leqslant 10^{5}$ and $0 \leqslant k \leqslant 2^{30}$.

- The following line defines the values of the cards 0 to $n-1$, in that order. It contains $n$ integers $v_{0} \ldots v_{n-1}$, separated by a space, and such that $0 \leqslant v_{i} \leqslant 2^{30}$, for $i \in$ $\{0, \ldots, n-1\}$. It is guaranteed that $\sum_{i=0}^{n-1} v_{i} \leqslant 2^{30}$.

**Output** A solution is a pair $i, j$ of cards with $i \leqslant j$. We define the value of the solution $i, j$ as
$$
\operatorname{val}(i, j):=\left|k-\sum_{\ell=i}^{j} v_{\ell}\right| .
$$

For each test case output a single line containing two numbers $i$ and $j$, separated by a space, corresponding to the solution $i, j$ with the smallest value. If there are multiple such solutions, output the lexicographically smallest one.

*Note:* $(i, j)$ is lexicographically smaller than $\left(\mathfrak{i}^{\prime}, \mathfrak{j}^{\prime}\right)$ iff $i<\mathfrak{i}^{\prime}$ or $i=\mathfrak{i}^{\prime}$ and $j<j^{\prime}$.

**Points** There are three groups of test sets. For each group there is also a corresponding hidden test set. Overall, you can achieve 100 points.

1. For the first group of test sets, worth 20 points, and the corresponding hidden test set, worth 5 points, you may assume $n \leqslant 200$.

2. For the second group of test sets, worth 40 points, and the corresponding hidden test set, worth 10 points, you may assume $n \leqslant 3000$.

3. For the third group of test test sets, worth 20 points, and the corresponding hidden test set, worth 5 points, there are no additional assumptions.

Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3\}$. 
