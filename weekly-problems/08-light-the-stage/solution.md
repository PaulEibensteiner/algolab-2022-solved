# Solution

## Basic Idea

The first group of test sets is easy: Create a Delaunay triangulation of the lamps $O(n \log n)$. Then for each participant, find the closest lamp $O(m\log n)$ and if it is closer than the lamp radius plus the person’s radius, remove the person from the winning set. For the remaining test sets just performing the search for each partial set of lamps is too expensive $O(n m \log n)$. But we can binary search for the amount of lamps needed to remove all participants, and then output the people removed in the run with one lamp less.