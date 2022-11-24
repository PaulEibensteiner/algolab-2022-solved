# Solution

## Basic Idea

Two rectangles constrain each other only in the dimension, in which they are further away from each other. Therefore it is possible to create constraints between each adjustable rectangle (n) and all other rectangles (n+m). This can be further optimized by sorting the distances by which the vertices are constrained and only creating one constraint for the minimum such distance, which leads to $n^2 + n$ constraints (not implemented in code). Unfortunately CGAL sucks.