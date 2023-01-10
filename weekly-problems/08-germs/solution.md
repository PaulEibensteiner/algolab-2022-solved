# Solution

## Basic Idea

Calculate the maximum squared distance each bacterium can grow. It is the minimum of the closest next bacterium (divided by four) and it's closest squared distance to the x and y borders. Sort these values, and take the ones corresponding to the right percentile (0th, n/2 floored and n-1th). Convert these values to time values: $t=\sqrt{\sqrt{r^2}-\frac 1 2)}$

## Challenges

Correctly handle cases where there is only one vertex (skip edge iteration) and where $r < \frac 1 2$ (output t=0)