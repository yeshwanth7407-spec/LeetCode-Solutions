/*
============================================================
Problem Name : Power of Two
LeetCode ID  : 231
NeetCode ID  : power-of-two
Difficulty   : Easy
Topic        : Bit Manipulation
Date Solved  : 2026-10-06

Problem Statement:
Given an integer n, return true if it is a power of two. 
Otherwise, return false. An integer n is a power of two if 
there exists an integer x such that n == 2^x.

Approach:
Bitwise Clearing of the Lowest Set Bit (Brian Kernighan's Property):
- A positive number is a power of two if and only if it has exactly one 
  set bit in its binary representation (e.g., 1 -> 0001, 2 -> 0010, 4 -> 0100).
- The operation `n & (n - 1)` clears the lowest set bit of `n`:
  - If `n` is a power of two, removing its only set bit reduces it to 0.
- Base Cases & Bounds:
  - If `n <= 0`, it cannot be a power of two; return false immediately.
  - Compute `x = n & (n - 1)`.
  - Return `true` if `x == 0`, else `false`.

Time Complexity  : O(1)
Space Complexity : O(1) auxiliary space
============================================================
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        int x = n&(n-1);
        return (x==0)?true:false;
    }
};