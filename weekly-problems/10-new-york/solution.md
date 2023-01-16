# Solution

## Problem in a nutshell

Given a dag with integer weights on the nodes, find all nodes $n$ who have a path starting at $n$ of length $k-1$ and maximum weight difference between the nodes in the path of $k$.

## Basic Idea

Do DFS while keeping track of $k-1$ parent's indices and the current maximum and minimum value of these parent's weights.

## Challenges

Efficient access to the important operations. A linked list enables lenghtening/shortening in $O(1)$, a tree insertion in $O(log n)$, max/min in $O(1)$ and deletion in $O(1)$.
