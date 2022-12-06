# Solution not entirely working

## Basic Idea

Traverse undirected acyclic graph (=tree), using each edge only twice. This means that every subtree must be traversed entirely before returning (DFS). Therefore it reduces to choosing the order in which subtrees are traversed. In the case of the balanced tree this is simply the one with the smalles sum of edge weights. In the general case this is more complicated:

We can look at the amount of gold that we loose when traversing a subtree, which seems to be $2 \cdot \sum_i w_i \cdot (n - n_p)$ where $w_i$ are the edge weights, $n$ is the amount of vertices and $n_p$ is the amount of vertices already visited by previous walks. Reforming this formula (and since we can not change $n$) we get to the maximization problem

$$
\max \left[ w_1 \cdot 0 + w_2 \cdot n_1 + w_3 \cdot (n_1 + n_2) + \ldots \right]
$$

where we want to maximize over the orders of the $w_i$ and $n_i$

