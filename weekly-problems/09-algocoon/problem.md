---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---



# Exercise - Algocoön Group

The startup you created with your best friend is a great success. On impulse, you jointly decide to spend a big chunk of your profits on one of those ancient Greek sculptures depicting a group of mythological figures entangled in a complicated configuration.

You are presented with several sculptures to choose from. Unfortunately, you can afford only one sculpture and both of you would like to take it home. A brilliant idea you have is to hire a stonecutter to cut the sculpture in two parts.

Every sculpture consists of several figures, each of them equipped with (possibly large) number of limbs. Each limb reaches some other figure and has a cost that the cutter will charge for separating it. The deal is as follows: you will decide on how to cut the sculpture (i.e., which figures you take home). Both you and your partner need to get at least one figure. To share the cost, you pay for cutting the limbs of your figures and your friend for limbs of her figures.

Your objective is to write a program that will go over all sculptures and for each of them find a cutting that minimizes your cost.

Input The first line contains $1 \leqslant t \leqslant 30$, the number of sculptures. Each of the $t$ sculptures is described as follows:

- It starts with a line that contains two numbers $\mathrm{n} \mathrm{m}$, separated by a space. They denote
  - $2 \leqslant n \leqslant 200$, the number of figures in the sculpture and
  - $0 \leqslant m \leqslant 5000$, the total number of limbs between the figures.


- $\mathrm{m}$ lines follow, each of them containing three numbers a b c, indicating that figure $a$ has a limb that extends to figure $b$ with cutting cost $c$ (with $0 \leqslant a, b<n, a \neq b$ and $1 \leqslant c \leqslant 1000)$. Note that a figure can have several limbs extending to the same other figure.

Output For every test case output a single line with the total cost of an optimal cut.

Points There are five groups of test sets which are worth 100 points in total.

1. For the first group of test sets, worth 10 points, you may assume that there is a solution minimizing your cost where you get figure 0 and your friend gets figure $n-1$.
2. For the second group of test sets, worth 10 points, you may assume that there is a solution minimizing your cost where you get figure 0 .
3. For the third group of test sets, worth 20 points, you may assume that $n \leqslant 50$ and $m \leqslant 1000$.
4. For the fourth and fifth group of test sets, worth 30 points, there are no further assumptions. 

Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3,4,5\}$.
