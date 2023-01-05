# Solution

## Basic Idea

Construct a flow that is constrained, such that every unit of the max flow corresponds to a tile placed. Since it does not matter which of the tiles is the “beginning” and which is the “end” this can easily be done. Half of the positions is defined to be “beginnings” (positioned like the white tiles of a chess board) and half to be “ends” (what would be the black tiles). For every position that is free in the input, an edge is created either from the source (“beginnings”) or to the sink (“ends”). Then from every active “beginning” an edge is created to every active adjacent “end”. All edges are of capacity one.