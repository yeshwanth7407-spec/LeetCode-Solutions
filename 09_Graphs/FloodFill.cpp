/*
============================================================
Problem Name : Flood Fill
LeetCode ID  : 733
NeetCode ID  : flood-fill
Difficulty   : Easy
Topic        : Graphs
Date Solved  : 2026-10-16

Problem Statement:
An image is represented by an m x n integer grid image where image[i][j] 
represents the pixel value of the image. You are also given three integers 
sr, sc, and color. You should perform a flood fill on the image starting 
from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels 
connected 4-directionally to the starting pixel of the same color as the 
starting pixel, plus any pixels connected 4-directionally to those pixels 
(also with the same color), and so on. Replace the color of all of the 
aforementioned pixels with color. Return the modified image after performing 
the flood fill.

Approach:
Depth-First Search (DFS) Grid Traversal:
- Base Condition:
  - If the starting pixel `image[sr][sc]` already equals the target `color`,
    the flood fill has nothing to change. Return `image` immediately to 
    prevent infinite recursive cycles without needing an explicit visited array.
- Recursive DFS Fill (`Helper`):
  - Overwrite the current cell `adj[sr][sc]` with `newer` (target color).
  - Use directional delta arrays `nr = {-1, 0, 1, 0}` and `nc = {0, -1, 0, 1}` 
    to explore 4-directional adjacent neighbors (up, left, down, right).
  - For each neighboring coordinate `(r, c)`:
    - Check boundaries: `0 <= r < rows` and `0 <= c < cols`.
    - If the neighbor matches `original` (the initial color before fill),
      recursively invoke `Helper` on `(r, c)`.
- Return the modified grid.

Time Complexity  : O(M * N) where M is rows and N is columns (each cell visited at most once)
Space Complexity : O(M * N) auxiliary stack space in the worst-case recursion tree
============================================================
*/

class Solution {
public:
    void Helper(vector<vector<int>>& adj, int sr, int sc, int original, int newer) {
        adj[sr][sc] = newer;
        vector<int> nr = {-1, 0, 1, 0};
        vector<int> nc = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++) {
            int r = sr + nr[i];
            int c = sc + nc[i];
            if (r >= 0 && c >= 0 && r < adj.size() && c < adj[0].size()) {
                if (adj[r][c] == original) {
                    Helper(adj, r, c, original, newer);
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        Helper(image, sr, sc, image[sr][sc], color);
        return image;
    }
};