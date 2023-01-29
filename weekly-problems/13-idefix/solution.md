# Solution

## Problem in a nutshell

Given is a point set of trees and a point set of bones. We are interested in subsets of trees $t_i$, where each tree in the subset has another tree of squared distance at most $(2 \cdot r)^2 = d$ from it. And we are interested in the amount of bones $b_i$ that are at squared distance at most $r^2$ from the closest tree in subset $t_i$. We want to find

1. Given $d = s$, the largest $b_i$ and output it as $a$

2. Given an amount of bones $k$, we want to find the minimum $d$ such that the largest $b_i = k$

## Solution

1. Create Delaunay triangulation of trees, sort the edges by length.
2. For all bones, find the closest tree, save the squared distance times four and the tree index in a list. Sort by the distances.
3. Create union find data structure of tree indexes $t_i$, with corresponding $b_i = 0$
4. Go through edges and distances in parallel:
   - If edge, union the trees it connects in UF data structure, add up the $b_i$, keep track of $\max b_i = b_m$
   - If distance, add 1 to respective $b_i$, keep track of $b_m$
   - If $b_m \geq k$ save the current squared distance as $q$
   - If current squared distance greater $s$ or both lists are empty save maximum $b_m = a$ 