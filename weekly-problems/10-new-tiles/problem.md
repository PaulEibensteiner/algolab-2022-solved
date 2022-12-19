---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22
Department of Computer Science Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - New Tiles

Problem Domino Magic started releasing brand new $2 \times 2$ tiles because everybody is already tired of the $1 \times 2$ domino tiles. To make a long story short, you are given a rectangular floor plan with some cells which you are not allowed to place tiles on, and your goal is to maximize the number of new $2 \times 2$ tiles you can put in this rectangle without overlapping.

**Input** The first line contains $1 \leqslant t \leqslant 20$, the number of testcases. Each of the $t$ testcases is described as follows:

- It starts with a single line that contains two integers $\mathrm{h}$ w, separated by a space, specifying specify the height $h$ and the width $w$ of the floor plan at hand $(1 \leqslant h \leqslant 100,1 \leqslant w \leqslant 17)$.

- The following $\mathrm{h}$ lines each describe one row of the floor plan, ordered from top to bottom. Each such line consists of $w$ space-separated characters: ' 1 ' if that square can be tiled and ' 0 ' if it cannot be used. You may assume that the floor plan is surrounded by a wall, so the border cells of the input consist of $0$s.

**Output** For each test case output a single line with the maximum number of new $2 \times 2$ tiles you can place on the grid without overlapping.

Points There are two test sets:

1. For the first set, worth 50 points, you may assume that $w \leqslant 10$.

2. For the second set, worth 50 points, there are no additional constraints.

## Problem in a Nutshell

Given a $h × w$ matrix of 0’s and 1’s.
Find the maximum number of non-overlapping $2 × 2$ matrices of the form: $\matrix{1 & 1 \\ 1 & 1}$
