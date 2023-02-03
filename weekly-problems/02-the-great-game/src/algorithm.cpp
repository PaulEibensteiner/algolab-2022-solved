#include <iostream>
#include <vector>

const int MAX_N = 50001;

typedef std::vector<int> VI;

int testcase() {
  int n, m;
  std::cin >> n >> m;  // Reading the number of vertices and edges
  int r, b;
  std::cin >> r >> b;  // Reading the starting positions of the meeples
  std::vector<VI> graph(n + 1, VI());  // Adjacency list
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;     // Reading an edge
    graph[u].push_back(v);  // Store the edge
  }

  VI mini(n + 1, MAX_N);
  VI maxi(n + 1, -1);

  // Set up the starting values of the recursion

  mini[n] = 0;
  maxi[n] = 0;

  // Do the recursive calculations

  for (int i = n - 1; i >= 1; --i) {
    // For all the possible moves from the current position

    for (int v : graph[i]) {
      mini[i] = std::min(mini[i],maxi[v] + 1);  // Mini makes the move
			maxi[i] = std::max(maxi[i], mini[v] + 1); // Maxi makes the move
    }
  }

  int sherlock = mini[r];  // Sherlock needs mini[r] moves to finish the game
  int moriarty = mini[b];  // Moriarty needs mini[b] moves to finish the game

  // Sherlock needs fewer moves

  if (sherlock < moriarty) return 0;
  // Moriarty needs fewer moves

  if (moriarty < sherlock) return 1;
  // Both need the same number of moves but Sherlock wins if and only if

  // the number of moves is not divisible by 2, as the sequence of moves is: //
  // r --> b --> b --> r --> r --> b --> ... s --> m --> s --> m --> s --> m -->
  // ...

  if (sherlock % 2 == 1) return 0;
  return 1;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) std::cout << testcase() << "\n";
}