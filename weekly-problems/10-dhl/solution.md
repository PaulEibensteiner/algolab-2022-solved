# Solution

## Basic Idea

1. Subtract 1 from a,b so we can ignore the -k term in the cost.
2. Try writing down the matrix M with Mij = aibj, and visualize what the total costs are made up of, and try designing a more efficient recursive relation.
3. Costs are the sum of rectangular boxes connected at the corners from top-left to buttom-right. Boxes with both width and height >1 can always be replaced by subboxes with either width or height = 1.
4. For the minimum cost starting from top-left to ij, we find the minimum cost from top-left to (i-1,j) or (i-1,j-1) or (i,j-1) and add aibj.
5. Since the recursive relation is local in i,j. We only need to maintain a 1D dynamic programing array and update it for each row and read the final result at last. Then we can pass test 4 in 0.02s.