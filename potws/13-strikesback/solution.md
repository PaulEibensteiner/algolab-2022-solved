# Solution

## Problem in a nutshell

Given are three point sets $A, S, B$, one sum of energies $e$ and a density $k_a$ for every point $a$ in $A$. Can we choose a (squared) radius $r^2_s$ and an energy $e_s$ for every point $s$ in $S$ s.t.
$$
\sum_{s \in S} e_s \leq e \\
\forall a \in A:\sum_{\forall s \in S :d^2(a, s) \leq r_s^2} \frac {e_s} {\max(1, d^2(a, s))} \geq k_a \\
\forall b \in B: \forall s \in S: d^2(b, s) > r^2_s
$$
where $d^2(p, p')$ is the squared distance between two points $p, p'$

## Basic Idea

1. Calculate maximum radiii by creating a triangulation of $B$ and calculating the nearest neighbor for every point in $S$
2. Since radii are not constrained in any other way, we can just set them to their respective maximum values
3. For all points in $A$ find the subset of $S$ in who‘s range it is. Simply possible with double loop because $\max |A| = 30$
4. Create linear program with energy as variables and inequality constraints as given by the first two lines in math above.

## Challenges

Debugging linear programs