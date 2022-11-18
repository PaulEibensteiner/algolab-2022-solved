---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Coin Tossing Tournament

You play an exciting game of chance with your fellow computer science students. First of all, you agree on a schedule of rounds. In each round two players face each other. The number of rounds and the players who compete in each round are predetermined before the proper game starts. Then, the outcome of each round is decided by a simple coin toss - the winner gets one point, the loser zero. In the end the points of each player are added up and the scoreboard with each player's result is assembled. Whoever has the lowest score does the homework for everyone else.

You happened to play such tournament on a particularly pleasant Friday night. You wrote down the schedule of rounds, but in the ensuing excitement you did not manage to record all the results of the coin tosses - only some of them. Now, your friends show you a scoreboard that clearly indicates you lost! Good-hearted as you are, you would like to check if it is even possible to obtain this scoreboard given the schedule of matches and the results you had noted. After all it should take some non-trivial effort to play a prank on you...

Input The first line of the input contains the number of test cases $1 \leqslant t \leqslant 200$. Each test case is described as follows.

- It starts with a line containing two integers $n, m$ separated by a single space $(1 \leqslant n \leqslant 200$, $1 \leqslant m \leqslant 1000)$, the number of players and rounds played, respectively. The players are numbered from 0 to $n-1$.

- The next $m$ lines each describe one round of the game: each contains three integers $a, b, c$ separated by single spaces $(0 \leqslant a, b<n$ and $a \neq b)$ indicating a round was played between players $a$ and $b$. The result of the coin toss is given by $c$ :

$$
\begin{aligned}
-c &=1 \text { : player a won; } \\
-c &=2: \text { player b won; } \\
-c &=0 \text { : you did not write down the winner. }
\end{aligned}
$$

(c always takes one of these three values.)

- On the final line of the test case, there are $n$ integers $s_{0}, \ldots, s_{n-1}$ (with $0 \leqslant s_{i} \leqslant 2^{10}$ ) separated by single spaces, where $s_{i}$ is the score of player $i$ according to the final scoreboard.

Output For each test case decide if it is possible to assign results to the rounds marked with $\mathrm{c}=0$ such that the final standings match the scoreboard specified in the input. Indicate the result with one word on a single line: either yes or no.

**Sample Input**

2
4 4
0 1 1
1 2 2
2 3 1
3 0 0
2 0 1 1
3 3
0 1 0
2 1 0
2 0 0
0 2 1

**Sample Output**

no

yes

Explanation In the first test case, player 2 already scored 2 points, so they cannot finish with only 1 point in the scoreboard.

In the second test case, if player 1 wins both their matches and player 2 wins the match with player 0 , the desired scoreboard is achieved.