---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Rubeus Hagrid

> "Ah, well, people can be stupid abou' their pets", said Hagrid wisely. Buckbeak spat a few ferret bones onto Hagrid's pillow.

*Harry Potter and the Prisoner of Azkaban by J. K. Rowling*

After several mishaps during his Care of Magical Creatures lectures, some of them ending in students getting seriously injured, Hagrid finally opted for presenting tamer creatures next: nifflers. Nifflers are cute looking fluffy creatures with a long snout similar to that of a platypus. They are attracted to shiny objects and thus primarily used by goblins to burrow for treasure.

For the purpose of a lecture, Hagrid has buried a bunch of galleons made out of leprechaun gold into previously dug chambers below the ground. He has built a network of two-way tunnels of various lengths and has left a single entry point to this network on the surface. Each tunnel connects either two distinct chambers or the entry point and some chamber. The chambers and tunnels have been purposefully arranged so that from every chamber there is a unique sequence of tunnels leading up to the surface.

Hagrid plans to introduce the nifflers to the class and then organize a competition. Each student is to choose a niffler and release it into the underground network through the entry point on the surface with the goal to dig out as many galleons as possible. The student whose niffler digs out the most galleons wins a huge slab of chocolate from Honeydukes.

Of course, not everything is as simple as it sounds. As leprechaun gold has a disappearing "quality", in every second that passes after a niffler is released underground, one galleon disappears from each non-empty chamber simultaneously. The nifflers are known to be quick creatures which never rest and travel at one meter per second. Once a niffler reaches a chamber it immediately picks up all the galleons left in that chamber and places them into its pouch; from then on these galleons cannot disappear. Note that if a niffler arrives at some chamber $x$ seconds after being released underground, then $x$ galleons have already disappeared from this chamber at the moment of the niffer's arrival. Nifflers are very fast at picking up galleons and traversing chambers—these actions take them practically 0 seconds. Lastly, a niffler will only go through a tunnel at most twice (once in every direction), will visit all the chambers (too attracted to shiny objects), and has to exit back to the surface once it is done collecting.

Nifflers are not regarded as highly intelligent and so they each have an undetermined way of searching for gold. Yet, some are really clever and can figure out the best possible searching strategy. If only a single niffler is released, what is the maximum possible number of leprechaun gold galleons it can dig out? To keep even the most stupid niffler motivated, Hagrid has made sure to bury enough gold in all the chambers. Namely, whenever a niffler reaches some chamber for the first time there will be at least one galleon left in it to be picked up.

**Input** The first line of the input contains the number $t \leqslant 30$ of test cases. Each of the $t$ test cases is described as follows.

- It starts with a line that consists of a single integer $n$ denoting the number of chambers Hagrid has dug below the ground $\left(2 \leqslant n \leqslant 5 \cdot 10^{4}\right)$.

- The following line consists of $n$ integers $g_{1} g_{2} \ldots g_{n}$, separated by a space, denoting the number of galleons buried in the $i$-th chamber $\left(1 \leqslant g_{i}<2^{31}\right)$.

- The following $n$ lines define the tunnels. The $i$-th such line consists of three integers $u\ v\ l,$ separated by a space, denoting the two chambers it connects $(0 \leqslant u<v \leqslant n)$ and the length of the tunnel in meters $\left(1 \leqslant \ell \leqslant 2^{8}\right)$. You may assume that $u$ is strictly closer to the surface than $v$, in terms of the number of tunnels needed to reach the entry point. If $u=0$, the tunnel connects the entry point on the surface (labeled 0 ) to the chamber $v$.

**Output** For each test case output a single line with the maximum number of galleons a single niffler can dig out once released into the underground network.

**Points** There are four groups of test sets. For each group there is also a corresponding hidden test set. Overall, you can achieve 100 points.

Let $c$ be either the entry point or a chamber and let $d_{1}, \ldots, d_{k}$ be the chambers directly connected to $c$ via tunnels so that $c$ is strictly closer to the surface than any $d_{i}$. An underground network of tunnels is said to be balanced if for every such $c$ the number of chambers reachable from $d_{i}$ without going through $c$ is exactly the same for all $i \in\{1, \ldots, k\}$.

1. For the first group of test sets, worth 25 points, and for the corresponding hidden test set, worth 5 points, you may assume that $n \leqslant 10^{3}$, the underground network of tunnels is balanced, the entry point has exactly two tunnels leading to/from it, and every chamber has at most three tunnels leading to/from it.

2. For the second group of test sets, worth 25 points, and for the corresponding hidden test set, worth 5 points, you may assume that the underground network of tunnels is balanced, the entry point has exactly two tunnels leading to/from it, and every chamber has at most three tunnels leading to/from it.

3. For the third group of test sets, worth 25 points, and for the corresponding hidden test set, worth 5 points, you may assume that the underground network of tunnels is balanced.

4. For the fourth group of test sets, worth 5 points, and for the corresponding hidden test set, worth 5 points, there are no additional assumptions.

Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3,4\}$.
