# Solution

## Basic Idea

For each position in the newspaper, one unit of flow can go from the source to either the front side letter or the backside letter. Then, from either letter, a flow equal to the amount of ocurrences of the letter in the message goes to the sink. Now maximum flow must be equal to the message's length, if it is possible.

This can be further optimized, because each position in the newspaper with the same backside / backside letter combination is equivalent. So we only need 26 choose 2 nodes, and add up the respective in and outgoing edges. Graph size: (26 choose 2) + 26 + 2 = 353 vertices; (26 choose 2) + (26 choose 2) x 2 + 26 x 2 = 1079 edges; Flow of n

Still not working though

Indexing of all positions in n choose 2, letters a and b:

E.g. for n = 4, ordering:

```
AA AB AC AD
BB BC BD
CC CD
```

Corresponding formula:
$$
a \cdot n - \frac {(a-1)^2 + (a-1)} 2 + (b-a) = a \cdot n - \sum_{i=0}^{a-1}i + (b-a) = \sum_{i=26-1}^{26-a} i  + (b-a)
$$