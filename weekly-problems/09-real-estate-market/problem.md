---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Real Estate Market

In Algoland the housing market is booming. Property prices are skyrocketing and ALGO (the All Land Governing Organization) decided to sell some of their sites to the highest bidder. They publicly announced all the $M$ pieces of land that they want to sell and $N$ potential buyers submitted their bids. Every buyer is interested in buying at most one piece of land and submitted a bid for all of the $M$ sites (but they might bid just one franc if they are really not interested in a piece and hope for a bargain).

You now want to maximize ALGO's profit and have to decide who gets which piece of land. But be aware of the state legislations! Depending on which state of Algoland the sites lie, you might not be allowed to sell all of them. To avoid hoarding by big real estate brokers, each of the $\mathrm{S}$ states in Algoland recently passed a new law that specifies a maximum number of sites that ALGO is allowed to sell in that state.

**Input** The first line of the input contains the number of test cases $T$. Each of the $T$ test cases is described as follows.

- It starts with a line that contains three integers $\mathrm{N} \mathrm{M} \mathrm{S}$, separated by a space and such that $1 \leqslant N \leqslant 100,1 \leqslant M \leqslant 100$ and $1 \leqslant S \leqslant M$. $N$ denotes the number of interested buyers, $M$ the number of sites that ALGO owns and $S$ the number of states in Algoland.

- The second line contains $S$ space separated integers. These numbers $l_{1}, \ldots, l_{S}$ denote the limits on the number of sites that can be sold in state $i$. We have $0 \leqslant l_{i} \leqslant N$ for all $i$.

- The third line contains $M$ space separated integers. These numbers $s_{1}, \ldots, s_{M}$ denote to which state each site belongs to. Site $j$ belongs to state $s_{j}$, so we have $1 \leqslant s_{j} \leqslant S$ for all $j$.

- The remaining $\mathrm{N}$ lines of each test case contain the bids, one potential buyer per line. The $i$-th of these lines contains the bids of the $i$-th potential buyer for all the sites represented as $M$ numbers $b_{i, 1}, \ldots, b_{i, M}$. We have $1 \leqslant b_{i, j} \leqslant 100$ for all $i$ and $j$.

**Output** For each test case output a line with two integers $c$ and $p$, the optimum number of sites sold and the maximum profit.

**Points** There are five groups of test sets, worth 20 points each.

1. For the first group of test sets, you may assume that $N=M, S=1, l_{1}=N$ and $N \cdot M \leqslant 10^{3}$.

2. For the second group of test sets, you may assume that $S=1, l_{1}=N$ and $N \cdot M \leqslant 10^{3}$.

3. For the third group of test sets, you may assume that $S=1$ and $N \cdot M \leqslant 10^{3}$.

4. For the fourth group of test sets, you may assume that $N \cdot M \leqslant 10^{3}$.

5. For the fifth group of test sets there are no additional assumptions.

Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3,4,5\}$. 