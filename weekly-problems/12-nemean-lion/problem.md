---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - The Nemean Lion

> First he cleared the grove of Zeus of a lion, and put its skin upon his back, hiding his yellow hair in its fearful tawny gaping jaws.

The first labor of Hercules is to hunt down a vicious lion that terrorizes the Argolic forests. In his struggles to track down the beast he approaches Pythia, the high priestess of the Oracle at Delphi, for help. As it tends to go with oracles, the hint he receives is not as helpful as hoped for: Look for a spot with two Platanos trees at a distance of 42 feet and no other Platanos tree any closer.

As there are many Platanos trees in Argolis, this seems to be a hopeless task. But Hercules is not one to easily give up and gets to work, regardless. With the help of Hermes ${ }^{2}$ he obtains a map of the area that shows the location of all relevant trees. He is convinced that this information should suffice to quite effectively narrow down the number of places that he has to visit in his search for the beast. He suspects that Hera $^{3}$, who is determined to see Hercules fail, had a hand in the oracle's prophecy, so as to make his work as hard as possible. "How would she select this distance?", he thinks, "It must not be too small, or there would be no solution. But once you have solutions, how many are there? And what is the maximum number of solutions possible?"

For simplicity, we consider the situation as seen from above on a map and model trees as points in the two-dimensional Euclidean plane $\mathbb{R}^{2}$. A spot is a point in the plane-anywhere, in or outside the (unspecified) Argolic Forests. Let $\mathcal{F}$ denote the set of Platanos trees in the Argolic Forests. A subset $\mathrm{T} \subseteq \mathcal{F}$ of trees is admissible for a distance $\mathrm{d} \in \mathbb{R}$ if there exists a spot $p$ such that every tree in $T$ has distance exactly $d$ to $p$, and every tree in $\mathcal{F}$ has distance at least $d$ to $p$. We are interested in the number of admissible sets of two or three trees for certain distances. You may assume that there exists (1) at least one admissible set of three trees for some distance but (2) no admissible set of four or more trees for any distance. Finally, in place of the fixed distance of 42 feet from the prophecy we consider the distance $\sqrt{s}$ to be a parameter of the problem.

Input The first line of the input contains the number $t \leqslant 30$ of test cases. Each of the $t$ test cases is described as follows.

- It starts with a line containing three integers $\mathrm{n} \mathrm{s}$ h, separated by a space. They denote
  - $s$, a given squared distance $\left(1 \leqslant s \leqslant 2^{50}\right)$; and
  - $h$, a hint for the first three groups of test sets $\left(0 \leqslant h \leqslant 10^{5}\right)$.

- The following $n$ lines define the positions of the trees in $\mathcal{F}$. Each position is described by two integers $x y$, separated by a space and such that $|x|,|y|<2^{24}$.

You may assume that the positions of the trees in $\mathcal{F}$ are pairwise distinct.

Output The output for each test case consists of a separate line containing four integers $a_{2} a_{3} a_{s} a_{\max }$, separated by a space. They denote

- $a_{k}$, the number of pairwise distinct admissible sets of size $k$ for $d_{k}$, where $k \in\{2,3\}$ and $d_{k}$ is the smallest distance $d \in \mathbb{R}$ so that the number of admissible sets of size $k$ for $d$ is strictly greater than zero;

- $a_{s}$, the number of pairwise distinct admissible sets of size two for the given distance $\sqrt{s}$; and

- $a_{\max }$, the maximum number of pairwise distinct admissible sets of size two for $\mathrm{d}$, over all distances $d \in \mathbb{R}$.

Points There are four groups of test sets. For each group there is also a corresponding hidden test set, each worth 5 points. Overall, you can achieve 100 points.

1. For the first group of test sets, worth 25 points, you may assume that $a_{3}, a_{s}$ and $a_{\max }$ are given $\left(a_{3}=1\right.$ and $\left.a_{s}=a_{\max }=h\right)$.

2. For the second group of test sets, worth 25 points, you may assume that $a_{s}$ and $a_{\max }$ are given $\left(a_{s}=a_{\max }=h\right)$.

3. For the third group of test sets, worth 15 points, you may assume that $a_{\max }$ is given $\left(a_{\max }=h\right)$

4. For the fourth group of test sets, worth 15 points, the parameter $h$ is useless $(h=0)$.

Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3,4\}$.

${ }^{1}$ Platanus orientalis is a deciduous tree that can grow to a height of $30 \mathrm{~m}$.

${ }^{2}$ In Greek mythology, Hermes is the herald of the gods, the protector of travellers, thieves, and merchants, the divine trickster, one of the twelve Olympians, and a son of Zeus.

${ }^{3}$ In Greek mythology, Hera is the goddess of women, marriage, family, childbirth, one of the twelve Olympians, and the wife of Zeus. $-n$, the number of trees in $\mathcal{F}\left(3 \leqslant n \leqslant 5 \cdot 10^{3}\right)$;