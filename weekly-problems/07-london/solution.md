# Solution

## Basic Idea

For each position in the newspaper, one unit of flow can go from the source to either the front side letter or the backside letter. Then, from either letter, a flow equal to the amount of ocurrences of the letter in the message goes to the sink. Now maximum flow must be equal to the message's length, if it is possible.

This can be further optimized, because each position in the newspaper with the same backside / backside letter combination is equivalent. So we only need 26 choose 2 nodes, and add up the respective in and outgoing edges.

Still not working though