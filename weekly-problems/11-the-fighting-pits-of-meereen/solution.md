# Solution

## Basic Idea

Basic dynamic programming example, challenge is to reduce state space as much as possible. Tricks:

1. Lengths of lists can't be further apart then 12 (round would be negative) therefore saving the remaining list length and the difference between the current ones saves a lot.

2. States can be mirrored (i.e. longer list and shorter list)

3. Only need $m-1$ fighters for the remaining excitement.