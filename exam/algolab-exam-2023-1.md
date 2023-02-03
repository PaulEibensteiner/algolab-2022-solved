# Algorithms Lab Exam January 2023

*First Part*

## Exercise - Schneewittchen

> "Spieglein, Spieglein, an der Wand, wer ist die Schönste im ganzen Land?"

> "Looking-glass upon the wall, who is fairest of us all?"

*Kinder- und Hausmärchen by Jacob Grimm (1785-1863) and Wilhelm Grimm (1786-1859)*

Once upon a time, there was a beautiful princess named Snow-white. But alas, poor Snow-white was in grave danger. The wicked Queen, who was jealous of Snow-white's beauty, had a magic mirror that told her where the child was. The Queen set out to kill Snow-white. Fortunately, Snow-white had the seven dwarfs, who were determined to keep her safe. And so, they hatched a plan. They would build a new magic mirror for the Queen, one that would not divulge the whereabouts of Snow-white, and secretly exchange the mirrors the next night. Thus, the Queen would no longer be able to find Snow-white, and the child would be safe once more.

So they went about to acquire the raw materials for the mirror. Perchance, these could be mined from the nearby mountain. The dwarfs knew this mountain like the back of their hands. There were $n$ mines, one of which was the entry of the mountain. For each mine the dwarfs knew the minerals available there. The mines were connected by railway tracks. Each track connected two mines, and from each mine there was a unique sequence of tracks to reach the entry. To collect the minerals they transported them to the entry using the railways. But some of the mines—luckily, only very few—were dangerous. Whenever a railcar passed through a dangerous mine, half o f its contents got lost. Furthermore, a dangerous mine would collapse if the total amount of minerals that enter it throughout the whole process was strictly larger than a certain danger threshold. A collapse had to be avoided at all costs.

Finally, there was a mineral shop in their village. The shop had a limited supply $s_{j}$ for a price per unit $p_{j}$ of the mineral $j$, for $j \in\{0, \ldots, m-1\}$. The dwarfs would try to get enough minerals combining the mines and the shop. They minimized the price they had to pay at the shop by carefully picking the minerals collected from the mountain. Could they obtain all the minerals they needed? If yes, how much did they have to pay?

**Input** The first line of the input contains the number $t \leqslant 30$ of test cases. Each of the $t$ test cases is described as follows.

- It starts with a line containing two integers $n\ m$, separated by a space. They denote 
  - $n$, the number of mines $\left(1 \leqslant n \leqslant 10^{3}\right)$ and
  - $m$, the number of minerals $(1 \leqslant m \leqslant 5)$.


- The following $n$ lines describe the mines. The first line corresponds to the entry. Each line contains $m+1$ integers $d\ r_{0} \ldots r_{m-1}$, separated by a space. They denote $d$, the danger threshold $\left(-1 \leqslant d<2^{28}\right)$, and $r_{j}$, the quantity of mineral $j$ available $\left(0 \leqslant r_{j}<2^{20}\right)$. If $d \geqslant 0$, then the corresponding mine is dangerous. In a dangerous mine, no minerals are available $\left(r_{0}=\ldots=r_{m-1}=0\right)$. You may assume that at most 20 mines are dangerous and that the entry is not.

- The following $n-1$ lines describe the railway tracks. Each line contains two integers $u\ v$, separated by a space, indicating a railway track between mine $u$ and mine $v$ $(0 \leqslant u, v<n)$. You may assume that $v$ lies on the (unique) path from $u$ to the entry. 
- The following $m$ lines describe the minerals. Each line contains 3 integers $c\ s\ p$, separated by a space. They denote $c$, the amount of the mineral required for the mirror; $s$, the supply of the mineral at the shop; and $p$, its price per unit at the shop $\left(0 \leqslant c, s, p<2^{28}\right)$.

**Output** For each test case the corresponding output appears on a separate line. If the dwarfs can obtain all the minerals required, the output is the price they had to pay, rounded down to the next integer. Otherwise, the output is `Impossible!`.

**Points** There are four groups of test sets. For each group there is also a corresponding hidden test set, each worth 5 points. Overall, you can achieve 100 points.

1. For the first group of test sets, worth 25 points, you may assume that (1) the railway tracks form a path that starts at the entry; (2) there exists at most one dangerous mine and (3) the market is sold out $\left(s_{j}=0\right.$, for all $\left.j\right)$.

2. For the second group of test sets, worth 25 points, you may assume that (1) for every mine there is at most one dangerous mine on its (unique) sequence of tracks to the entry; and (2) the market is sold out $\left(s_{j}=0\right.$, for all $\left.j\right)$.

3. For the third group of test sets, worth 20 points, you may assume that the market is sold out $\left(s_{j}=0\right.$, for all $\left.j\right)$.

4. For the fourth group of test sets, worth 10 points, there are no additional assumptions.

## Exercise - Rumpelstilzchen

> "Heute back ich, Morgen brau ich, Übermorgen hol ich der Königin ihr Kind; Ach, wie gut ist, daß niemand weiß, daß ich Rumpelstilzchen heiß!"

> "Today I bake, tomorrow I brew, The day after that the queen's child comes in; And oh! I am glad that nobody knew that the name I am called is Rumpelstiltskin!"

*Kinder- und Hausmärchen by Jacob Grimm (1785-1863) and Wilhelm Grimm (1786-1859)*

After many years, Rumpelstilzchen is living on a group of islands. One day he decides to spin as much gold as he can in one night at the islands. He discovers that he can spin one yarn of superior gold if he uses one sack of wheat straw and one sack of barley straw. However, wheat straw is only available in the castle of the kingdom to the west of the islands and barley straw in only available in the castle of the kingdom to the east of the islands.

The queen's father, the miller, wants to repay Rumpelstilzchen for helping his daughter and agrees to transport the straw from both kingdoms to the islands for free. The miller transports the straw during the day, and Rumpelstilzchen can spin gold during the night. The miller has two independent transportation networks. The transportation networks consist of roads between cities, and shipping routes connecting cities of the two kingdoms to the islands. The two transportation networks do not have any cities in common, and there are no roads connecting cities of one transportation network with cities of the other transportation network. Each road and shipping route has a maximum capacity associated with it, which denotes the maximum number of sacks that can be transported through it. Both kingdoms have strict traffic rules, and all roads and shipping routes are one-way, i.e. they can only be traversed in a prespecified direction. The castle is situated in the city with index zero in both kingdoms.

On each island is one spinning wheel that Rumpelstilzchen can use to spin gold. However, the spinning wheels are not well maintained, and they will break down after spinning exactly one yarn of gold, i.e. each island can produce at most one yarn of gold. Like all gold spinners who take themselves seriously, Rumpelstilzchen prefers some spinning wheels over others. More specifically, he has a preference score for each spinning wheel, indicating how much he enjoys spinning on that particular spinning wheel. Rumpelstilzchen would like to maximize the number of yarns of superior gold spinned that night. If there exist multiple strategies leading to the same number of yarns of superior gold, he chooses a combination of spinning wheels with the highest total sum of preference scores. You can assume that Rumpelstilzchen has enough time during the night to visit all islands, if needed.

**Input** The first line of the input contains the number $t \leqslant 30$ of test cases. Each of the $t$ test cases is described as follows:

- It starts with a single line containing nine integers $n\ p_{G}\ p_{H}\ e_{G}\ e_{H}\ f_{G}\ f_{H}\ s_{G}\ s_{H}$, separated by a space. For $X \in\{G, H\}$, they denote

  - $n$, the number of islands $(1 \leqslant n \leqslant 500)$;
  - $p_{X}$, the number of cities in the network $X\left(1 \leqslant p_{X} \leqslant 10^{3}\right)$
  - $e_{X}$, the number of edges of $X\left(1 \leqslant e_{X} \leqslant 5 \cdot 10^{3}\right)$
  - $f_{X}$, the number of edges from $X$ to the islands $\left(1 \leqslant f_{X} \leqslant 2 \cdot 10^{3}\right) ;$ and
  - $s_{X}$, the number of sacks of straw available in the castle of $X\left(1 \leqslant s_{X} \leqslant 10^{3}\right)$.

- The following line contains $n$ integers $a_{0} \ldots a_{n-1}$, separated by a space. They denote the preference score of the spinning wheel on each of the $n$ islands $\left(0 \leqslant a_{i} \leqslant 2^{10}\right)$

- The following $e_{G}+e_{H}$ lines define the edges of $G$ (first) and $H$ (second). Each line contain three integers $u\ v\ c$, separated by a space, that define a one-way road of capacity $c$ from city $u$ to city $v$ in the respective network $\left(0 \leqslant u<p_{X}, 0 \leqslant v<p_{X}, u \neq v, 0 \leqslant c \leqslant 2^{24}\right)$.

- The next $f_{G}+f_{H}$ lines define the edges between the networks $G$ (first) and $H$ (second) on one side and the islands on the other side. Each line contains three integers $u\ v\ c$ separated by a space, that define a one-way shipping route of capacity $c$ from city $u$ in the respective network to an island $v\left(0 \leqslant u<p_{x}, 0 \leqslant v<n, 0 \leqslant c \leqslant 2^{24}\right)$.

**Output** The output for each test case consists of a separate line containing two integers $y\ s$, separated by a space. They denote $y$, the maximum number of yarns of superior gold that Rumpelstilzchen can spin during the night; and $s$, the corresponding maximum total preference score of the used spinning wheels for that number of yarns of superior gold.

**Points** There are four groups of test sets. For each group there is also a corresponding hidden test set, each worth 5 points. Overall, you can achieve 100 points.

1. For the first group of test sets, worth 25 points, you may assume that all preference scores $a_{i}$ are equal to zero, that the second transportation network $H$ contains a direct shipping route from the castle (index 0 ) to each island with capacity equal to 1 , and that the number of sacks of barley straw available in the second transportation network $\mathrm{H}$ is equal to the total number of islands $n$.

2. For the second group of test sets, worth 25 points, you may assume the same as for the first group of test sets, except that the preference scores are not necessarily equal to zero. Moreover, you may assume $n \leqslant 100, p_{G}+p_{H} \leqslant 200, e_{G}+e_{H}+f_{G}+f_{H} \leqslant 1200$

3. For the third group of test sets, worth 15 points, you may assume that all preference scores $a_{i}$ are equal to zero.

4. For the fourth group of test sets, worth 15 points, there are no additional assumptions.

Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3,4\}$ 

## Exercise - Rapunzel

> "Rapunzel, Rapunzel, laß dein Haar herunter!"

> "Rapunzel! Rapunzel! Let down your hair that I may climb thy golden stair!"

*Kinder- und Hausmärchen by Jacob Grimm (1785-1863) and Wilhelm Grimm (1786-1859)*

Once upon a time there was a beautiful girl called Rapunzel with splendid long hair, golden as the sun. Alas, she was prisoner to an evil sorceress, who had locked her in a high tower with no doors or stairway, only a small window at the top.

One day, a king's son happened to be passing by the tower and heard Rapunzel's angelic singing. His heart touched by the girl's magical voice, he wanted to climb up the tower and meet her. He observed that when the sorceress wanted to go up, she would ask Rapunzel to let her hair down. The girl would then wind it around a window hook and let the rest of it down out of the window. Her hair was so long that it reached all the way down to the ground and the sorceress could climb up, using it as a ladder. So after waiting for the sorceress to go away, the prince asked Rapunzel to let her hair down so he could climb up to her.

The girl's hair is braided in a complicated hairstyle, using $n$ hair ties. The hair ties are indexed $0,1, \ldots, n-1$, where hair tie 0 is the topmost one, that is, the one closest to Rapunzel's head. Some pairs of hair ties are connected by a strand of hair. We say that there is a strand of hair from hair tie $u$ to hair tie $v$ if $u$ and $v$ are connected by a strand of hair in such a way that $u$ is closer to Rapunzel's head than $v$. A sequence $s_{0}, \ldots, s_{\ell-1}$ of hair ties such that there is a strand of hair from $s_{j-1}$ to $s_{j}$, for all $j \in\{1, \ldots, \ell-1\}$, is called a rope of length $\ell$ starting at hair tie $s_{0}$ and ending at hair tie $s_{\ell-1}$. For each hair tie $u$, there is precisely one rope starting at 0 and ending at $u$.

Rapunzel's plan is to find an appropriate rope $s_{0}, \ldots, s_{m-1}$ of length $m$ and then wind hair tie $s_{0}$ around a window hook and let the rest of the rope down out of the window, so the prince can climb up. The girl has chosen $m$ carefully, so that any rope of length $m$ would reach the ground exactly. However, there is an additional difficulty: the prince is very sensitive to bright light and so the golden shining of the girl's magnificent hair could blind him if they are not careful. The hair around each hair tie $i \in\{0, \ldots, n-1\}$ has some brightness $h_{i} \geqslant 0$. The prince explains that the important quantity is the contrast of a rope, that is, the difference between the maximum and the minimum brightness of the hair around all hair ties in that rope. If that difference is too large, the prince's eyes could not adapt to the change. Thus, a rope is safe for the prince if it has contrast at most $k$.

A rope is considered by the prince and Rapunzel to be climbable if it is safe and it has length exactly $m$. Since Rapunzel wants to know her options, her task is then to find all hair ties at which some climbable rope starts.

**Input** The first line of the input contains the number $t \leqslant 30$ of test cases. Each of the $t$ test cases is described as follows.

- It starts with a line that contains three integers $n\ m\ k$, separated by a space. They denote 

  - $n$, the number of hair ties $\left(1 \leqslant n \leqslant 10^{5}\right)$;
  - $m$, the desired length of the rope $\left(2 \leqslant m \leqslant 10^{4}\right)$;
  - $k$, the maximum contrast that is considered safe for the prince $\left(0 \leqslant k \leqslant 10^{4}\right)$.

- The following line defines the brightness of the hair around the hair ties. It contains $n$ integers $h_{0} \ldots h_{n-1}$, separated by a space, and such that $0 \leqslant h_{i}<2^{31}$, for $i \in$ $\{0, \ldots, n-1\}$. Here $h_{i}$ denotes the brightness around the $i$-th hair tie.

- The following $n-1$ lines define the strands of hair. Each line consists of two integers $u\ v$, separated by a space, and such that $u, v \in\{0, \ldots, n-1\}$. This means that there exists a strand of hair from hair tie $u$ to hair tie $v$.

**Output** For each test case output a single line with a sequence of all hair ties, separated by a space and listed in increasing order, for which there exists a climbable rope starting there. If there is no such hair tie, output a single line with `Abort mission`.

**Points** There are four groups of test sets. For each group there is also a corresponding hidden test set, each worth 5 points. Overall, you can achieve 100 points.

1. For the first group of test sets, worth 15 points, you may assume that for every hair tie, there is at most one rope starting from it. Furthermore, $n \leqslant 10^{3}$ and $m, k \leqslant 10^{2}$.

2. For the second group of test sets, worth 15 points, you may assume that for every hair tie, there is at most one rope starting from it.

3. For the third group of test sets, worth 15 points, you may assume that $n \leqslant 10^{3}$ and $m, k \leqslant 10^{2}$.

4. For the fourth group of test sets, worth 35 points, there are no additional assumptions.

Corresponding sample test sets are contained in testi. in/out, for $i \in\{1,2,3,4\}$.