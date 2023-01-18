---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---


# Exercise - The Fighting Pits of Meereen

> "People love blood when it's not their own. But tavern brawls are boring, and wars never have good seating. Thus, the famed fighting pits of Meereen opened shortly after the city's own founding."

*Dario Naaharis, A Song of Ice and Fire by George R. R. Martin*

Meereen is the largest and most famous slaver city in the Slaver's Bay, known for its fighting pits which have been there since the city was founded. After Daenerys Stormborn of House Targaryen, the First of Her Name, Queen of the Andals and the First Men, Protector of the Seven Kingdoms, the Mother of Dragons, the Khaleesi of the Great Grass Sea, the Unburnt, the Breaker of Chains, conquers the city of Meereen, she abolishes slavery and closes the fighting pits for good. Hizdahr zo Loraq, an extremely wealthy noblemen, makes use of the situation that arises and buys all the fighting pits at a greatly reduced price.

While most of the people of Meereen accept Daenerys as the queen, one particular party of noblemen is aggressively opposing her, engaging in a "shadow war" against her. In order to put an end to this, Daenerys is pressured into marrying Hizdahr and reopening the fighting pits.

Hizdahr, now the owner of all of the fighting pits, wants the opening day to be majestic. In particular, the events need to be arranged so that the overall excitement of the audience is maximized. He orders you to design a schedule which achieves that.

The fighting pit has two entrances for the fighters: north and south. The fighters are lined up in a queue and are of several possible types—there are gladiators, lions, exotic animals, dwarves, even dragons! After all, everyone would enjoy seeing a dwarf facing a lion and the pathetic tries of the little creature to fight off the beast. The assignment of fighters to the entrances proceeds in rounds until the queue is depleted, where in each round you need to decide whether to send the fighter from the front of the queue to the north or to the south entrance.

The individual excitement of each round can then be measured as follows. The audience is usually somewhat drunk and can remember only the last $m$ fighters that came through each of the entrances. Thus, they look at the last $\min \{m, q\}$ fighters sent through the entrance used in this round (including the one you sent just now), where $q$ denotes the total number of fighters sent through that entrance so far, and they acquire an excitement of 1000 times the number of distinct types of fighters among those.

However, if the number of fighters coming through the entrances is in a large imbalance, the audience is not amused since it is rather repetitive seeing fighters coming through the same entrance too many times consecutively. As a result, the individual excitement of a round decreases by $2^{|p-q|}$, where $p$ and $q$ denote the number of fighters that have been sent to the two entrances up until (and including) this round, respectively.

Lastly, if the excitement of an individual round is negative the audience is outraged and starts a riot. Thus, as a last request from Hizdahr, the schedule needs to be such that there is no round whose individual excitement is negative.

Your task is to compute the maximum possible overall excitement, that is the maximum sum of individual excitements over all rounds, one can enforce with a given queue of fighters.

**Input** The first line of the input contains the number $t \leqslant 30$ of test cases. Each of the $t$ test cases is described as follows.

- It starts with a line that consists of three integers $n\ k\ m$, separated by a space. They denote
  - $n$, the number of fighters standing in the queue $\left(1 \leqslant n \leqslant 5 \cdot 10^{3}\right)$;
  - $k$, the number of different types of fighters $(2 \leqslant k \leqslant 4)$;
  - $m$, the number of fighters the audience can remember last being sent through each of the entrances $(2 \leqslant m \leqslant 3)$.


- The following $n$ lines define the fighters. The $i$-th such line consists of an integer $x$, $x \in\{0,1, \ldots, k-1\}$, denoting the type of the i-th fighter in the queue.

**Output** For each test case output a single line that consists of a single integer denoting the maximum overall excitement one can achieve given the current queue of fighters.

**Points** There are four groups of test sets, each of which is worth 25 points. So, there are $4 \cdot 25=100$ points in total.

1. For the first group of test sets you may assume that $n \leqslant 200, m=2$, and that there are only two types of fighters, i.e. $k=2$. Additionally, the queue is such that there is no fighter which is both preceded and followed by fighters of the other type.

2. For the second group of test sets you may assume that $n \leqslant 200$ and $m=2$.

3. For the third group of test sets you may assume that $n \leqslant 200$.

4. For the fourth group of test sets there are no additional assumptions.

Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3,4\}$.

**Sample Input**

```
4
1 2 2
0
2 2 2
0
1
5 2 2
0
0
1
1
1
6 4 3
0
2
1
3
1
2
```

**Sample Output**

```
998
2994
6992
13874
```



