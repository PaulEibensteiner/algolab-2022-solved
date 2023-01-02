# Solution

## Basic Idea

Each specie’s private network must be a unique MST (see Prim’s algorithm).

1. Create mst for each species $s \cdot O(e \log e)$
2. Create master graph by choosing the minimum weight edge from the msts for each possible edge (and none if it does not exist in the msts) $O(e)$
3. Create shortest path in master graph from $a$ to $b$ $O(n \log n + e)$

## Challenges

- Iterating jointly though the graphs of different edge numbers. Solved by sorting the edge descriptors by source and target nodes.
- Assigning vectors copies them. Therefore references must be passed and used.