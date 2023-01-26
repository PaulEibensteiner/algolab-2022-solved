---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - The Augean Stables

> "The flies, filth, and stench were overwhelming and seemed to affect everyone but King Augeas."

*The Mythology of the Night Sky by David E. Falkner*

For his fifth labor, Hercules has been tasked to clean up King Augeas' filthy stables in a single day. These stables have not been cleaned in over thirty years and over three thousand cattle heads live there. As such, the assignment is considered humiliating—rather than impressive, like the previous labors—and also impossible.

The stables are divided into $n$ individual stalls. The i-th stall currently contains a certain amount $f_{i}$ of filth, which needs to be reduced to a smaller amount of at most $c_{i}$ for the stall to be considered clean. With no wish to humiliate himself by either carrying the dung out of the stalls by hand or by failing at this immense task completely, Hercules identifies three crucial positions on the walls of the stables where he plans to knock holes and then let water flow through, carrying all of the accumulated filth with it. Figuring out the ideal size of the three holes-so that enough water flows through each stall to wash it clean—is the task at hand.

For each stall, Hercules notes down three numbers $k_{i}, \ell_{i}, m_{i}$. He estimates that the amount of filth removed from the $i$-th stall can be expressed as the weighted sum $h_{1} k_{i}+h_{2} l_{i}+h_{3} m_{i}$, where $h_{1}, h_{2}, h_{3}$ are freely selectable real numbers between 0 and 1 that measure the respective sizes of the three holes to be made. Note that some of the numbers $k_{i}, l_{i}, m_{i}$ may in fact be negative, since one of the holes might divert water away from a stall or maybe because the filth from a neighboring stall is brought in.

Unfortunately, the local water supply might be insufficient for the task. Hercules thus considers digging trenches to two nearby rivers, which are called Alpheius and Peneius. For simplicity, we assume that Hercules may spend any whole number of hours from 0 to 24 working on each trench, where every added hour of work redirects an additional amount of the respective river's water flow towards the stables. Let $a$ and $p$ be the total amount of water flow redirected thusly from Alpheius and Peneius, respectively. According to Hercules' estimations, this increases the numbers $k_{i}, l_{i}, m_{i}$ from before according to the rules

$$
k_{i}^{\prime}=k_{i}+a^{2}, \quad l_{i}^{\prime}=l_{i}+p^{2}, \quad m_{i}^{\prime}=m_{i}+a p .
$$

Is there a way for Hercules to clean all stalls, possibly by making use of redirected water from the two rivers? If so, what is the minimum number of hours needed to work on both trenches?

**Input** The first line of the input contains the number $t \leqslant 30$ of test cases. Each of the $t$ test cases is described as follows.

- It starts with a line containing one integer $n$, where $n$ denotes the number of individual stalls in the stables $(1 \leqslant n \leqslant 100)$.

- The following $n$ lines define the individual stalls. The i-th such line contains five integers $f\ c\ k\ l\ m$, separated by a space. They denote the initial amount $f_{i}$ of filth in the $i$-th stall $\left(0 \leqslant f_{i}<2^{25}\right)$, the maximum allowable amount $c_{i}$ of filth for it to be considered clean $\left(0 \leqslant c_{i} \leqslant f_{i}\right)$, and the numbers $k_{i}, l_{i}, m_{i}$ as explained above $\left(\left|k_{i}\right|,\left|l_{i}\right|,\left|m_{i}\right|<2^{25}\right)$.

- The following line contains 24 integers $a_{1} a_{2} \ldots a_{24}$, separated by a space, where $a_{i}$ denotes the additional amount of water flow redirected from the river Alpheius if Hercules spends an additional $i$-th hour working on the corresponding trench $\left(0 \leqslant a_{i}<2^{25}\right)$.

- The following line contains 24 integers $p_{1} p_{2} \ldots p_{24}$, separated by a space, where $p_{i}$ denotes the additional amount of water flow redirected from the river Peneius if Hercules spends an additional $i$-th hour working on the corresponding trench $\left(0 \leqslant p_{i}<2^{25}\right)$.

For example, if Hercules works three hours on Alpheius' trench and no hours at all on Peneius' trench, then the respective amounts of redirected water flow are $a=a_{1}+a_{2}+a_{3}$ and $p=0$.

**Output** For each test case the corresponding output appears on a separate line. If even after working for 24 hours on each trench (i.e., after $2 \times 24=48$ hours in total) there remains a stall that is not clean, the output is `Impossible!`. Otherwise, the output is the smallest (integral) number of hours required to work on both trenches such that the stalls can be made clean.

**Points** There are four groups of test sets. For each group there is also a corresponding hidden test set, each worth 5 points. Overall, you can achieve 100 points.

1. For the first group of test sets, worth 25 points, you may assume that $n \leqslant 50$ and that working on either trench has no effect $\left(a_{i}=p_{i}=0\right.$ for all $\left.i>0\right)$.
2. For the second group of test sets, worth 25 points, you may assume that $n \leqslant 80$ and that working for more than four hours on either trench has no additional effect $\left(a_{i}=p_{i}=0\right.$ for all $i>4$ ).
3. For the third group of test sets, worth 20 points, you may assume that $n \leqslant 80$ and that working for more than sixteen hours on either trench has no additional effect $\left(a_{i}=p_{i}=0\right.$ for all $i>16)$.
4. For the fourth group of test sets, worth 10 points, there are no additional assumptions.

Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3,4\}$.