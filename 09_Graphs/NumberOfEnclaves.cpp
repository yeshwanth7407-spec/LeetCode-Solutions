/*
============================================================
Problem Name : Number of Enclaves
LeetCode ID  : 1020
NeetCode ID  : number-of-enclaves
Difficulty   : Medium
Topic        : Graphs
Date Solved  : 2026-10-16

Problem Statement:
You are given an m x n binary matrix grid, where 0 represents a sea 
cell and 1 represents a land cell. A move consists of walking from one 
land cell to another adjacent (4-directionally) land cell or walking off 
the boundary of the grid. Return the number of land cells in grid for 
which we cannot walk off the boundary of the grid in any number of moves.

Approach:
Boundary DFS Flooding / Sinking Traversal:
- Key Insight:
  - Any land cell (`1`) positioned along the outer perimeter (boundary rows/columns) 
    or connected directly/indirectly to a boundary cell can walk off the grid.
  - All remaining interior land cells that cannot reach any boundary are true enclaves.
- Phase 1 (Sinking Boundary-Connected Land):
  - Traverse all perimeter cells:
    - Boundary rows: `i == 0` and `i == s - 1` across all columns `j`.
    - Boundary columns: `j == 0` and `j == t - 1` across all rows `i`.
  - Whenever an edge cell contains land (`grid[i][j] == 1`), trigger DFS (`Helper`):
    - Sink the current land cell by turning it into water: `grid[sr][sc] = 0`.
    - Explore 4-directional cardinal neighbors (`{-1, 0, 1, 0}` / `{0, -1, 0, 1}`).
    - Recursively sink any adjacent land cell (`grid[r][c] == 1`).
- Phase 2 (Counting Enclaves):
  - Scan the remaining grid. Any cell that is still `1` was completely isolated 
    from the boundaries.
  - Count and return the total number of remaining `1`s.

Time Complexity  : O(M * N) where M is rows and N is columns (each cell visited at most a constant number of times)
Space Complexity : O(M * N) auxiliary recursion stack space in the worst case
============================================================
*/

class Solution {
public:
    void Helper(vector<vector<int>>& grid, int sr, int sc) {
        grid[sr][sc] = 0;
        static const int nr[4] = {-1, 0, 1, 0};
        static const int nc[4] = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++) {
            int r = sr + nr[i];
            int c = sc + nc[i];
            if (r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size()) {
                if (grid[r][c] == 1) {
                    Helper(grid, r, c);
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int s = grid.size();
        int t = grid[0].size();

        for (int i = 0; i < s; i++) {
            for (int j = 0; j < t; j++) {
                if (i == 0 || j == 0 || i == s - 1 || j == t - 1) {
                    if (grid[i][j] == 1) {
                        Helper(grid, i, j);
                    }
                }
            }
        }

        int count = 0;
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < t; j++) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};