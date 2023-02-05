---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Clues

Holmes and Watson are out on the streets to keep an eye on various people and places, hoping to obtain clues regarding criminal activities. Each of them carries a radio set and they want to coordinate through it as soon as something interesting happens. As the area of interest is quite large, Holmes and Watson cannot maintain a direct connection throughout the investigation. Instead they setup a network of radio stations to route the communication. In the following we use the term clients to refer to radio sets and radio stations collectively. All clients have the same operation range $r$ so that they can communicate with every client in distance at most $r$.

For the actual communication there are four different frequencies available. Any client can receive on all frequencies. But in order to avoid interferences, any two clients that are in range of each other must send on different frequencies. Each of the two radio sets has one exclusive sending frequency assigned to it. This leaves two frequencies for the stations to work with. To keep the protocol simple, Holmes wants to assign one fixed frequency to each station so that the station sends on this frequency only. Is it possible to achieve such an assignment without generating any interferences? If so, which collections of clues can be routed within this network between Holmes and Watson?

The radio sets are "intelligent" in the sense that they automatically select the client to connect to. If the other radio set is in range, they connect to the other radio set. Otherwise-if any station is in range - they select the station with the strongest signal (closest client) to connect to. You may assume that this station is unique in all test instances.

**Input** The first line of the input contains the number $t \leqslant 30$ of test cases. Each of the $t$ test cases is described as follows.

- It starts with a line that contains three integers $n\ m\ r$, separated by a space and such that $1 \leqslant n, m \leqslant 9 \cdot 10^{4}$ and $0<r<2^{24}$. Here $n$ denotes the number of stations, $m$ denotes the number of clues, and $r$ denotes the operation range of the clients.

- The following $n$ lines define the positions $s_{0}, \ldots, s_{n-1}$ of the stations. You may assume that these positions are pairwise distinct.

- The final $m$ lines define the $m$ clues. Each clue is defined by two positions $a_{i}$ and $b_{i}$, for $i \in\{0, \ldots, m-1\}$, where $a_{i}$ describes the position of Holmes and $b_{i}$ describes the position of Watson at the moment when this clue is obtained.

Each position is described by two integer coordinates $x \mathrm{y}$, separated by a space and such that $|x|,|y|<2^{24}$.

**Output** For each test case output a line with one character " $\mathrm{n}$ " or "n" per clue, that is, a string $c_{0} c_{1} \cdots c_{m-1}$ of $m$ characters. For each $i \in\{0, \ldots, m-1\}$, the character $c_{i}$ is "y", if and only if clue $i$ can be routed within this network, as defined in the next paragraph.

Denote the set of stations by $S=\left\{s_{0}, \ldots, s_{n-1}\right\}$. A network without interferences on $S$ corresponds to a map $f: S \rightarrow\{0,1\}$ such that $f(u) \neq f(v)$, for all $u, v$ with $\|u-v\| \leqslant r$. A clue can be routed from $a_{i}$ to $b_{i}$, if there exists a network without interferences on $S$ and there exist $k \in \mathbb{N}$ and a sequence $t_{0}, \ldots, t_{k}$, such that

1. $t_{0}=a_{i}, t_{k}=b_{i}$, and $t_{j} \in S$, for $j \in\{1, \ldots, k-1\}$;

2. $\left\|t_{j}-t_{j-1}\right\| \leqslant r$, for all $j \in\{1, \ldots, k\}$;

3. If $t_{1} \neq b_{i}$ (and, thus, $t_{k-1} \neq a_{i}$ ), then $t_{1}$ is the (unique) client from $S$ that is closest to $a_{i}$ and $t_{k-1}$ is the (unique) client from $S$ that is closest to $b_{i}$.

**Points** There are four groups of test sets, worth 100 points in total.

1. For the first group of test sets, worth 20 points, you may assume that $n \leqslant 5^{\prime} 000, m=1$, and $a_{0}=b_{0}$. (Effectively, this reduces to the question of whether or not there exists a network without interferences.)

2. For the second group of test sets, worth 30 points, you may assume that there exists a network without interferences on $S$ and $m \leqslant 20$.

3. For the third group of test sets, worth 30 points, you may assume that there exists a network without interferences on $S$.

4. For the fourth group of test sets, worth 20 points, there are no additional assumptions.

Corresponding sample test sets are contained in testi. in/out, for $i \in\{1,2,3,4\}$.

