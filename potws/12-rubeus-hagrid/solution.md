# Solution

## Basic Idea

Traverse undirected acyclic graph (=tree), using each edge only twice. This means that every subtree must be traversed entirely before returning (DFS). Therefore it reduces to choosing the order in which subtrees are traversed. In the case of the balanced tree this is simply the one with the smallest sum of edge weights. In the general case this is more complicated:

We can look at the amount of gold that we loose when traversing a subtree, which seems to be $2 \cdot \sum_i w_i \cdot (n - n_p)$ where $w_i$ are the edge weights, $n$ is the amount of vertices and $n_p$ is the amount of vertices already visited by previous walks. 

Now if we swap the order in which we traverse two subtrees, this does not affect the value of all other subtrees (apart from those two). Therefore to order the subtrees, we only have to find a correct relation between two of them. Since we multiply the weight sum of the second one with the number of vertices of the first one, it can easily be seen that the correct ordering is
$$
a \text{ before } b \Leftrightarrow n_a \cdot w_b > w_a \cdot n_b
$$
