---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Antenna

After the invention of radio, Theirland wants to demonstrate its technological superiority and builds a first radio transmitter. The transmitter must cover the whole population. It is characterized by a location and a transmission radius (within which a reception of the signal is guaranteed). Not surprisingly, transmitters with a higher radius require more advanced technology and more time to build and—last but not least—they cost much more. Thus, the government decided to find a location where the transmission radius is as small as possible, but every single citizen can receive the signal at home. This is not an easy goal to achieve, though...

**Input** The input contains several test cases. Each of them begins with a line containing one integer $n\left(1 \leqslant n \leqslant 200^{\prime} 000\right)$, denoting the number of citizens. The next $n$ lines contain coordinates $x_{i} y_{i}$ of homes of citizens $\left(x_{i}, y_{i}\right.$ integral with $\left.\left|x_{i}\right|,\left|y_{i}\right|<2^{48}\right)$. All numbers on a single line are separated by a single space. The input is terminated by a single line containing 0 (i.e., an empty testcase).

**Output** For each input, write on a single line the smallest integral transmission radius needed to cover all citizens.