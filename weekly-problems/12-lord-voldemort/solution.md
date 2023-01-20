# Solution

## Problem in a nutshell

In a vector of $n$ elements, find $m$ non overlapping continuous subsequences, each with sum $k$, and such that the sum of cardinalities is maximal.

### Basic Idea

Create set of potential subsequences using the sliding window approach. Then find the correct maximum elements covered by $m$ subsequences using a flow formulation or dynamic programming.
