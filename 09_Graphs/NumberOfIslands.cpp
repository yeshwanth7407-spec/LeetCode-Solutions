/*
============================================================
Problem Name : Number of Islands
LeetCode ID  : 200
NeetCode ID  : number-of-islands
Difficulty   : Medium
Topic        : Graphs
Date Solved  : 2026-10-16

Problem Statement:
Given an m x n 2D binary grid grid which represents a map of '1's (land) 
and '0's (water), return the number of islands. An island is surrounded 
by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Approach:
Depth-First Search (DFS) Island Sinking:
- Iterate through each cell `(i, j)` in the `m x n` grid:
  - If a cell contains unvisited land (`grid[i][j] == '1'`):
    - Increment the island counter `count++`.
    - Launch DFS (`Helper`) to traverse and sink the entire connected component.
- In `Helper(grid, sr, sc)`:
  - Mark the current land cell as visited by overwriting it (`grid[sr][sc] = '2'`).
  - Explore 4-directional cardinal neighbors using delta vectors:
    `nr = {-1, 0, 1, 0}` and `nc = {0, -1, 0, 1}`.
  - For each neighboring cell `(r, c)`:
    - Ensure boundaries satisfy `0 <= r < rows` and `0 <= c < cols`.
    - If `grid[r][c] == '1'`, recursively sink it via `Helper(grid, r, c)`.
- Return the final `count`.

Time Complexity  : O(M * N) where M is rows and N is columns (every cell is visited at most a constant number of times)
Space Complexity : O(M * N) auxiliary call stack space in the worst case (e.g., grid filled entirely with land)
============================================================
*/

class Solution {
public:
    void Helper(vector<vector<char>>& grid, int sr, int sc) {
        grid[sr][sc] = '2';
        vector<int> nr = {-1, 0, 1, 0};
        vector<int> nc = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++) {
            int r = sr + nr[i];
            int c = sc + nc[i];
            if (r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size()) {
                if (grid[r][c] == '1') {
                    Helper(grid, r, c);
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    Helper(grid, i, j);
                }
            }
        } 
        return count;
    }
};