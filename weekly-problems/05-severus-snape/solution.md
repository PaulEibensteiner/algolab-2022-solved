# Solution

## Problem in a Nutshell

Given: Multiset $A$ of size $n \leq 100$ with elements $(p_i\leq2^{31}, h_i\leq2^{10})$, set $B$ of size $m \leq 100$ with elements $w_i \leq 2^{31}$, integers $P,H,W, a, b$. Find subset $B_s$ of $B$ and subset $A_s$ of $A$ with minimum total size, s.t.:
$$
\sum_{p_i \in A_s} p_i - \sum_{w_j \in B_s} b \geq P \\
\sum_{h_i \in A_s} h_i \geq H \\
\sum_{w_j \in B_s} w_j - \sum_{p_i \in A_s} a \geq W \\
$$

## Solution

1. Calculate a table, that contains for every number of potions from $A$ used, and every sum of $h_i$ they can form the maximum amount of $P$ possible.
2. Sort $B$ by $w_i$
3. Iterate through sorted $B$ and calculate the amount of $P$ necessary with the deductions of $b$. Also calculate the maximum amount of $As$ possible, that are accumulated by the $w_j$. Then check in the table, if for any amount of $As$ that are possible, they create more then the necessary $P$

