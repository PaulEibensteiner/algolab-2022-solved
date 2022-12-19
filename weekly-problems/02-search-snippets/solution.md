# Solution

## Basic Idea

- Sort all positions while keeping track of the words the positions belong to
- Use a sliding windows approach and keep track
  - How often each word is occuring in the current window (array of size $n$)
  - How many different words there are in the current window (change if counter of any word switches from or to 0)
- When the counter for different words is equal to $n$:
  - Update the minimum if the current interval from first to last item in the window is smaller than the current minimum