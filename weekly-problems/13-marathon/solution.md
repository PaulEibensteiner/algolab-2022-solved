# Solution

## Problem in a nutshell

In an undirected weighted graph with capacities, find the max flow from vertex $s$ to $f$ only using shortest paths, as defined over the weights.

## Solution

While reading input, discard all loops, discard edges with same start and end and higher distance, and add up edges with same start, end and distance to form a (non multi) graph. Calculate shortest paths to every node $v$ from node $s$, using a modified version of Dijkstra's which keeps a list of all predecessors on paths with minimum distance from $s$ to $v$. Then walk all paths backwards starting at $s$, and add the edges encountered to a flow graph. Then calculate max flow.

## Challenges

Priority queue sorts from high to low. Using `setS` as first template parameter in boost graph prevents multigraph.