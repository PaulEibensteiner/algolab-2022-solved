# Solution

## Basic Idea

Teams are vertices, matches are edges and flow is directed via cost. Edges with capacity $l$ from and to teams ensure that they are filled up first, then come edges with cost $2^15$ and capacity $\infty$. To ensure that difficult matches are filled last, team's vertices are doubled and the doubled vertices with higher cost connected to each other.

## Challenges

Can not pass edges from function for some reason. Can not just do max flow on graph, must also do find cost for values to be correct first.