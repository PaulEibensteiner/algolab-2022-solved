# Solution

## Basic Idea

The problem is basically the Knappsack problem with 30 elements plus the possibility to add the potion gulps.

The easiest solution for 60 points is just brute forcing every possible combination of movements, and calculating the gulps needed to succeed with this combination of movements via binary search. This yields a runtime of $O(2^n \cdot \log m)$

The solution for 100 points uses split and list to search for a feasible combination of movements. To this end, for every number of gulps $i$ that is tried, all combinations of half the moves are sorted by the distance they cover given the number of gulps. Then all combinations, that are worse in both regards (lower distance and higher time) than any another combination are discarded. This guarantees that binary searching in this set of combinations for the minimum distance that is big enough also yields the minimum time possible. Finally a binary search in the number of gulps is performed, where for every search step the split and list technique is applied to the moves as stated before.
