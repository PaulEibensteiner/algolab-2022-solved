# Solution

## Basic Idea

To check if a solution is possible, create a flow graph, where one point can 'flow' from the source to each game, and from each game one point can flow to either of player a and b. Finally set edges from each player to the sink with weights equal to the player's total scored points. This way, a maximum flow will try to 'fill' the players total scored points, if possible by the given games.

The only logical constraint that is not considered yet is, that every game *must* have a winner i.e. a point distributed to either player a or b. To make sure this constraint is fulfilled by the given total scores as well, it is only necessary to check if the sum of the total scores is equal to the number of games. If it is not, it can not be valid scores.

Now we know that in the flow, every game must give exactly one point (to build the correct sum) and each player must receive the given amount of points by a valid game.

## Implementation

We can remove the known games from the graph, and only consider the unknown scores to further reduce complexity.