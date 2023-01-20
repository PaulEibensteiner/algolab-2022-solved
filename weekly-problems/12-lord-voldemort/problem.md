---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Lord Voldemort

> "Wouldn't it be better, make you stronger, to have your soul in more pieces, I mean, for instance, isn't seven the most powerfully magical number, wouldn't seven-?", Tom Marvolo Riddle

*Harry Potter and the Half-Blood Prince by J. K. Rowling*

Harry Potter, together with his friends Ron and Hermione, and the other members of Dumbledore's Army, is at war with Lord Voldemort, the most vicious dark wizard of all times. Voldemort, determined to attain immortality at any cost, has hidden fragments of his soul into a number of objects, thereby turning them into Horcruxes. The only way he can be defeated is if all Horcruxes are destroyed first.

Harry, Ron and Hermione have found all the Horcruxes and lined them up on the ground. The other members of Dumbledore's Army now have to destroy as many Horcruxes as they can. They may not be able to destroy all Horcruxes today, since destroying Horcruxes takes magical power, of which each wizard has a limited amount for each day. Whichever Horcruxes remain will be handled by Harry, Ron and Hermione tomorrow, since they have already used up all their magical power for today when looking for the Horcruxes. Your task is to determine the maximum number of Horcruxes that can be destroyed by the other members of Dumbledore's Army today.

Apart from Harry, Ron and Hermione, there are $m$ other members of Dumbledore's Army, each of whom has $k$ magical power left for today. Recall that Harry, Ron and Hermione have no magical power left for today. There are $n$ Horcruxes, arranged in a straight line on the ground and indexed 0 through $n-1$ from left to right. The $i$-th Horcrux has $v_{i}$ amount of evil in it, which means that it takes $v_{i}$ magical power to be destroyed. Each member of Dumbledore's Army must be assigned to destroy a non-empty contiguous sequence of Horcruxes, so as to liquidate them all by casting just one single spell. The total evil in the Horcruxes in any such sequence must be exactly $k$ - a member of Dumbledore's Army has precisely $k$ magical power for today, and their pride would not allow them to spend less than that. Again for reasons of honour and pride, all members of Dumbledore's Army with remaining magical power for today must contribute, and no Horcrux can be assigned to more than one member.

Your task is to design a strategy for destroying as many Horcruxes as possible today, complying with all the requirements outlined above. Formally, a permissible strategy is a choice of disjoint intervals $\left[a_{0}, b_{0}\right], \ldots,\left[a_{m-1}, b_{m-1}\right]$ (where $\left[a_{i}, b_{i}\right]$ is the segment of Horcruxes destroyed by the $i$-th member of Dumbledore's Army) with the property that the sum $\sum_{j=a_{i}}^{b_{i}} v_{j}$ of the evil in the Horcruxes in each segment $\left[a_{i}, b_{i}\right]$ is equal to $k$, the magical power of a member of Dumbledore's army. The effect of a strategy is the total number $\sum_{i=0}^{m-1}\left(b_{i}-a_{i}+1\right)$ of destroyed Horcruxes. Find the maximum possible effect of a permissible strategy.

**Input** The first line of the input contains the number $t \leqslant 300$ of test cases. Each of the $t$ test cases is described as follows.

- It starts with a line that contains three integers $n\ m\ k$, separated by a space. They denote
  - $n$, the number of Horcruxes $\left(1 \leqslant n \leqslant 10^{5}\right)$;

  - $m$, the number of members of Dumbledore's Army, other than Harry, Ron and Hermione $(1 \leqslant m \leqslant 100)$

  - $k$, the magical power that each member of Dumbledore's Army, other than Harry, Ron and Hermione, has for today $\left(1 \leqslant k<10^{9}\right)$.

- The following line defines the amount of evil in each Horcrux. It contains $n$ integers $v_{0} \ldots v_{n-1}$, separated by a space, and such that $1 \leqslant v_{i}<10^{4}$, for all $i \in\{0, \ldots, n-1\}$. Here $v_{i}$ denotes the amount of evil in the $i$-th Horcrux.

**Output** For each test case output one line that contains either a single integer that denotes the maximum effect of a permissible strategy, or the string `fail`, if no permissible strategy exists.

**Points** There are five groups of test sets, worth 20 points each. So, you can achieve $5 \cdot 20=100$ points overall.

1. For the first group of test sets you may assume $n \leqslant 300$ and $m=2$.

2. For the second group of test sets you may assume $n \leqslant 3000$ and $m=2$.

3. For the third group of test sets you may assume $m \leqslant 2$.

4. For the fourth group of test sets you may assume $n \leqslant 1000$.

5. For the fifth group of test sets there are no additional assumptions.

Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3,4,5\}$.
