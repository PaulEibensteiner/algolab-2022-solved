# Solution

## Basic Idea

Same as the example ‘Interval Scheduling’ from the slides. The only difference is that the end points of the boats are not fixed, and must be calculated based on the last currently set boat. 

When taking the next boat (in order of $p$ value) as a ‘default’ for the next proposed endpoint, we only need to consider boats with their $p$ value inside the last currently set boat and the next end point given by this ‘default’ (since any boat with a $p$ value bigger than this would necessarily also have a bigger end point). Additionally, we can discard all the considered boats after selecting one (since they’re $p$ value is smaller than the new end point). Therefore we only need to calculate the end point for each boat once, and have the same runtime as in ‘Interval Scheduling’ $O(n \log n)$.

## Difficulties

Determining the end point calculations and proofing that the greedy algorithm actually works.