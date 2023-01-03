---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Severus Snape

>  "My word, Severus, that I shall never reveal the best of you?" Dumbledore sighed, looking down into Snape's ferocious, anguished face. "If you insist..."

*Harry Potter and the Deathly Hallows by J. K. Rowling*

The Triwizard Tournament, the most deadly magical contest, is held at Hogwarts this year. The Third Task of the Tournament is tomorrow and Harry must participate against his will, since the Goblet of Fire spat out his name. This was unexpected—he had not entered his name in it, but the Goblet's choice constitutes a magical contract which Harry cannot back out of.

Severus Snape, a former Death Eater and Harry's least favorite Hogwarts professor, is in fact secretly a double agent for Dumbledore, trying to undermine Lord Voldemort and protect Harry. He suspects there is something off in the whole situation with Harry's name coming out of the Goblet of Fire, and thinks it's highly likely that Voldemort is involved. Thus, he wants to help Harry be as prepared as he can for whatever may unfold tomorrow. The golden opportunity to do this is today's Potions class, which Snape is teaching.

With his impeccable magical intuition, Snape correctly predicts the attributes Harry will need for the challenges tomorrow: magical power, happiness, and wit. Snape suspects Harry will need wit to cope with the Third Task of the Tournament, happy memories to cast the Patronus Charm in case he runs into Dementors, and magical power to fight Voldemort if this becomes necessary. To boost Harry's magical power, happiness, and wit, Snape can give him some potions in today's class. Unfortunately, potions can have negative side effects—a potion that boosts one or two of the three attributes, may weaken another. What complicates matters even more is that Snape must remain undercover and, hence, in order to not raise any suspicion, cannot give Harry too many potions. Help Snape pick a subset of as few potions as possible that will sufficiently boost Harry's attributes.

Snape suspects that Harry will need at least $P$ magical power, $H$ happiness, and $W$ wit. Harry starts out having 0 power, 0 happiness, and 0 wit, and each potion he drinks increases or decreases these attributes by some amount. Snape has two types of potions at his disposal: type A and type B. Potions of type A boost Harry's magical power and happiness, but weaken his wit. Different potions of type A increase his magical power and happiness by possibly different amounts. Each potion of type A decreases Harry's wit by exactly a. Potions of type B boost Harry's wit but weaken his magical power, and do not affect his happiness. Different potions of type B increase his wit by possibly different amounts. Each potion of type B decreases Harry's magical power by exactly $b$. It is possible that after drinking only a subset of the potions given to him by Snape, Harry has negative power or negative wit, and that is not a problem.

**Input** The first line of the input contains the number $t \leqslant 30$ of test cases. Each of the $t$ test cases is described as follows.

- It starts with a line that contains two integers $n\ m$, separated by a space, denoting the number of potions of type $A(1 \leqslant n \leqslant 100)$ and the number of potions of type $B(1 \leqslant$ $m \leqslant 100)$ at Snape's disposal.

- The following line contains two integers $a\ b$, separated by a space, denoting the wit Harry loses with each potion of type $A$ he drinks $\left(0 \leqslant a<2^{31}\right)$ and the magical power Harry loses with each potion of type $B$ he drinks $\left(0 \leqslant b<2^{31}\right)$.

- The following line contains three integers $P H W$, separated by a space, denoting the magical power Harry needs $\left(1 \leqslant P<2^{31}\right)$, the happiness he needs $\left(1 \leqslant H \leqslant 2^{10}\right)$, and the wit he needs $\left(1 \leqslant W<2^{31}\right)$.

- The following $n$ lines each describe a potion of type $A$. The $i$-th such line contains two integers $p_{i} h_{i}$, separated by a space, denoting the magical power $\left(1 \leqslant p_{i}<2^{31}\right)$ and the happiness $\left(1 \leqslant h_{i} \leqslant 2^{10}\right)$ Harry can get from the $i$-th potion of type $A$.

- The following $m$ lines each describe a potion of type $B$. The $j$-th such line contains an integer $w_{j}$ denoting the wit $\left(1 \leqslant w_{j}<2^{31}\right)$ Harry can get from the $j$-th potion of type $B$.

**Output** For each test case, output a single line that consists of a single integer denoting the minimum number of potions necessary to boost Harry's magical power, happiness, and wit to (at least) the required levels, or $-1$ if no subset of potions can do that.

**Points** There are four groups of test sets, worth 100 points in total.

1. For the first group of test sets, worth 30 points, you may assume that each potion of type A gives Harry as much magical power as it gives him happiness $\left(p_{i}=h_{i}\right.$, for every $i \in\{1, \ldots, n\})$, potions of type A do not decrease Harry's wit $(a=0)$, and potions of type B do not decrease Harry's magical power $(b=0)$.

2. For the second group of test sets, worth 30 points, you may assume that potions of type A do not decrease Harry's wit $(a=0)$ and potions of type $B$ do not decrease Harry's magical power $(b=0)$.

3. For the third group of test sets, worth 20 points, you may assume that potions of type A do not decrease Harry's wit $(a=0)$.

4. For the fourth group of test sets, worth 20 points, there are no additional assumptions. Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3,4\}$.
