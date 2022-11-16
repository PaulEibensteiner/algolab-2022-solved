#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdbool.h>
#include "prettyprint.hpp"
#include <stack>

using namespace std;

int N;

 // function to check whether the position is safe or not 
bool isSafe(vector<vector<int>>& board, int row, int col) 
{ 
    int i, j; 
    for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) 
            return false; 
    for (i = row, j = col; j >= 0 && i < N; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true; 
} 

// The function that solves the problem using backtracking 
int solveNQUtil(vector<vector<vector<int>>>& boards, vector<vector<int>> current_board, int col) 
{ 
    if (col >= N) {
		boards.push_back(current_board);
        return 1; 
	}
  
	int num_placements = 0;


	for (int i = 0; i < N; i++) { 
	//if it is safe to place the queen at position i,col -> place it
		if (isSafe(current_board, i, col)) { 
			current_board[i][col] = 1;
			num_placements += solveNQUtil(boards, current_board, col + 1);
			current_board[i][col] = 0;
		} 
	} 
  
   
    return num_placements; 
}


bool isPossible(vector<vector<int>>& board, int row, int col) 
{ 
    int i, j; 
    for (i = 0; i < row; i++) 
        if (board[i][col]) 
            return false; 

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) 
            return false; 
    for (i = row, j = col; j < N && i >= 0; i--, j++) 
        if (board[i][j]) 
            return false; 
  
    return true; 
} 

// working our way down in rows instead of clumns
int solveIteratively(vector<vector<vector<int>>>& boards) {
	int num_solutions = 0;

	auto unfinished_boards = stack<vector<vector<int>>>();
	unfinished_boards.push(vector<vector<int>>()); // push empty vector = zero rows filled

	while(!unfinished_boards.empty()) {
		auto current = unfinished_boards.top();
		unfinished_boards.pop();
		
		if (current.size() == N) {
			num_solutions++;
			boards.push_back(current);
		} else {
			int row = current.size();
			current.push_back(vector<int>(N, 0));
			for (int potential_placement = 0; potential_placement < N; potential_placement++) {
				if (isPossible(current, row, potential_placement)) {
					auto new_board = current;
					new_board[new_board.size()-1][potential_placement] = 1;
					unfinished_boards.push(new_board);
				}
			}
		}
	}

	return num_solutions;
}

void testcase() {
	cin >> N;

	auto boards = vector<vector<vector<int>>>();

	cout << solveNQUtil(boards, vector<vector<int>>(N, vector<int>(N, 0)), 0) << endl << endl;
	//cout << solveIteratively(boards) << endl << endl;
	
	for (auto const& board : boards) {
		for (auto const& row : board) {
			cout << row << endl;
		}
		cout << endl;
	}
	
	return;
}


int main() 
{
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
		testcase();

    return 0;
} 