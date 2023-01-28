# Solution

## Problem in a Nutshell

Given is a weighted tree which is sorted i.e. parent weight > child weight. For a set of $(n, a)$ pairs, find the oldest parent of node $n$ with age younger or equal $a$.

## Solution

Do dfs, keep vector of parent nodes, binary search the given age in the list. Should also be possible with binary lifting.
