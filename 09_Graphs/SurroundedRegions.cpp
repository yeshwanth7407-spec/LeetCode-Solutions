/*
============================================================
Problem Name : Surrounded Regions
LeetCode ID  : 130
NeetCode ID  : surrounded-regions
Difficulty   : Medium
Topic        : Graphs
Date Solved  : 2026-10-16

Problem Statement:
Given an m x n matrix board containing 'X' and 'O', capture all 
regions that are 4-directionally surrounded by 'X'. A region is 
captured by flipping all 'O's into 'X's in that surrounded region.
An 'O' cell is NOT captured if it is connected to the boundary.

Approach:
Boundary DFS Traversal with Sentinel In-Place Marking:
- Key Insight:
  - Any 'O' that is on the boundary, or connected directly/indirectly 
    to a boundary 'O', can NEVER be fully surrounded.
  - All other interior 'O's are completely trapped and must be flipped to 'X'.
- Phase 1 (Boundary Flood Fill):
  - Traverse all boundary cells (first/last rows: `i == 0 || i == s - 1`,
    first/last cols: `j == 0 || j == t - 1`).
  - For every boundary cell where `board[i][j] == 'O'`, launch DFS (`Helper`):
    - Temporarily mark reachable cells with a sentinel character `'v'`.
    - Explore 4-directional cardinal neighbors (`{-1, 0, 1, 0}` / `{0, -1, 0, 1}`).
    - Recursively protect any connected `'O'`.
- Phase 2 (Grid Resolution):
  - Traverse every cell in the matrix:
    - If `board[i][j] == 'v'`: It is connected to the boundary -> restore to `'O'`.
    - If `board[i][j] == 'O'`: It is an unreached, surrounded interior cell -> flip to `'X'`.
    - If `board[i][j] == 'X'`: Leave untouched.

Time Complexity  : O(M * N) where M is rows and N is columns (each cell visited at most a constant number of times)
Space Complexity : O(M * N) auxiliary stack space in the worst-case DFS recursion tree
============================================================
*/

class Solution {
public:
    void Helper(vector<vector<char>>& grid, int sr, int sc) {
        grid[sr][sc] = 'v';
        static const int nr[4] = {-1, 0, 1, 0};
        static const int nc[4] = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++) {
            int r = sr + nr[i];
            int c = sc + nc[i];
            if (r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size()) {
                if (grid[r][c] == 'O') {
                    Helper(grid, r, c);
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int s = board.size();
        int t = board[0].size();

        for (int i = 0; i < s; i++) {
            for (int j = 0; j < t; j++) {
                if (i == 0 || i == s - 1 || j == 0 || j == t - 1) {
                    if (board[i][j] == 'O') {
                        Helper(board, i, j);
                    }
                }
            }
        }

        for (int i = 0; i < s; i++) {
            for (int j = 0; j < t; j++) {
                if (board[i][j] == 'v') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};