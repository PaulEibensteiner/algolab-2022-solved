---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22 Department of Computer Science Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Suez

One of Scotland Yard's finest men, who goes by the name of Detective Fix, has been sent to the port of Suez, Egypt. He is charged with narrowly watching all those who arrive by ship, so as to identify and apprehend any criminals trying to flee Europe. To help with this task, Fix has been given a full dossier containing posters of wanted thieves, burglars, murderers, as well as the vague description of an as of yet unnamed gentleman who is suspected to have stolen the record-breaking sum of $£ 55^{\prime} 000$ from the Bank of England not more than a week ago.

The detective wants to display all posters on a wall in his office. For that purpose there is a number of nails at fixed positions on the wall, where each nail can be used to hang up exactly one poster. A large number of these nails is already occupied with posters of those who have been brought to justice by Fix in the past. Luckily, the number of remaining unoccupied nails is exactly equal to the number of new posters that the detective wants to add.

Needless to say, being the perfectionist that he is, Fix does not want any of the posters (either old or new) to overlap. Nor does he want to hang up any of the posters sideways or at an angle. It should also go without saying that the trophies from his past-that is, the posters that are already on the wall-are to remain untouched.

By decree AW-80d, all posters provided by Scotland Yard have the exact same format; they are $h$ inches high and $w$ inches wide. This holds for both the old posters and the new. However, Fix believes that maximizing the sum of perimeters of all new posters will also maximize his chance of recognizing one of the faces. He is thus willing to infringe AW-80d by using his newly purchased magnifying machine to generate scaled copies of the new posters. Note that since this is a magnifying machine, it can only be used to make the posters larger. That is, Fix can transform the size of any poster from $h$-by-$w$ to $(a h)$-by-$(a w )$, where $a \geqslant 1$ is a scaling factor that can be chosen individually for each poster.

For the sake of maximal stability, Fix wants each nail to go through the center of the corresponding poster. In other words, if a nail has coordinates $(x, y)$ then the corresponding (scaled) poster covers the area

$$
\left[x-\frac{a w}{2}, x+\frac{a w}{2}\right] \times\left[y-\frac{a h}{2}, y+\frac{a h}{2}\right]
$$

Can you help Fix set up his wall before the arrival of the Mongolia?

**Input** The first line of the input contains the number $t \leqslant 30$ of test cases. Each of the $t$ test cases is described as follows.

- It starts with a line containing four integers $n\ m\ h\ w$, separated by a space. They denote

  - $n$, the number of new posters to be added to the wall $(2 \leqslant n \leqslant 30)$;

  - $m$, the number of old posters already hanging on the wall $\left(0 \leqslant m \leqslant 10^{3}\right)$;

  - $h$, the height of the posters as per AW-80d $\left(0<h<2^{7}\right)$;

  - $w$, the width of the posters as per AW-80d $\left(0<w<2^{7}\right)$.

- The following $n$ lines define the positions of the free nails on the wall.


- The following $m$ lines define the positions of the already occupied nails on the wall.

Each position is described by two integers $x\ y$, separated by a space and such that $|x|,|y|<2^{24}$. Here, $x$ and $y$ denote the coordinates in inches of the corresponding nail on the wall. You may assume that the $n+m$ positions of all nails are such that it is possible to hang up a poster with size $h$-by-$w$ centered at each nail without any overlap.

**Output** For each test case output on a separate line the maximum attainable sum of perimeters of the new posters in inches, rounded up to the nearest integer.

**Points** There are four groups of test sets, each of which is worth 25 points.

1. For the first group of test sets, you may assume that all nails are arranged on a horizontal line $(y=0)$ and that there are no old posters $(m=0)$.

2. For the second group of test sets, you may assume that there are no old posters $(m=0)$.

3. For the third group of test sets, you may assume that there is only a small number of old posters $(m \leqslant 10)$.

4. For the fourth group of test sets, there are no additional assumptions.

Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3,4\}$.
