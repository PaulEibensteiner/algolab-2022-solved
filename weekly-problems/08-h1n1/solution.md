# Solution

## Basic Idea

Use an adapted dijkstra's algorithm to determine the maximum escape size for each triangle in the delaunay triangulation from the outside going in. Then determine for each point which triangle it is in. Then I am check if the triangle's max escape size is bigger than the point's given distance*4 in and if the infected person closest to the point is too close.

## Problems

Boost heap needs compare inside struct but above handle. Easier to use triangulation to save pointers to stuff than handle the circular dependencies otherwise.
