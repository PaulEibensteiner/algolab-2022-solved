---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Idéfix and the Mansions of the Gods

In his latest and most ambitious attempt to subdue the final resisting Gaulish village, Julius Caesar has given orders to root up all the trees in the nearby forest and to surround the village with blocks of flats that would later be filled with tenants from Rome, thus slowly forcing the Gauls to adapt to the superior Roman culture. Needless to say, the attempt has been thwarted swiftly and the Romans have been expelled by Astérix and his friends. But most of the damage has been done already; the village is now surrounded by wasteland, littered with holes reminiscent of the mighty oak trees that once stood in their place.

Perhaps the one who suffers the most is Idéfix; the friendly dog and loyal companion of Obélix is known for howling in distress whenever he sees a tree being injured. Apart from his love for trees, he enjoys chewing on bones and burying them in the ground for later use. Over the years, he has thus buried a large number of bones at various sites in the former forest. He now mourns the good old days when he was able to go for a Sunday afternoon walk—covered in the shadows of the oak trees—visiting and inspecting the sites where his bones are buried.

To everyone's great relief, the village druid Panoramix has come up with a new magic potion that will solve the problem. Any acorn that has been soaked in this potion will instantaneously produce a fully grown oak tree, when thrown into one of the holes in the former forest. For simplicity, as seen from above, we assume that the new trees will cast a shadow in the form of a closed disk in the plane with a fixed radius $r$ and centered at the corresponding hole. Panoramix has one more trick up his sleeve though; if necessary, he may adjust the dosage of a certain secret ingredient, which has the effect of producing trees with radii smaller or larger than $r$.

In the meantime, while the other villagers are starting to prepare the required acorns, Idéfix wants to find answers to the following two most pressing questions:

- Once the oak trees (with radius $r$) are planted, what is the largest number a of distinct bones that Idéfix can inspect on a walk through the forest, if he can freely choose start and end point and if his trajectory must be contained in the union of the shadows?

- For some given integer $k$, what is the smallest radius $b$ (instead of $r$ ) that the oak trees would need to have such that it becomes possible for Idéfix to inspect at least $k$ bones on a walk through the forest, under the same constraints as above?

**Input** The first line of the input contains the number $t \leqslant 30$ of test cases. Each of the $t$ test cases is described as follows.

- It starts with a line containing four integers $n\ m\ s\ k$, separated by a space. They denote

  - $n$, the number of oak trees that will be planted $\left(1 \leqslant n \leqslant 4 \cdot 10^{4}\right)$;
  - $m$, the number of bones buried in the ground $\left(1 \leqslant m \leqslant 4 \cdot 10^{4}\right)$;
  - $s=4 r^{2}$, where $r$ is the normal radius of an oak tree $\left(1 \leqslant s<2^{51}\right)$;
  - $k$, the minimum number of bones that Idéfix would like to inspect $(1 \leqslant k \leqslant m)$.

- The following $n$ lines define the positions where the oak trees will be planted.

- The following $m$ lines define the positions where the bones are buried.

Each position is described by two integers $x$, separated by a space and such that $|x|,|y|<2^{24}$. You may assume that the $n$ positions corresponding to the oak trees are pairwise distinct. The same does however not hold for the $m$ positions corresponding to the buried bones; that is, there may be more than one bone buried at the same position and there also may be bones buried at the position where an oak tree will be planted.

**Output** The output for each test case consists of a separate line containing two integers $a\ q$, separated by a space, where $q=4 b^{2}$. The numbers $a$ and $b$ are as specified earlier.

**Remark** Note that the numbers $r$ and $b$ are not necessarily integers.

**Points** There are four groups of test sets, each of which is worth 25 points. So, there are $4 \cdot 25=100$ points in total.

1. For the first group of test sets, you may assume that there is only a small number of oak trees and buried bones $\left(n, m \leqslant 10^{3}\right)$, and you may also assume that the smallest radius that would allow inspecting $k$ bones is twice the normal radius $(b=2 r)$.

2. For the second group of test sets, you may assume that the smallest radius that would allow inspecting $k$ bones is twice the normal radius $(b=2 r)$.

3. For the third group of test sets, you may assume that there is only a small number of oak trees and buried bones $\left(n, m \leqslant 10^{3}\right)$.

4. For the fourth group of test sets, there are no additional assumptions.

Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3,4\}$.

