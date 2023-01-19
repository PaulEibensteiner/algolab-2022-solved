---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Revenge of the Sith

Chancellor Sheev Palpatine of the Galactic Republic is about to become the Emperor. He takes control of planet by planet while nobody can resist his army of clone troopers. The Jedi Council's hopes rest on you to plant the seeds of resistance and bring together an as large as possible group of planets to eventually stand up and provide opposition.

You travel on a small short-range scout, hoping to evade the massive enemy forces. You may choose the starting planet of your expedition as you want. This planet secretly pledges to you and becomes the seed of the Rebel Alliance. Then every day you will start from some planet of your choice that secretly pledges to the Rebels and travel to some planet nearby in order to convince the local population to join the Rebels as well. This always succeeds and results in the planet's secret pledge to the Rebels.

But every day also Palpatine's army incorporates one planet into the ever growing Empire. Your efforts are fragile: You cannot visit planets that are part of the Empire already. Worse even, should you visit a planet and later the Empire's army takes it over, then Palpatine learns of your secret alliance and makes sure to dismantle it before it can take off.

While your task sounds like a mission impossible, you have one advantage: The Council's intelligence obtained a complete schedule of the Empire's conquering expedition. That is, you know exactly the order in which the Empire visits the planets (of course, all planets are scheduled to become part of Empire sooner or later).

At any day you may choose to stop gathering support and instead reveal yourself and the Rebel Alliance. Let us hope that enough planets have pledged to it then in order to give the Rebels a fighting chance...

**Input** The first line of the input contains the number $t \leqslant 30$ of test cases. Each of the $t$ test cases is described as follows.

- It starts with a line that contains two integers $n\ r$, separated by a space. They denote
  - $n$, the number of planets $\left(2 \leqslant n \leqslant 3 \cdot 10^{4}\right)$ and
  - $r$, the operation range of the scout vessel $\left(0 \leqslant r<2^{24}\right)$.


- The following $n$ lines define both the individual positions $p_{0}, \ldots, p_{n-1}$ of the planets and collectively the order in which they are visited on the Empire's conquering expedition (first $p_{0}$, then $p_{1}$, etc.). Each position is described by two integer coordinates $x\ y$, separated by a space and such that $|x|,|y|<2^{24}$. You may assume that these positions are pairwise distinct.

**Output** For each test case output a line with one positive integer $k$ that is the maximum number of planets in the Rebel Alliance, as defined below.

For every test case $p_{0}, \ldots, p_{n-1}$ you can select $k$ and a sequence $r_{0}, \ldots, r_{k-1}$ of pairwise distinct planets from $\left\{p_{k}, p_{k+1}, \ldots, p_{n-1}\right\}$ to visit. (The planets $p_{k}, p_{k+1}, \ldots, p_{n-1}$ are those that are not yet conquered by the Empire after $k$ days.) The planets $r_{0}, \ldots, r_{k-1}$ must be reachable using your scout vessel, that is, for every $j \in\{1, \ldots, k-1\}$ there exists some $i \in\{0, \ldots, j-1\}$ with $\left\|r_{j}-r_{i}\right\| \leqslant r$. Then the $k$ planets $r_{0}, \ldots, r_{k-1}$ are in the Rebel Alliance.

**Points** There are four groups of test sets, each of which is worth 25 points. So, there are $4 \cdot 25=100$ points in total.

1. For the first group of test sets, you may assume that $n \leqslant 8 \cdot 10^{2}$.

2. For the second group of test sets you may assume that $n \leqslant 1.8 \cdot 10^{3}$.

3. For the third group of test sets you may assume that $n \leqslant 8 \cdot 10^{3}$.

4. For the fourth group of test sets there are no additional assumptions.

Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3,4\}$.
