/*
============================================================
Problem Name : Counting Bits
LeetCode ID  : 338
NeetCode ID  : counting-bits
Difficulty   : Easy
Topic        : Bit Manipulation
Date Solved  : 2026-10-06

Problem Statement:
Given an integer n, return an array ans of length n + 1 such that 
for each i (0 <= i <= n), ans[i] is the number of 1's in the 
binary representation of i.

Approach:
Brian Kernighan's Algorithm per Number (O(N log N)):
- Helper function `setBits(n)`:
  - Continuously clears the lowest set bit using `n &= (n - 1)` until `n` becomes 0.
  - Increments a counter `c` on each iteration, counting set bits in O(number of set bits).
- In `countBits(n)`:
  - Iterate `i` from 0 up to `n`.
  - Compute `setBits(i)` for each integer and push the result into vector `v`.
- Return `v`.

Time Complexity  : O(N log N) where N is n (worst-case ~32 operations per number)
Space Complexity : O(1) auxiliary space (excluding the returned vector)
============================================================
*/

class Solution {
public:

    int setBits(int n){
        int c = 0;
        while(n!=0){
            n &= (n-1);
            c++;
        }
        return c;
    }
    vector<int> countBits(int n) {
        vector<int> v;
        for(int i=0;i<=n;i++){
            v.push_back(setBits(i));
        }
        return v;
    }
};