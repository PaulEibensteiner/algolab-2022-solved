---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Germs

Microbactus solitarius is a very interesting type of organism: it grows as long as it lives, but it dies immediately as soon as something impedes its growing. In Labland they plan to run experiments to find out how long these bacteria live under certain circumstances. However, the plans stalled as soon as the national ethics commission heard of it, because any experiments on living organisms come under very close scrutiny. As of yet it is unclear whether these experiments will be allowed eventually, and there is not even a timeframe known when such a decision will be made. Therefore, it is currently being considered whether computer simulations form a viable alternative. This is where you come into play...

The setup is as follows. An initial configuration of bacteria is placed in a rectangular dish. Bacteria are modeled as disks, whose initial radius is $0.5 \mu \mathrm{m}$. Each bacterium grows such that its center remains stationary and its radius grows quadratically, described by the function $\rho(t)=t^{2}+\frac{1}{2}$, where $t$ is the time (measured in hours) that passed since the start of the simulation. For instance, after one hour the radius is $1.5 \mu \mathrm{m}$ and after two hours the radius is $4.5 \mu \mathrm{m}$. In the very moment a bacterium touches another bacterium or the outer boundary of the dish, it dies.

A dead bacterium stays where it is. In particular, it continues to be an obstacle to the growth (and life) of other bacteria. In principle, a dead bacterium would remain at the same size it had the moment it died. But for a first prototype of the simulation software, we consider a simplified model: We pretend that bacteria continue to grow, regardless of whether they are alive or not. In other words, in this model bacteria can grow "through" each other and even extend beyond the boundary of the dish. Of course, this is a somewhat unrealistic setup. But it will serve its purpose for a first prototype...

**Input** The input contains several test cases. Each of them is described as follows.

- It starts with a line that contains a single integer $n\left(1 \leqslant n \leqslant 10^{5}\right)$, denoting the number of bacteria.

- The next line describes the dish by four integers $l\ b\ r \ t$, with $|\mathrm{l},| \mathrm{b}|,| \mathrm{r}|,| \mathrm{t}|<2^{25}$. The dish consists of all points $(x, y)$, for which $l \leqslant x \leqslant r$ and $b \leqslant y \leqslant t$.

- The following $n$ lines describe the position of the bacteria, given by the integer coordinates of their centers $x y$, separated by space and so that $|x|,|y|<2^{24}$. You may assume that all bacteria are located within the dish and they are at pairwise distinct positions.

The input is terminated by a line containing a single value 0 . All coordinates are measured in $\mu \mathrm{m}$.

**Output** For every test case the corresponding output appears on a single line consisting of three non-negative integers $f \ m\ l$, where

- $f$ denotes the moment in which the first bacterium dies,

- $m$ denotes the moment in which the amount of bacteria still alive goes below $50 \%$

- $l$ denotes the moment in which the last bacterium dies.

All three output numbers are to be given in hours and possibly rounded up, that is, if the particular moment falls into the interval $(m, m+1]$, for some non-negative integer $m$, then output the number $m+1$. The terms "die" and "alive" refer to our simulation using the simplified model, as described above.
