/*
============================================================
Problem Name : Power of Four
LeetCode ID  : 342
NeetCode ID  : power-of-four
Difficulty   : Easy
Topic        : Bit Manipulation
Date Solved  : 2026-10-06

Problem Statement:
Given an integer n, return true if it is a power of four. Otherwise, 
return false. An integer n is a power of four if there exists an 
integer x such that n == 4^x.

Approach:
Bit Manipulation and Modulo-3 Property (O(1)):
- Condition 1 (`n > 0`): Powers of four are strictly positive integers.
- Condition 2 (`(n & (n - 1)) == 0`): Ensures `n` is a power of two 
  (meaning exactly one bit is set in its binary representation).
- Condition 3 (`n % 3 == 1`):
  - Notice the mathematical identity: 4^x = (3 + 1)^x ≡ 1^x ≡ 1 (mod 3).
  - Every power of four leaves a remainder of 1 when divided by 3.
  - Powers of two that are NOT powers of four (e.g., 2, 8, 32, 128) leave 
    a remainder of 2 when divided by 3 (since 2^(2k+1) = 2 * 4^k ≡ 2 * 1 ≡ 2 mod 3).
- Conjunction of all three conditions uniquely identifies powers of four.

Time Complexity  : O(1)
Space Complexity : O(1) auxiliary space
============================================================
*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 && (n&(n-1))==0 && n%3==1;
    }
};