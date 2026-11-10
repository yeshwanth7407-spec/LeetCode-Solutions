/*
============================================================
Problem Name : Climbing Stairs II
LeetCode ID  : -
NeetCode ID  : climbing-stairs-ii
Difficulty   : Medium
Topic        : 1D Dynamic Programming
Date Solved  : 2026-11-10

Problem Statement:
You want to reach the n-th step of a staircase starting from step 0. 
From any step i, you can jump 1, 2, or 3 steps forward (i + j where 1 <= j <= 3). 
Jumping j steps incurs a movement cost of (j * j) plus the step penalty costs[i + j - 1].
Find the minimum cost required to reach step n starting from step 0 with an initial cost of 0.

Approach:
1D Forward Push Dynamic Programming (Tabulation):
- Define `mins[i]` as the minimum total cost accumulated to reach step `i`.
- Initialize a DP table `mins` of size `n + 1` filled with infinity (`1e9`), setting `mins[0] = 0`.
- Iterate through each step `i` from `0` to `n - 1`:
  - If step `i` is unreachable (`mins[i] == 1e9`), continue.
  - Explore all possible jumps `j` from 1 to 3:
    - If `i + j <= n`:
      - Jump transition cost is `c = costs[i + j - 1] + (j * j)`.
      - Relax the target state: `mins[i + j] = min(mins[i + j], mins[i] + c)`.
- The answer is stored in `mins[n]`.

Time Complexity  : O(N) since each step checks at most 3 fixed forward transitions
Space Complexity : O(N) auxiliary space for the DP cost array
============================================================
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> mins(n + 1, 1e9);
        mins[0] = 0;

        for (int i = 0; i < n; i++) {
            if (mins[i] == 1e9) continue;
            for (int j = 1; j <= 3; j++) {
                if (i + j <= n) {
                    int c = costs[i + j - 1] + (j * j);
                    mins[i + j] = min(mins[i + j], mins[i] + c);
                }
            }
        }

        return mins[n];
    }
};