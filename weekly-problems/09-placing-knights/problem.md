---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Placing Knights

Let us have a square chessboard of a given size with holes. How many knights can you place on the chessboard so that no two knights threaten each other?

**Input** The first line of the input contains the number of chessboards $1 \leqslant t \leqslant 50$. Each of the $t$ chessboards is described as follows:

- It starts with a line containing $1 \leqslant n \leqslant 2^{6}$, the length of each side of the chessboard in squares.

- The next $n$ lines each contain $n$ integer values, separated by a space, denoting whether the corresponding chessboard field is present (1), or is a hole (0).

**Output** For every testcase you should output a single line with the maximum number of knights you can place on the chessboard so that no two threaten each other.

(I.e. if a knight is placed on position $[i, j]$ ($i$th row, $j$th column), there can be no knights at positions $[i-1, j-2],[i-1, j+2],[i+1, j-2],[i+1, j+2],[i-2, j-1],[i-2, j+1],[i+2, j-1]$, [ $i+2, j+1]$. It is disallowed to place knights on the holes or the outside of the chessboard.)

**Points** There are three groups of test sets which are worth 100 points in total.

1. For the first group of test sets, worth 30 points, you may assume that $n \leqslant 6$.

2. For the second and third group of test sets, worth 35 points each, there are no further assumptions.

Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3\}$.
