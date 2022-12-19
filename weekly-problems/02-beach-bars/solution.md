# Solution

## Basic Idea

Sort the input and use a sliding windows approach, while keeping track of the current longest distance from the window center and the number of elements in the window. When the first and last elements in the window grow to far apart shrink the window. Else expand it to the next element.