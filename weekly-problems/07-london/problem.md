---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - London

Phileas Fogg is a rich British gentleman, living a modest life in London with his valet Jean Passepartout. Most of his spare time is spent at the Reform Club, where he stays until midnight every day reading The Daily Telegraph. On Wednesday, 2 October 1872, he reads an article which claims that it is now possible to travel around the world in 80 days thanks to the opening of a new railway section in India. After a heated argument with his fellow club members, he accepts a wager for $£ 20^{\prime} 000$ to complete the journey within this time period. Having no time to lose, Fogg and Passepartout set forth at once. Their first objective is to board the steamer Mongolia, to bring them from Brindisi via Suez to Bombay.

On the same day, a major bank robbery takes place. Scotland Yard has reason to believe that the robber is no ordinary man, but a gentleman from the Reform Club. The only trace left at the crime scene is an anonymous note made out of separate letters cut from a newspaper. The note seems to be made in order to mislead the detectives, but it can instead reveal information about the robber. Since the Reform Club and all its members are known to pride themselves on only reading from The Daily Telegraph, Scotland Yard wants to confirm their suspicion by verifying that the anonymous note could indeed be made from that particular newspaper.

The Daily Telegraph has two sides: a front side and a back side. Both sides contain text printed as $h$ lines of $w$ letters each. The font is fixed-width so that every letter from the front side has exactly one corresponding letter on its back. This way cutting out a single letter from the front side results in a small piece of paper that has another letter on its back. By cutting up the page into such small pieces with a single letter on each side, many different notes can be written by arranging and flipping the pieces and putting some (or all) of them in sequence.

Help Scotland Yard to determine if the anonymous note could have possibly been made by cutouts from The Daily Telegraph.

Input The first line of the input contains the number $t \leqslant 30$ of test cases. All newspaper and note characters are capital English letters from A to Z (no whitespaces, punctuation, accents, or other special characters). Each of the $t$ test cases is described as follows.

- The first line contains two integers $\mathrm{h} \mathrm{w}$, separated by a space. They denote

$-h$, the number of lines in the newspaper $\left(2 \leqslant h \leqslant 10^{3}\right)$;

$-w$, the number of letters on every line of the newspaper $\left(2 \leqslant w \leqslant 10^{3}\right)$.

- The second line defines the note from the crime scene. It consists of a single string of $n$ letters $\left(2 \leqslant n \leqslant 10^{6}\right)$. Note that $n$ need not be equal to the number of newspaper pieces.

- The following $\mathrm{h}$ lines define the text on the front side of the newspaper. Each line contains exactly $w$ letters.

- The final $h$ lines define the text on the back side of the newspaper. Each line contains exactly $w$ letters. Note that on the back of the $i$-th line from the front side of the newspaper is the $i$-th line from the back side, for $i \in\{0, \ldots, h-1\}$. For every line of the newspaper, on the back of the $j$-th letter from the front side is the $(w-j-1)$-th letter from the back side, for $j \in\{0, \ldots, w-1\}$.

Output For each test case output one line with a single word "Yes" or "No", indicating whether or not the note can be composed from the given newspaper page.

Points There are five groups of test sets, worth 100 points in total.

1. For the first group of test sets, worth 10 points, you may assume that all letters on the back side of the newspaper are identical and that $h, w \leqslant 30$.

2. For the second group of test sets, worth 10 points, you may assume that only two different letters appear on the back side of the newspaper and that $h, w \leqslant 30$.

3. For the third group of test sets, worth 20 points, you may assume $h, w \leqslant 30$.

4. For the fourth group of test sets, worth 20 points, you may assume $h, w \leqslant 10^{2}$.

5. For the fifth group of test sets, worth 40 points, there are no additional assumptions.

Corresponding sample test sets are contained in test $i$. in/test $i$. out, for $i \in\{1,2,3,4,5\}$. 