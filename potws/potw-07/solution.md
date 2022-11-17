# Solution

## Basic Idea

An optimal solution alway deactivates the bomb with the minimum time left first (greedy).

Why? If I had a working solution, that deactivates a bomb $B_i$ before bomb $B_j$ even though $j < i$. Then I am guaranteed to also have a solution, if I remove $B_j$ before $B_i$, because I know that the order of removal does not make a difference for the total time needed. Therefore I can always swap the bombs with smaller time left with the ones with bigger time left, to get a solution that is more probable to stay inside the time constraint.

## Implementation

We have to be able to get the minimum Bomb $B_i$ with regard to $t_i$ fast, and we have to get the bombs that it stands on fast. To iteratively get the minimum we can either sort by $t$ or iteratively get the minimum from a heap. To get the bombs that it stands on we can use a simple binary tree structure, with the lower bombs as children. If we have to remove children as given by the tree structure we have to be able to find those children in the heap. This is possible only if the keys by which the bombs are saved in the heap are unique. At the same time they have to keeep the ordering by time. Therefore we use $t_i << 32 + i$ where $i$ is the index in the order of reading the data, and save the keys in long ints.