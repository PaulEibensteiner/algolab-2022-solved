---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - On Her Majesty's Secret Service

James Bond is out there again, saving the world. This time his mission takes him into the Swiss Alps, to the Schilthorn. With 2'970 meters, this summit overlooks the valley of Lauterbrunnen in the Bernese Oberland and features a panoramic view of the Alps. But James is not here for the view: On top of Piz Gloria, the evil mastermind and head of SPECTRE Ernst Stavro Blofeld set up a secret allergy-research institute where he hypnotizes and brainwashes his patients to prepare them for bacteriological warfare.

Bond and his fellow agents surrounded the compound and spread throughout the mountain. But they are in great danger! Blofeld threatens to launch a huge avalanche that would bury the whole mountain resort instantly. Fortunately, all agents are on skis so that they can escape quickly and hide inside some high-security shelters nearby. Your task is to compute the minimum advance warning time, such that every agent can enter a shelter before the avalanche launch.

To reach a shelter the agents can use slopes and ski lifts. But moving around takes time. Time is also required to enter a shelter, which involves a protocol including a retina scan and voice recognition tests. At every shelter, the entering protocol can be performed by at most one agent at a time. If an agent wants to enter a shelter while another agent is still in protocol there, (s)he has to wait. Finally, the capacity of each shelter is limited. Therefore, careful coordination is required to decide who hides where...

**Input** The first line of the input contains the number $t \leqslant 30$ of test cases. Each of the test cases is described as follows:

- It starts with a line that contains six integers $n\ m\ a\ s\ c\ d$, separated by a space. They denote
  - $n$, the number of relevant positions $p_{0}, \ldots, p_{n-1}$ around Schilthorn $\left(1 \leqslant n \leqslant 10^{3}\right)$.

  - $m$, the number of slopes and ski lifts around Schilthorn $\left(0 \leqslant m \leqslant 5 \cdot 10^{3}\right)$.

  - $a$, the number of secret agents $\left(1 \leqslant a \leqslant 10^{2}\right)$.

  - $s$, the number of shelters $\left(1 \leqslant s \leqslant 10^{2}\right)$.

  - $c$, the capacity of each shelter $(1 \leqslant c \leqslant 2)$.

  - $d$, the time (in seconds) an agent needs to perform the entering protocol at a shelter $\left(1 \leqslant d \leqslant 10^{3}\right)$.


- The following $m$ lines describe the slopes and ski lifts around Schilthorn. Each line contains four entities $w\ x\ y\ z$, separated by a space, where $w \in\{S, L\}$ is a character and $x, y, z$ are integers with $0 \leqslant x, y \leqslant n-1$ and $1 \leqslant z \leqslant 10^{4}$. If $w=s$, then the line describes a slope that an agent can use to ski from $p_{x}$ to $p_{y}$ in $z$ seconds (in this direction only). Otherwise, $w=L$ and the line describes a ski lift between $p_{x}$ and $p_{y}$. A lift can be used in both directions, each taking $z$ seconds. Slopes and lifts can be used by arbitrarily many agents at the same time. 

- The following line describes the starting positions of the agents. The line contains a integers $\alpha_{0} \ldots \alpha_{a-1}$, separated by a space and such that $0 \leqslant \alpha_{i} \leqslant n-1$, for $i \in\{0, \ldots, a- 1\}$. This means that agent $i$ starts at $p_{\alpha_{i}}$.

- The following line describes the positions of the shelters. The line contains $s$ integers $\sigma_{0}$ $\ldots \sigma_{s-1}$, separated by a space and such that $0 \leqslant \sigma_{i} \leqslant n-1$, for $i \in\{0, \ldots, s-1\}$. This means that shelter $i$ is located at $p_{\sigma_{i}}$.

Note: There may be multiple shelters and/or agents at the same position.

**Output** For each test case, output a line with one integer $t$, the minimum number of seconds needed until all agents safely entered a shelter. You may assume that there always exists a way such that all the agents can reach and enter a shelter.

**Points** There are five groups of test sets, which are worth 75 points in total, and five corresponding hidden test sets, each of which is worth 5 points. So there are 100 points in total.

1. For the first group of test sets, worth 20 points, you may assume that James Bond is on his own $(a=1)$.

2. For the second group of test sets, worth 20 points, you may assume that only one agent fits into each shelter and it takes either 9 or 10 seconds for all agents to safely enter a shelter $(\mathrm{c}=1$ and $\mathrm{t} \in\{9,10\})$.

3. For the third group of test sets, worth 10 points, you may assume that only one agent fits into each shelter and no more than 10 seconds are needed for all agents to safely enter a shelter $(c=1$ and $t \leqslant 10)$.

4. For the forth group of test sets, worth 10 points, you may assume that only one agent fits into each shelter $(c=1)$.

5. For the fifth group of test sets, worth 15 points, there are no additional assumptions.

Hint: Note that for almost all the subtasks, only a single agents fits into each shelter $(c=1)$. Try to solve this case first and let the restrictions of the many subtasks guide you to the full solution!

Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3,4,5\}$. 
