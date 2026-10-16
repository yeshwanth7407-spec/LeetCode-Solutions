/*
============================================================
Problem Name : Rotting Oranges
LeetCode ID  : 994
NeetCode ID  : rotting-oranges
Difficulty   : Medium
Topic        : Graphs
Date Solved  : 2026-10-17

Problem Statement:
You are given an m x n grid where each cell has one of three values:
- 0 representing an empty cell,
- 1 representing a fresh orange, or
- 2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a 
rotten orange becomes rotten. Return the minimum number of minutes that 
must elapse until no cell has a fresh orange. If this is impossible, return -1.

Approach:
Multi-Source Breadth-First Search (Level-Order BFS):
- Scan the grid to count all initial fresh oranges (`fresh`) and enqueue 
  all initial rotten orange coordinates `(i, j)` into a BFS queue.
- If `fresh == 0`, no oranges need rotting; return 0 immediately.
- Run level-order BFS traversal:
  - Process all nodes at the current level using `qsize = q.size()`.
  - Track if any fresh orange was contaminated during the current minute (`to`).
  - For each cell, check 4-directional cardinal neighbors (`{-1, 0, 1, 0}` / `{0, -1, 0, 1}`).
  - If an adjacent cell is fresh (`grid[r][c] == 1`):
    - Infect it (`grid[r][c] = 2`).
    - Decrement `fresh--`, increment `to++`, and push its coordinates into the queue.
  - If at least one orange was infected during this level (`to >= 1`), increment `time++`.
- After BFS finishes:
  - If `fresh == 0`, return `time`.
  - If `fresh > 0` (unreachable fresh oranges remain), return -1.

Time Complexity  : O(M * N) where M is rows and N is columns (each cell is processed at most once)
Space Complexity : O(M * N) auxiliary queue space in the worst case
============================================================
*/

#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    void BFS(vector<vector<int>>& grid, int& time, int& fresh, queue<pair<int, int>>& q) {
        int s = grid.size();
        int t = grid[0].size();
        static const int nr[4] = {-1, 0, 1, 0};
        static const int nc[4] = {0, -1, 0, 1};

        while (!q.empty()) {
            int qsize = q.size();
            int to = 0;
            for (int k = 0; k < qsize; k++) {
                pair<int, int> temp = q.front();
                q.pop();
                int sr = temp.first;
                int sc = temp.second;

                for (int l = 0; l < 4; l++) {
                    int r = sr + nr[l];
                    int c = sc + nc[l];
                    if (r >= 0 && c >= 0 && r < s && c < t) {
                        if (grid[r][c] == 1) {
                            grid[r][c] = 2;
                            fresh--;
                            to++;
                            q.push({r, c});
                        }
                    }
                }
            }
            if (to >= 1) time++;
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0, time = 0;
        int s = grid.size();
        int t = grid[0].size();

        for (int i = 0; i < s; i++) {
            for (int j = 0; j < t; j++) {
                if (grid[i][j] == 1) fresh++;
            }
        }

        if (fresh == 0) return 0;

        queue<pair<int, int>> q;
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < t; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        BFS(grid, time, fresh, q);
        return (fresh == 0) ? time : -1;
    }
};