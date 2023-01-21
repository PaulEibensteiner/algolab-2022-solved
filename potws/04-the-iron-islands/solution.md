# Solution

## Basic Idea

*Reformulation of the problem*: Given is a tree, where every node has only one child apart from the root node which has up to $n$ children, and each node has a weight. Find a path with weight sum $k$ and maximum length.

## Testcases 1 and 2

Use the sliding window idea for the “arms” of the tree and calculate the sub sums of the start of the arms up to the weight sum that is needed. Then try every combination of the arm’s subsums. Problematic, because there can be up to $n$ arms, which leads to $O(n^2)$ runtime if every combination is checked

## Binary Search Solution

Do as in previous solution, but save the sub sums in a vector, with additional information from which “arm” they come. Sort this vector $O(n \log n)$. Then for each element of the vector perform binary search to find the missing sub sum, while discarding sub sums that come from the same arm. $O(n \log n)$

## Heap solution

Again save the sub sums in a sorted data structure $O(n \log n)$, but this time for each sub sum, save maximally two entries (the ones with the maximum amount of vertices, suffices because we only care about matching two sub sums and that is now guaranteed to be possible). Now find sub sums that sum to $k$ by iterating through the data structure from the front and the back at the same time. $O(n)$

