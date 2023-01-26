---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Carsharing

Carsharing is very popular in Algoland. The Algolandians love that they can just pick up a car and drive it from one city to another without having to return it - something that many car sharing systems in other countries do not allow.

This flexible return-policy complicates the management of the car fleet enormously though. For example, if the route from $A$ to $B$ is more popular than the reverse route from $B$ to $A$, we might have to turn some customers down who want to drive from $A$ to $B$, so that we do not run out of cars at station $A$.

You were hired to improve the online booking system that decides which customer can get a car and who has to take the bus. You are given the list of booking requests that contains for each customer when and where he wants to drive and how much money you would earn. You also know how the cars are distributed initially and you can assume that all rental stations have sufficient parking space and that the handover of cars happens instantaneously. You should select a set of booking request that is feasible (all customers that you select can drive their desired route) and optimal (maximizes the profit).

**Input** The first line of the input contains the number of test cases $\mathrm{T}$, each described as follows.

- It starts with a line that contains two integers $\mathrm{N}$ and $\mathrm{S}$, separated by a space. $\mathrm{N}$ denotes the number of booking requests and $S$ the number of rental stations in Algoland. We have $1 \leqslant N \leqslant 10^{\prime} 000$ and $2 \leqslant S \leqslant 10$.

- The second line contains $S$ space-separated integers. These numbers $l_{1}, \ldots, l_{S}$ denote the number of cars placed initially at every rental station. We have $0 \leqslant l_{i} \leqslant 100$ for all $i$.

- The remaining $\mathrm{N}$ lines of each test case describe the booking requests, one request per line. The $i$-th of these lines contains the $i$-th request represented as space-separated numbers $s_{i}, t_{i}, d_{i}, a_{i}, p_{i}$. These represent the indices of the start and target rental station $s_{i}$ and $t_{i}$, the departure and arrival times $d_{i}$ and $a_{i}$ in minutes, and the profit $p_{i}$ that you would make by satisfying this request. We have $1 \leqslant s_{i}, t_{i} \leqslant S, 0 \leqslant d_{i}<a_{i} \leqslant 100^{\prime} 000$ and $1 \leqslant p_{i} \leqslant 100$.

**Output** For each test case output a line with a single integer $p$, the maximum profit that the carsharing system in Algoland can achieve.

**Points** There are five groups of test cases, worth 20 points each.

- In the first three groups of test cases, all times are at most 10'000 and multiples of 30 minutes.

- In the first four groups of test cases, there are only two rental stations $(S=2)$.

1. For the first group of test cases, you may assume that there is only a single car $\left(l_{1}+l_{2}=1\right)$.

2. For the second group of test cases, you may assume that there are only at most 20 booking requests $(N \leqslant 20)$

3. For the third group of test cases, there can be many booking requests.

4. For the fourth group of test cases, the booking times are no longer constrained to half hours below $10^{\prime} 000$.

5. For the fifth group of test cases, there are no additional assumptions.

Corresponding sample test cases are contained in testi.in/out, for $i \in\{1,2,3,4,5\}$.

This task is based on the paper "Scheduling Transfers of Resources over Time: Towards Car-Sharing with Flexible Drop-Offs" by Kateřina Böhmová, Yann Disser, Matúš Mihalák, and Rastislav Srámek.