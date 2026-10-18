/*
============================================================
Problem Name : Snakes and Ladders
LeetCode ID  : 909
NeetCode ID  : snakes-and-ladders
Difficulty   : Medium
Topic        : Graphs / Breadth-First Search
Date Solved  : 2026-10-18

Problem Statement:
You are given an n x n integer matrix board where the cells are 
labeled from 1 to n^2 in a Boustrophedon (alternating snake-like) 
direction starting from the bottom-left corner:
- Row n-1 from left to right,
- Row n-2 from right to left, and so on.
Starting at square 1, on each move you roll a 6-sided die to advance 
to square x + 1 through min(x + 6, n^2). If the square contains a snake 
or ladder (board[r][c] != -1), you must jump to its destination.
Return the minimum number of moves to reach square n^2, or -1 if unreachable.

Approach:
1D Flattening + Breadth-First Search (Shortest Path in Unweighted Graph):
- Board Linearization:
  - Flatten the 2D n x n Boustrophedon grid into a 1D array `v` of size n^2 + 1.
  - For each square label `i` from 1 to n^2:
    - Row index from the bottom: `r = n - 1 - (i - 1) / n`.
    - Column offset: `rem = (i - 1) % n`.
    - Check row direction parity from the bottom: `(n - 1 - r) % 2`.
      - If even (0, 2, ...): left-to-right -> `c = rem`.
      - If odd (1, 3, ...): right-to-left -> `c = n - 1 - rem`.
    - Set `v[i] = (board[r][c] == -1) ? i : board[r][c]`.
- Level-Order BFS:
  - Initialize `queue<int> q`, push `1`, and mark `visited[1] = 1`.
  - Track moves with `dieroll = 0`.
  - While `q` is non-empty, process all squares at the current move level:
    - If current square `t == n * n`, return `dieroll`.
    - For die values `j` from 1 to 6:
      - Compute next square `x = t + j`.
      - If `x <= n * n`, find its actual destination `dest = v[x]`.
      - If `visited[dest] == 0`:
        - Mark `visited[dest] = 1`.
        - Push `dest` into `q`.
    - Increment `dieroll++` after completing each level.
- If the queue exhausts without reaching `n^2`, return -1.

Time Complexity  : O(N^2) where N is the board dimension (at most N^2 vertices and 6*N^2 edges)
Space Complexity : O(N^2) auxiliary space for the flattened array, visited vector, and BFS queue
============================================================
*/

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> v(n * n + 1, 0);

        for (int i = 1; i <= n * n; i++) {
            int r = n - 1 - ((i - 1) / n);
            int rem = (i - 1) % n;
            int c = ((n - 1 - r) % 2 == 0) ? rem : (n - 1 - rem);
            v[i] = (board[r][c] == -1) ? i : board[r][c];
        }

        vector<int> visited(n * n + 1, 0);
        queue<int> q;
        int dieroll = 0;

        q.push(1);
        visited[1] = 1;

        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                int t = q.front();
                q.pop();

                if (t == n * n) return dieroll;

                for (int j = 1; j <= 6; j++) {
                    int x = t + j;
                    if (x <= n * n) {
                        int destination = v[x];
                        if (visited[destination] == 0) {
                            visited[destination] = 1;
                            q.push(destination);
                        }
                    }
                }
            }
            dieroll++;
        }

        return -1;
    }
};