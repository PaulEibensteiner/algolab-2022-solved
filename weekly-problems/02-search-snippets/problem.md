---
Eidgenössische Technische Hochschule Zürich Swiss Federal Institute of Technology Zurich Algorithms Lab HS22

Department of Computer Science

Prof. Dr. A. Steger, Prof. Dr. E. Welzl cadmo.ethz.ch/education/lectures/HS22/algolab
---

# Exercise - Search Snippets

A high-school friend of yours has recently founded a startup. He is marketing a new product for searching the extensive archives that major companies tend to accumulate over the years of their existence.

A first user study at the offices of National Office Hardware (NOH) was recently conducted, to compare the new product to certain well-known web search engines. Most of these engines display short text snippets that show some context of where the search terms came up. Users at NOH asked for a similar feature in your archive search tool.

Inevitably, your friend asks you to assist him in designing a proper way of finding suitable snippets. You decide to look for a single, contiguous, shortest possible (measured in the number of words contained) snippet that contains all the search terms.

You are given, for each word and document, a list of the positions at which this word occurs. For instance, in the preceding three paragraphs the word "snippets" appears as the 69th and the 110th word, and so the corresponding list of positions (counting from zero) is $(68,109)$.

As your program will be run for every document matching a query, it must be very fast even on large documents!

**Input** The first line of the input contains the number $t \leqslant 40$ of test cases. Each of the following $t$ test cases describes a word/position index for one document.

- It starts with a line that contains an integer $n$, denoting the number of words in the query, and such that $2 \leqslant n \leqslant 2^{11}$.

- The following line contains $n$ integers $m_{0} \ldots m_{n-1}$, separated by a space, where $m_{i}$ denotes the number of times word $i$ occurs within the document, and such that $1 \leqslant m_{i} \leqslant 2^{16} / \mathrm{n}$.

- $n$ lines follow. The $i$-th such line contains $m_{i}$ integers $p_{i, 0} \ldots p_{i, m_{i}-1}$, separated by single spaces, such that $0 \leqslant p_{i, 0}<\ldots<p_{i, m_{i}-1} \leqslant 2^{30}$. Each $p_{i j}$ denotes one position of the $i$-th word in the document. Within a test case, you may assume that all $p_{i j}$ are pairwise distinct.

**Output** For each test case output a single line consisting of one non-negative integer, the length $b-a+1$ of a shortest possible interval $[a, b]$ such that every word occurs at least once within $[a, b]$. (That is, for every $i \in\{0, \ldots, n-1\}$, there is a $j \in\left\{0, \ldots, m_{i}-1\right\}$ with $p_{i j} \in[a, b]$.)

**Points** There are three groups of test sets, worth 100 points in total.

1. For the first group of test sets, worth 50 points, you may assume that $n=2$.

2. For the second group of test sets, worth 25 points, you may assume that $n \leqslant 2^{8}$.

3. For the third group of test sets, worth 25 points, there are no additional assumptions.

Corresponding sample test sets are contained in testi.in/out, for $i \in\{1,2,3\}$.
