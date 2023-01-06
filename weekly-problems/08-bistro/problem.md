---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Bistro

Sunbunny is a chain of bistros that provide among the finest snacks available in the country of Sealand. These places have become so popular that at lunch and dinner prime time one can regularly find long queues of people waiting to be served. Due to the continuing success the head office started to evaluate possible locations where to open another restaurant. One important selection criterion is that the new location must not be too close to an existing Sunbunny restaurant...

**Input** The input contains several test cases. Each of them begins with a line containing one integer $n\left(1 \leqslant n \leqslant 110^{\prime} 000\right)$, denoting the number of existing restaurants. The next $n$ lines describe the location $x_{i} y_{i}$ of these restaurants $\left(x_{i}, y_{i}\right.$ integers, $\left.\left|x_{i}\right|,\left|y_{i}\right|<2^{24}\right)$. It follows the number $m\left(1 \leqslant m \leqslant 110^{\prime} 000\right)$ of possible locations for the new restaurant, and on the next $m$ lines the coordinates of these locations, in the same format as for the existing restaurants. The input is terminated by a line containing a single number 0 .

**Output** For each possible location for the new restaurant, write on a single line the squared (Euclidean) distance to the closest existing restaurant.