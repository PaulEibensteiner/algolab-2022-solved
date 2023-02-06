# Algorithms Lab Exam January 2023

*Second Part*

## Exercise - Little fish

> "Oh Brüderchen im tiefen See, wie tut mir doch mein Herz so weh!"

> "Oh little brother in the lake, my sad heart is about to break."

*Kinder- und Hausmärchen by Jacob Grimm (1785-1863) and Wilhelm Grimm (1786-1859)*

Once upon a time, there was a little brother and a little sister who loved each other very much. Since their mother had passed away, they had been living with a stepmother who secretly hated them, and did everything she could to hurt them.

One very hot summer day as the siblings were happily playing outside, the stepmother could no longer take it: this terrible happiness had to stop, she thought. She proceeded to cast an evil spell that transmuted the poor unsuspecting boy into a little fish, and promptly threw him into the garden's pond! The sad little fish was trapped in the pond, but not all hope was lost: the little sister had escaped the evil stepmother's grip, and was now on the run, traveling to seek a healer who could turn her brother back into human form.

Yet the hot summer brought another trouble: the pond was slowly drying up. The pond can be modeled as a grid of size $n \times m$, with an integer $d$ assigned to every cell denoting the initial depth at time $t=0$ of the pond at that coordinate. The pond slowly dries up, such that at every unit of time, one unit of depth worth of water disappears from each coordinate. For the little fish to survive, he needs to have enough oxygen at each point in time. A region of the pond has enough oxygen if its connected water surface area (not volume!) is at least $k$ cells, and the amount of oxygen available in the region is defined as the connected water surface area (not volume!) of the region. Two grid cells have a connected water surface if they are neighbours (left, right, up or down) and they are both under water, that is, $d>t$. The little fish can survive if there exists a region in the pond with enough oxygen.

The little sister needs to know how fast she should find a healer. So she needs to know the latest time $t$ by which the little fish can still survive. However, there is another issue: The stepmother has a barrier, which can be used to block the water surface between one pair of neighboring grid cells so that this pair is no longer considered adjacent. She will only use the barrier at time $t$, and aims to place it in such a way that the oxygen available for the little fish reduces by at least 1. If she manages, the little fish will panic and as a result cannot be turned back into human form any more. The fish will not panic if there exists a region in the pond with enough oxygen whose available oxygen cannot be reduced by the barrier. Of course, the little sister would like to know whether this will be the case as well. We can assume that the little fish can instantaneously jump to whichever part of the grid he wants to at any time, and always chooses to be in a place where he can survive and also be free of panic, if such a place exists in the pond. Note that after the stepmother has placed the barrier, the fish cannot move anymore.

**Input** The first line of the input contains the number $T$ of test cases. Each of the test cases is described as follows:

- It starts with a single line containing two integers $n\ m$, separated by a space, denoting the length $n$ of the grid and the width $m$ of the grid $1 \leq n, m \leq 30$.

- The next line contains an integer $k$, denoting the minimum amount of oxygen that needs to be available so that the little fish can survive.

- The third line contains an integer $h$, which is a hint indicating whether the little fish gets panic at time $t$. We have that $h=1$ indicates yes and $h=0$ indicates no. When $h=-1$, the hint is invalid.

- The next $n$ lines define the pond's depth profile. Line $i$ contains $m$ integers $d \ldots d_{m-1}$, separated by a space, where $d_{j}$ denotes the initial depth of the pond at time $t=0$ on coordinates $i,j$.

**Output** The output for each test case consists of a separate line containing two integers $t$ and $p$, separated by a space. They denote $t$, the latest time by which the little fish has enough oxygen; and $p$, whether or not the little fish gets panic due to the barrier at time $t$ (here $p=1$ indicates panic and $p=0$ indicates no panic).

**Points** There are three groups of test sets. For each group there is also a corresponding hidden test set. Overall, you can achieve 100 points.

1. For the first group of test sets, worth 25 points, and for the corresponding group of hidden test sets, worth 5 points, you may assume that $n \quad 5, m 5, h \quad 1$, and $p=h$.

2. For the second group of test sets, worth 25 points, and for the corresponding group of hidden test sets, worth 5 points, you may assume that $h \quad 1$, and $p=h$.

3. For the third group of test sets, worth 3 points, and for the corresponding group of hidden test sets, worth 1 points, you may assume that $h=1$, i.e. no hint available.

Corresponding sample test sets are contained in testi.in/out, for $i \in 1,2,3\}$.

## Exercise - Hänsel und Gretel

> "Wart nur, Gretel, bis der Mond aufgeht, dann werden wir die Brotbröcklein sehen, die ich ausgestreut habe, die zeigen uns den Weg nach Haus."

> "Just wait, Gretel, until the moon gets up, then we shall see the breadcrumbs I have scattered along the path, they will show us the way home."

*Kinder- und Hausmärchen by Jacob Grimm (1785-1863) and Wilhelm Grimm (1786-1859)*

The siblings Hänsel and Gretel have been abandoned in the forest. Hänsel has dropped some stones and some breadcrumbs along the way, originally with the intent to find the way back home. However, by now he regrets not having the bread anymore because they have no other food available. Therefore, they decide to go and pick up as many of the breadcrumbs as possible. The moonlight is sketchy, so they can see everything up to a distance of $d$ only. Also, they must avoid getting lost in the forest—there have been rumors of a nasty witch hiding in the area. In particular, they must stay together (at the same position) at all times. So, they decide on a safe pickup strategy, which is an arbitrary sequence of the following three actions only:

1. Standing at a stone $p$, directly (i.e., in a straight line) walk to a position that is in sight (i.e., at a distance $d$ from $p$ );

2. standing at a breadcrumb, collect and eat it; or

3. from the current position, directly walk to a stone in sight.

We consider the situation as seen from above on a map where all positions—of the siblings and of breadcrumbs or stones—are points in the two-dimensional Euclidean plane^2^. From the story we know that Hänsel and Gretel are smart, that is, from a given starting position they select an optimal safe pickup strategy so as to maximize the number of breadcrumbs collected. Given that this is a fairytale, we may also assume that Hänsel and Gretel are lucky, that is, their starting position is best possible–-again, in the sense of allowing them to collect a maximum number of breadcrumbs starting from there with a safe pickup strategy. How many breadcrumbs can Hänsel and Gretel collect? And what if the weather conditions change, which could affect the distance $d$ they can see ahead in the moonlight? For a given hunger parameter $h$, what is the minimum distance $d_{\min }$ they would need to be able to see ahead in the moonlight so as to collect at least $h$ breadcrumbs?

**Input** The first line of the input contains the number $t$ of test cases. Each of the $t$ test cases is described as follows.

- It starts with a line containing four integers $s\ b\ z\ h$, separated by a space. They denote
  - $s$, the number of stones placed by Hänsel
  - $b$, the number of breadcrumbs placed by Hänsel
  - $z=4 d^{2}$, where $d$ is the distance that defines how far they can see in the moonlight $\left(1 \leq z<2^{51}\right) ;$ and
  - $h$, the number of breadcrumbs they want to collect.


- The following $s$ lines define the positions of the stones.

- The following $b$ lines define the positions of the breadcrumbs.

Each position is described by two integers $x\ y$, separated by a space and such that $|x|,|y|<2^{24}$. You may assume that the s positions of the stones are pairwise distinct. The positions of the breadcrumbs are unrestricted: several may be placed at the same position and/or at the same position as a stone.

**Output** The output for each test case consists of a separate line containing two integers $m\  f$, separated by a space, where

- $m$ is the maximum number of breadcrumbs that the siblings can collect and

- $f=4 d_{\min }{ }^{2}$, where $d_{\min }$ is the minimum distance the siblings would need to be able to see ahead in the moonlight so as to collect at least $h$ breadcrumbs,

in both cases assuming that Hänsel and Gretel are both smart and lucky. Note that the numbers $d$ and $d_{\min }$ need not be integral in general.

**Points** There are four groups of test sets, each of which is worth 2 points. For each group there is also a corresponding hidden test set, each worth 5 points. Overall, you can achieve 100 points.

1. For the first group of test sets, you may assume that $d_{\min }=2 d$ and that there is only a small number of stones and breadcrumbs $\left(s, b \leq 10^{3}\right)$.

2. For the second group of test sets, you may assume that $d_{\min }=2 d$.

3. For the third group of test sets, you may assume that there is only a small number of stones and breadcrumbs $\left(r, b \leq 10^3\right)$.

4. For the fourth group of test sets, there are no additional assumptions.

Corresponding sample test sets are contained in testi.in/out, for $i \in 1,2,3,4\}$.

## Exercise - The Pied Piper of Hamelin

> "Der Rattenfänger zog demnach ein Pfeifchen heraus und pfiff, da kamen alsobald die Ratten und Mäuse aus allen Häusern hervorgekrochen und sammelten sich um ihn herum."

> "The rat-catcher produced a small pipe and whistled. Soon, rats and mice came creeping out from all the houses and gathered around him."

*Deutsche Sagen by Jacob Grimm (1785-1863) and Wilhelm Grimm (1786-1859)*

When word of the dire rat infestation plaguing the city of Hamelin reached the ears of the Pied Piper, he heeded the call for aid without hesitation. The prospect of the bountiful reward of one gold penny per rat eliminated, offered by the honorable mayor, proved sufficient inducement for the benevolent Piper to put his musical talent to use to lure the vermin from their lair.

Upon his arrival at the city gate, he is greeted by the mayor, who lays before the Piper a map of Hamelin in intricate detail. The map shows a total of $n$ public squares, numbered from 1 to $n-1$, scattered across the city. The public square at the entrance of the city, where the Piper currently stands, is public square 0. The map also indicates that there are $m$ one-way streets in Hamelin, each of which leads from some public square to another and has a number of rats residing on it. A sequence of public squares $s_0, \ldots, s_{\ell}$ and a sequence of streets $r_0, \ldots, r_{\ell-1}$ such that $r_{i}$ leads from $s_{i}$ to $s_{i+1}$ for each $i \in, \{0,\ldots, \ell - 1\}$, is called a plan for the Pied Piper's route through the city. In order to maximize the bounty that the Piper can collect, he wants to find a plan that maximizes the total number of rats on the streets included in the plan.

However, the mayor gives a few restrictions on the kind of plan that the Piper may follow. The plan must start and end at public square , it must contain the main public square, $n-1$, and shouldn't contain any public square more than once, except for 0. Finally, to not disturb the citizens, the plan must not change directions more than once, defined as follows. We say that a plan $s, \ldots, s_{\ell}$ is a monotonically increasing path if for every $i \in \left\{0, \ldots, \ell - 1\right\}$, it holds that $s_{i}<s_{i+1}$. Similarly, a plan $s, \ldots, s_{\ell}$ is called a monotonically decreasing path if for every $i \in,\{0, \ldots, \ell - 1\}$, we have $s_{i}>s_{i+1}$. . The mayor requires the plan  followed by the Piper to be a concatenation of a monotonically increasing path and a monotonically decreasing path. That is, $s_0, s_{1}, \ldots, s_{j-1}, s_{j}=n - 1$ should be a monotonically increasing path, and $n-1, s_{j+1}, \ldots, s_{\ell-1}, s_{\ell}$ should be a monotonically decreasing path. The plan is called acceptable if it satisfies all the requirements of the mayor.

The Pied Piper would like to find the maximum number of rats on the streets in any acceptable plan. It is guaranteed that an acceptable plan always exists.

**Input** The first line of the input contains the number $t$ of test cases. Each of the $t$ test cases is described as follows.

- It starts with a line that contains two integers $n \mathrm{~m}$, separated by a space. They denote 
  - $n$, the number of public squares and

  - $m$, the number of one-way streets connecting two public squares.

- The following $m$ lines define the streets and the number of rats on them. Each line consists of three integers $u\ v\ f$ separated by a space, such that $u, v \in \{0, \ldots, n - 1\}$ with $u \neq v$, indicating that there exists a street leading from public square $u$ to public square $v$ with $f$ rats on it. It is guaranteed that there is no street from 0 to $n-1$ and there is no street from $n-1$ to 0. Furthermore, for each $u, v \in \{0, \ldots, n -1\}$, there is at most one street from $u$ to $v$.

**Output **The output for each test case consists of a separate line containing a single integer that denotes the maximum number of rats on the streets in an acceptable plan.

**Points** We say that the city of Hamelin is layered (see Figure 1) if there exist $k$ non-empty sets $S, \ldots, S_{k-1}$ of public squares, such that:

- every public square $u \in \{0, \ldots, n -1\}$ belongs to precisely one set $S_{i}$ with $i \in \{0, \ldots, k - 1 \}$;

- for every street leading from $u$ to $v$ there is $i \in \{0, \ldots, k -2\}$ such that either $u \in S_{i}$ and $v \in S_{i-1}$, or $v \in S_{i}$ and $u \in S_{i -1} ;$ and

- for every $i \in \{0, \ldots, k -2\}$ and each $u \in S_{i}$ and $v \in S_{i-1}$, it holds that $u<v$.

The sets $S, \ldots, S_{k-1}$ are called a layering of Hamelin.

There are four groups of test sets. For each group there is also a corresponding hidden test set, each worth 5 points. Overall, you can achieve 1 points.

1. For the first group of test sets, worth 25 points, you may assume that the city of Hamelin is layered and there is a layering $S_0, \ldots, S_{k-1}$ such that for each $i \in \{0, \ldots, k -1\}$, we have $\left|S_{i}\right| \quad 1$. Additionally, you may assume that for every monotonically increasing path from 0 to $n-1$, there exists a monotonically decreasing path from $n - 1$ to 0 with the same total number of rats on its streets, and the public squares these two paths visit are disjoint, apart from 0 and $n-1$.

2. For the second group of test sets, worth 25 points, you may assume that the city of Hamelin is layered and there is a layering $S_0, \ldots, S_{k-1}$ such that for each $i \in \{0, \ldots, k - 1\}$, we have $\left|S_{i}\right| \quad 1$.

3. For the third group of test sets, worth 15 points, you may assume that the city of Hamelin is layered.

4. For the fourth group of test sets, worth 15 points, there are no additional assumptions.

Corresponding sample test sets are contained in testi.in/out, for $i \in 1,2,3,4\}$.