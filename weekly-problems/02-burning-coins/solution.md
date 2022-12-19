# Solution

## Basic Idea

Simple dynamic programming top down approach. The points we are guaranteed to score, with the pile starting at index $i$ and ending at $j$ is $V(i,j)$

- Base case: One coin left means we take it ($V(i,i) = v_i$) if it's our turn, else opponent takes it ($V(i,i) = 0$)

- Recursive formula: If it's our turn, then $V(i,j) = \text{max}(V(i+1, j) + v_i,\ V(i, j-1) + v_j)$ else if it‘s the opponents turn then $V(i,j) = \text{min}(V(i+1, j),\ V(i, j-1))$

- Use state array to prevent recomputing overlapping subproblems
