---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Buddy Selection

At the beginning, Mathilda was very enthusiastic about her school's new buddy program. Students were to be grouped into pairs of buddies that were supposed to help each other out in their studies. As one of the first, Mathilda composed a short profile of herself describing her hobbies etc. The school director Dr. Fuzzman intended to use these profiles to find a suitable partner for every student. Alas, when Mathilda got the profile of her assigned partner she was very disappointed: her partner was to be male, like soccer and be crazy about military gear. In short, her partner was the direct opposite of herself.

Mathilda went straight to Dr. Fuzzman to complain about the assignment. However he could not understand her discontent as Mathilda's partner liked math and chemistry just like Mathilda and enjoyed watching television, just like her. Nodding to a huge stack of student profiles he said with a mean smile: "I can give you the profiles of everybody and you will see that no better pairing is possible - it is a chance that everybody can be paired at all!". You have to help Mathilda.

Given a list of students and several characteristics per student, check whether there is a buddy assignment in which partners share more common characteristics than in the solution of Dr. Fuzzman.

**Input** The first line of the input contains the number $t \leqslant 30$ of test cases. Each of the $t$ test cases is described as follows:

- It starts with a line that contains three integers $n\ c\ f$, separated by a space, denoting
  - $n$, the (even) number of students $(2 \leqslant n \leqslant 400, n \equiv 0 \bmod 2)$.
  - $c$, the number of characteristics per student $(1 \leqslant c \leqslant 100)$.


- $f$, the minimum number of common characteristics over all pairs of buddies in Dr. Fuzzman's solution $(f \geqslant 0)$.

- The next $n$ lines each describe the characteristics of one student: each student is described by c space separated keywords. Every keyword describes a characteristic. Each keyword consists of less than 20 lowercase letters and no two keywords for one student are the same.

**Output** For every testcase, if there is a buddy assignment in which all pairs of buddies share more than $f$ characteristics, output not opt imal, otherwise output opt imal. Two characteristics are considered equal only if they have identical keywords.

**Points** There are three groups of test sets, which are worth 100 points in total.

1. For the first group of test sets, worth 30 points, you may assume that $f=0$ and $c \leqslant 10$.

2. For the second group of test sets, worth 40 points, you may assume that $c \leqslant 10$. 