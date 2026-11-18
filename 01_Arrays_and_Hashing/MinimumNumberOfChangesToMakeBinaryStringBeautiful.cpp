/*
============================================================
Problem Name : Minimum Number of Changes to Make Binary String Beautiful
LeetCode ID  : 2914
NeetCode ID  : minimum-number-of-changes-to-make-binary-string-beautiful
Difficulty   : Medium
Topic        : Strings / Greedy
Date Solved  : 2026-11-18

Problem Statement:
You are given a 0-indexed binary string s having an even length.
A string is beautiful if it is possible to partition it into one or more 
substrings such that:
- Each substring has an even length.
- Each substring contains only 1's or only 0's.
You can change any character in s to 0 or 1. Return the minimum number 
of changes required to make the string s beautiful.

Approach:
Greedy Adjacent Pairwise Decomposition:
- Any even-length uniform substring can be decomposed into contiguous 
  2-character blocks of identical characters (`"00"` or `"11"`).
- Conversely, if every disjoint adjacent pair `(s[0], s[1])`, `(s[2], s[3])`, ..., 
  `(s[n - 2], s[n - 1])` consists of two identical characters, the entire 
  string is guaranteed to be valid.
- Iterate through the string in steps of 2 (`i = 0, 2, 4, ...`):
  - If `s[i] != s[i + 1]`, one character in the pair must be flipped to match 
    the other -> increment `mini++`.
- Return `mini`.

Time Complexity  : O(N) single-pass traversal in steps of 2
Space Complexity : O(1) auxiliary space
============================================================
*/

class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int mini = 0;
        for (int i = 0; i < n - 1; i += 2) {
            if (s[i] != s[i + 1]) mini++;
        }
        return mini;
    }
};