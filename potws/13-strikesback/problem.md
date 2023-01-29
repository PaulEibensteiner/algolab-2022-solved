---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - The Empire Strikes Back
The base of the Rebel army on planet Hoth has been captured by the Imperial fleet with the use of their unbeatable gigantic AT-AT Walkers. Luckily, Han Solo, Princess Leia, C-3PO and Chewbacca manage to escape on the Millennium Falcon. After a long and difficult trip, our heroes find themselves hiding in the Anoat Asteroid Belt.

The situation inside the asteroid field is dangerous. There are numerous asteroid particles that could potentially damage the ship. Fortunately, the Falcon is not completely helpless: that is what Quadlasers are for! The Falcon's radar system has identified all particles that need to be destroyed. The particles have two characteristics: their location and their density. The higher the density of a particle, the more energy is needed to destroy it. Han plans to program the Quadlasers to shoot all those dangerous particles.

A Quadlaser aims and shoots an energy beam at a specific point, thereby creating a circular explosion around this point. Both the radius of this explosion and the amount of energy in the beam can be adjusted individually for each shot. It appears, though, that the hyperspace drive system of the Falcon that is used to aim the Quadlasers is malfunctioning. As a consequence, the laser can only aim at a limited number of points.

As if all this was not enough trouble, Darth Vader has summoned a group of bounty hunters to assist in tracking the Falcon. Some of the bounty hunters are about to close in on the Falcon and have already reached the Anoat Asteroid Belt. If the explosion of a beam gets noticed by a bounty hunter—that is, his distance to the center of the explosion is at most the radius—he can easily guess where the beam was shot from and thus locate the Falcon. For our heroes, being discovered would mean getting captured...

Your mission is to help Han program the Quadlasers. A particle can be destroyed over the course of one or several laser shots. Every particle is affected by all shots for which it is in the radius of the explosion. But the larger the distance to the center of the explosion (the spot the laser aimed at), the less energy reaches the particle. More precisely, the total energy that reaches a particle is given by the formula

$$
\sum_{i} \frac{e_{i}}{\max \left\{1, d_{i}^{2}\right\}},
$$

where $e_{i}$ is the energy of the $i$-th shot, $d_{i}$ is the distance to the point the i-th shot aims at^1^, and $i$ runs over all shots for which the particle is in the radius of the explosion, that is, $d_{i} \leqslant r_{i}$, where $r_{i}$ is the radius of the $i$-th shot. A particle is destroyed, if the total energy that reaches it is at least as large as the particle's density.

The conditions are extreme and the supply of energy on board of the Falcon is limited. Your task is to eliminate (if possible) all asteroid particles using no more energy than available and without getting noticed by any bounty hunter.

^1^ The maximum in the denominator is there only to address the case $d_{i}=0$.

**Input** The first line of the input contains the number $t \leqslant 30$ of test cases. Each of the $t$ test cases is described as follows.

- It starts with a line that contains three integers $a\ s\ b$, separated by a space and such that $1 \leqslant a \leqslant 30,1 \leqslant s \leqslant 10^{4}$, and $0 \leqslant b \leqslant 10^{5}$. Here $a$ denotes the number of asteroid particles, $s$ denotes the number of laser shots, and $b$ denotes the number of bounty hunters.

- Then comes a line with one integer $e$ such that $0 \leqslant e \leqslant 10^{6}$. Here $e$ denotes the available energy on board of the Falcon.

- The following $a$ lines define the positions and densities of the asteroid particles. Each line contains three integers $x\ y\ d$, separated by a space and such that $|x|,|y|<2^{24}$ and $1 \leqslant d \leqslant 2^{3}$.

- The following $s$ lines denote the positions of the shooting points (the spots the laser aims at). Each line contains two integers $x\ y$, separated by a space and such that $|x|,|y|<2^{24}$.

- The final $b$ lines denote the positions of the bounty hunters. Each line contains two integers $x y$, separated by a space and such that $|x|,|y|<2^{24}$.

**Output** For each test case the corresponding output appears on a separate line. It consists of a single character: `y`, if it is possible to destroy all asteroid particles as required, and `n`, otherwise.

**Points** There are four groups of test sets, worth 100 points in total.

1. For the first group of test sets, worth 40 points, you may assume $s \leqslant 100$ and $b=0$.

2. For the second group of test sets, worth 30 points, you may assume $s, b \leqslant 100$.

3. For the third and fourth group of test sets, worth 15 points each, there are no additional assumptions.

Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3\}$.


