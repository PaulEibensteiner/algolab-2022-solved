---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22 Department of Computer Science Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---
# Exercise - Octopussy

Bond took over a case from Agent 009 who met an untimely end in the British embassy in East-Berlin. During his investigations James meets Octopussy, a mysterious, beautiful, and fabulously wealthy woman. She lives in a luxurious island palace, from where she runs a wide network of business enterprises such as shipping, hotels, carnivals, and circuses. A less known fact is that Octopussy also is a successful jewellery smuggler. Together with her friend Kalam Khan-an exiled prince-she uses the circus as a cover for various illegal activities.

While trying to infiltrate the smuggling operation, Bond discovers a much greater threat. Khan has a grand evil plan which even Octopussy is oblivious of. He uses Octopussy's circus to hide a nuclear warhead in each of $n$ balls $B_{0}, \ldots, B_{n-1}$, which play a central role in one of the circus' acts. The warheads are set to explode during a performance at an US Air Force base in West Germany so as to start World War III.

The bombs have timers which activate at the start of the show. The timer in $B_{i}$ lets the bomb explode exactly $t_{i}$ minutes after activation. After revealing Khan's plans, Bond convinces Octopussy to work with him against Khan to deactivate the bombs. Fortunately, Octopussy gained some crucial information just before the start of the show: the bombs are connected in a sophisticated way in order to make them, as Khan believes, impossible to deactivate. These connections depend on the position of the balls, in the following way:

1. $B_{j}$ stands on both $B_{2 j+1}$ and $B_{2 j+2}$, for $j \in\left\{0, \ldots, \frac{n-3}{2}\right\}$;

2. for $j \in\left\{\frac{n-1}{2}, \ldots, n-1\right\}$, the ball $B_{j}$ is on the ground (and not on any other ball).

You may assume that $n$ is always odd. If $B_{i}$ stands on $B_{j}$, then trying to deactivate the bomb in $B_{i}$ before deactivating the bomb in $B_{j}$ triggers their explosion.

It takes Bond one minute to deactivate a bomb. Doing so takes his full attention and so he can deactivate exactly one bomb per minute. As the balls are close to each other, we assume that Bond can instantly (without any loss of time) move from one bomb to any other. Is it possible for 007 to save the world and deactivate all bombs in time, without triggering an explosion?

**Input** The first line of the input contains the number $t \leqslant 50$ of test cases. Each of the $t$ test cases is described as follows.

- It starts with a line that contains one integer $n$, the number of balls $\left(n=2^{i}-1\right.$, for $i \in\{1, \ldots, 16\})$.

- The following line defines the individual explosion times of the bombs. The line contains $n$ integers $t_{0} \ldots t_{n-1}$, separated by a space, and such that $1 \leqslant t_{i} \leqslant 2^{30}$, for $i \in$ $\{0, \ldots, n-1\}$

**Output** For each test case the corresponding output appears on a separate line. Output the string 'yes', if Bond can deactivate all bombs, that is if there is a permutation $\pi:\{0, \ldots, n-1\} \rightarrow$ $\{0, \ldots, n-1\}$ (which we interpret as 'the bomb in $B_{i}$ is the $\pi(i)$-th bomb to be deactivated') such that

- $\pi(i)<t_{i}$, for every $i \in\{0, \ldots, n-1\}$, and

- $\pi(x)<\pi(y)$, for each pair $(x, y)$ such that $B_{y}$ stands on $B_{x}$.

If such a permutation does not exist, output the string 'no'.

**Points** There are four groups of test sets, each of which is worth 20 points. For each group there is also a corresponding hidden test set that is worth 5 points. So, there are $4 \cdot 20+4 \cdot 5=100$ points in total.

1. For the first group of test sets you may assume that there are no more than 7 bombs $(n \leqslant 7)$

2. For the second group of test sets you may assume that there are no more than $5 \cdot 10^{3}$ bombs and that the explosion times respect the 'stand on'-order $\left(n \leqslant 5 \cdot 10^{3}\right.$ and for all $i, j \in\{0, \ldots, n-1\}:$ if $B_{i}$ stands on $B_{j}$, then $t_{i}>t_{j}$ ).

3. For the third group of test sets you may assume that there are no more than $5 \cdot 10^{3}$ bombs $\left(n \leqslant 5 \cdot 10^{3}\right)$

4. For the fourth group of test sets there are no additional assumptions.

Corresponding sample test sets are contained in testi. in/out, for $i \in\{1,2,3,4\}$.

**Sample Input**

76551289

3

311

**Sample Output**

yes

no