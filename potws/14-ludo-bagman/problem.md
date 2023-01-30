---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Ludo Bagman

> Quidditch unites witches and wizards from all walks of life, bringing us together to share moments of exhilaration, triumph, and despair.

*Quidditch Through the Ages by J. K. Rowling*

Quidditch is a popular sport played by witches and wizards on flying broomsticks. Appointed to organize the qualifiers for the 422nd Quidditch World Cup is none other than Ludovic "Ludo" Bagman, the Head of the Department of Magical Games and Sport.

Ludo first splits all the participating teams into two groups, depending on whether they come from the East or the West. Then, each match is to be played between a team from the East and a team from the West. As in every competition, some pairs of teams have developed a strong rivalry between them. Whenever two teams that are rivals play each other, there is a potential of a violent fight breaking out. Such matches are considered to be difficult. Ludo is very much aware of this and, unfortunately, may have to cancel all difficult matches if violence around Quidditch keeps getting worse. In order to fairly assess each team's performance regardless, he must ensure that every team has at least $\ell$ non-difficult matches scheduled to be played during the qualifiers. Naturally, any two teams can play each other at most once.

Of course, such a huge event poses a significant threat to the International Statute of Secrecy^1^. In an attempt to keep things under control and not have too many Muggles' memories erased, Ludo's department has computed a risk value for every potential match. The total risk of a schedule is the sum of the individual risks over all the scheduled matches—difficult or not.

Given two parameters $p, \ell \in \mathbb{N}$ and a list of all potential matches at his disposal, Ludo has a clear goal: design a fair schedule of minimum total risk for the qualifiers. A schedule is a collection of exactly $p$ potential matches—difficult or not. A schedule is fair if it allows to fairly assess each team's performance, as defined above.

^1^ Muggles (people without any magical ability) are to be unaware of the existence of the Wizarding World.

**Input** The first line of the input contains the number $t \leqslant 30$ of test cases. Each of the $t$ test cases is described as follows.

- It starts with a line containing four integers $e \ w\ m\ d$, separated by a space. They denote
  - $e$, the number of teams from the East $(1 \leqslant e \leqslant 250)$;
  - $w$, the number of teams from the West $(1 \leqslant w \leqslant 250)$
  - $m$, the number of non-difficult matches on the list of potential matches $(1 \leqslant m \leqslant$ $\left.4 \cdot 10^{3}\right)$
  - $d$, the number of difficult matches on the list of potential matches $\left(0 \leqslant d \leqslant 4 \cdot 10^{2}\right)$.


- The following line contains two integers $p\ \ell$, separated by a space. They denote

  - $p$, the number of matches for the qualifiers $(1 \leqslant p \leqslant m+d)$; and

  - $\ell$, the minimum number of matches each team needs to play in order to be assessed fairly $(1 \leqslant \ell \leqslant \min \{e, w\})$.

- The following $m+d$ lines describe the list of potential matches. The first $m$ lines describe the non-difficult matches, while the latter $d$ describe the difficult matches. Each such line contains three integers $u\ v\ r$, separated by a space, denoting that there is a potential match between team $u$ from the East $(0 \leqslant u<e)$ and team $v$ from the West $(0 \leqslant v<w)$ with an associated risk of $r\left(1 \leqslant r \leqslant 2^{14}\right)$.

You may assume that every team appears at least $\ell$ times in the $m$ non-difficult matches and that every ordered pair $(u, v)$ appears at most once in the list of potential matches.

**Output** The output for each test case consists of a separate line containing either

- a single integer that denotes the minimum total risk of a fair schedule for the given problem instance, or

- the string "No schedule!", to indicate that no fair schedule exists.

**Points** There are four groups of test sets, each of which is worth 20 points. For each group there is also a corresponding hidden test set that is worth 5 points. So, there are $4 \cdot 20+4 \cdot 5=100$ points in total.

1. For the first group of test sets you may assume that there are no difficult matches $(d=0)$, the risk $r$ is identical for all matches, and it is easy to fairly assess teams $(\ell=1)$.

2. For the second group of test sets you may assume that there are no difficult matches $(d=0)$ and the risk $r$ is identical for all matches.

3. For the third group of test sets you may assume that there are no difficult matches $(d=0)$.

4. For the fourth group of test sets there are no additional assumptions.

Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3,4\}$.
