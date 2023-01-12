# Solution

Create a flow graph, where stations are vertices, and edges between consecutive stations are of capacity $l$ and with cost 0. Create edges for each mission, with capacity one and cost $q$, and create a sink vertex, with an extra edge of capacity $l$ and cost 0.

Now the challenge is that we need a max flow max cost instead of min cost. To get this working, notice that $\sum_e \text{flow} (e) \cdot \text{length}(e) = l \cdot n$, because between vertices the flow must be $l$ and there are $n+1$ vertices now. Now this helps us to reformulate the flow problem without negative edges. $f(e)$ is the flow, $q(e)$ the priority, $k(e)$ it’s length (number of stations it spans):
$$
\max \sum_e f(e)+q(e) = \\
- \min \sum_e -f(e) \cdot q(e) = \\
ln2^7 -\min ln2^7 -\sum_e f(e) \cdot q(e) = \\
ln2^7 - \min 2^7\sum_e f(e) \cdot k(e) -\sum_e f(e) \cdot q(e) = \\
ln2^7 - \min \sum_e f(e) \cdot \big(2^7 k(e) - q(e)\big)
$$
Now, we can use $2^7 - q(e)$ as the edge costs and thus solve the problem without negative weigths, since $q(e) < 2^7$ and $k(e) \geq 1$.