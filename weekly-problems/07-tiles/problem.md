---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Tiles

Domino Magic has been a producer of stylish domino game pieces for several years. Their exclusive designs and quality materials have always guaranteed them a safe position on the market. Recently however, due to the global financial crisis, the demand for luxurious domino games has drastically dropped. In order to stay afloat, the company has decided to expand into other areas. Their newest plan is to produce garden floor tiles using their exclusive domino designs. The problem is that these designs require rectangular tiles of a length to width ratio of 2:1. Many of Domino Magic's rich customers have complex garden layouts which they want to tile and it is often difficult to decide whether that is possible with 2:1 tiles.

**Problem** Write a program to help Domino Magic decide whether a given layout can be tiled with 2:1 tiles. Every tile covers exactly two horizontally or vertically adjacent spaces of the garden layout. Every space that is to be tiled must be covered by exactly one tile while the other spaces must remain untiled. The supply of tiles is unlimited.

**Input** The first line of input contains the number $n$ of test cases to follow $(0 \leqslant n \leqslant 100)$. Every test case starts with a single line containing two space-separated integers $1 \leqslant w, h \leqslant 50$, specifying the width and the height of the garden layout at hand, respectively. The next $h$ lines each describe one row of the layout. Each such line consists of $w$ characters: `.` if that space is to be tiled and `x` if it is to be left free.

**Output** For every test case output a single line containing the word "yes" if the given layout can be tiled and "no" otherwise.
