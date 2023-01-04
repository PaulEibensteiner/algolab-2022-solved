---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Diet

The economical crisis came and people in a poor country of Theirlands do have hardly enough money to feed themselves. The government decided to help them by designing a cheap, yet sufficient, diet for all its citizens. There are some constraints on the diet that need to be fulfilled for a long-term normal functioning of the human body, as for instance a daily intake of between around 1500 and 2500 kilocalories, some minimal amounts of vitamins, antioxidants and some other nutrients which are considered "generally healthy" - and much more. You can describe all these constraints in the form "the daily amount of $x$ should be between $a$ and $b$ ". These constraints slightly differ from person to person and are exactly determined by voluntary-unpaid doctors in the country.

What the government wants from you is a program that, given the constraints for an individual and the food which is available in the area where the individual lives, calculates the cheapest diet (that means amounts of each product such that the total amounts of each nutrient fulfills the prescribed conditions; these amounts do not need to be integral - it is possible to consume any fractional amount of a product in a day). They understand though, that it is an uneasy task on such a short notice and will for now be happy with an alpha version which only calculates the price of a cheapest diet.

**Input** The input file consists of several test cases. Each of them starts with a line containing two integers $n$ and $m$ $(1 \leqslant n \leqslant 40$ and $1 \leqslant m \leqslant 100)$. The following $n$ lines describe the nutrients. The $i$th of these lines contains two integers $\min _{i}$ and $\max _{i}$, the minimal and maximal daily amount of the $i$th nutrient. The next $m$ lines describe the foods. Each of them contains an integer price of a unit of the $j$th product, $p_{j}$, and another $n$ integers $C_{j, 1} \ldots C_{j, n}$ describing the amounts of nutrients $1 \ldots \mathrm{n}$ in a unit of product $j$. All the above integer values are in absolute value smaller than $2^{20}$. The input is terminated by a line 00 .

All the numbers on a single line are separated by a single space and there are no trailing whitespaces at the end of a line.

**Output** The output for each testcase is a line containing a single number $c$, the cost of the cheapest diet rounded down to an integer. If there is no diet fulfilling the criteria, output the line "No such diet.". Please note the trailing dot and that no trailing spaces at the end of the line are allowed.