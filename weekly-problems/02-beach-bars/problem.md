---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Beach Bars

You have always been daydreaming about opening a bar on a beach somewhere warm. But as you are still a reasonable person you would not just book a one way ticket to Hawaii and hope for the best. You need a business plan first.

You know from various papers on the economics of beach bars that no customer is ever going to walk more than 100m to get to your establishment.

As a first approximation to the number of potential customers you look at satellite images of various beaches and write down the number and position of the parasols that you can see. For this you represent the beach as a simple one-dimensional coordinate system (i.e. a line) where you choose the parking lot of the beach as the origin. Then the coordinate of each parasol is given by the distance along the beach from the parking lot in meters, using positive or negative numbers depending on whether the parasol is up or down the beach from the parking lot.

With this data at hand, all that remains to do is to identify the best possible locations for your bar. For each point on the beach you can compute how many parasols are at most 100m away from it and pick out all points that maximize this number. However you quickly realize that this leads to a large number of locations. You then decide that you further want to minimize the maximum distance that any of your potential customers (i.e. those within 100m) must walk.

Input The first line of the input contains the number $t \leqslant 40$ of test cases. Each test case is described as follows.

- It starts with a line that contains an integer $\mathrm{n}$ denoting the number of parasols, and such that $1 \leqslant n \leqslant 10^{6}$.

- The next line contains $n$ (not necessarily positive) integers $x_{0} \ldots x_{n-1}$, separated by a space, denoting the coordinates of the parasols, with $\left|x_{i}\right| \leqslant 10^{6}$. You can assume that no two parasols have the same coordinates.

**Output** A location $x$ on the beach can only have integer coordinates and is optimal if the number of parasols within 100m of it (i.e. with coordinates in $[x-100, x+100]$ ) is maximal with respect to all other locations on the beach. If many locations maximize the number of parasols we only want those such that the distance to the farthest parasol at most 100m away is minimized.

For each beach you have to print two lines. The first line must contain the maximum number of parasols and the minimal longest distance as above. The second line should contain the coordinates of all possible optimal locations for your bar sorted from low to high.

**Points** There are three groups of test sets, worth 100 points in total.

1. For the first group of test sets, worth 20 points, you may assume that $\left|x_{i}\right| \leqslant 10^{3}$ and $n \leqslant 10^{3}$.

2. For the second group of test sets, worth 20 points, you may assume that $n \leqslant 10^{3}$.

3. For the third group of test sets, worth 60 points, there are no additional assumptions.

Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3\}$.
