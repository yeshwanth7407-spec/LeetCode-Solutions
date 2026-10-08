/*
============================================================
Problem Name : Climbing Stairs
LeetCode ID  : 70
NeetCode ID  : climbing-stairs
Difficulty   : Easy
Topic        : 1-D Dynamic Programming
Date Solved  : 2026-10-09

Problem Statement:
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct 
ways can you climb to the top?

Approach:
Iterative Dynamic Programming (Fibonacci Space Optimization):
- To reach step `i`, one must take a single step from `i - 1` 
  or a double step from `i - 2`.
- Recurrence relation: `dp[i] = dp[i - 1] + dp[i - 2]`.
- This is the standard Fibonacci sequence with base values:
  - Step 0: 1 way (empty path / ground)
  - Step 1: 1 way
- State reduction:
  - Maintain `f0` (representing ways to reach step `i - 2`) and 
    `f1` (representing ways to reach step `i - 1`).
  - For each step from `1` to `n`:
    - Cache `f1` in temporary variable `t`.
    - Advance `f1 = f1 + f0`.
    - Advance `f0 = t`.
- Return `f1`, which holds the total distinct combinations to reach step `n`.

Time Complexity  : O(N) where N is n
Space Complexity : O(1) auxiliary space
============================================================
*/

class Solution {
public:
    int climbStairs(int n) {
        int f0 = 0,f1 = 1;
        for(int i=1;i<=n;i++){
            int t = f1;
            f1 += f0;
            f0 = t;
        }
        return f1;
    }
};