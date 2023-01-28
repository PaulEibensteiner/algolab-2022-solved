# Solution

## Problem in a nutshell

Given a tree with weighted nodes, calculate the minimum weight sum node subset such that for each node: Either it is included, it's parent or one of it's children.

## Solution basic idea

Dynamic programming bottom up or top down. For fourth testcase it is necessary to not be quadratic in the number of children for each node. For this, we need to realize that the minimum weight sum when including one of the children is equal to including the child, where the difference between it being included and it not being included is the smallest.