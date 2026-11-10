/*
============================================================
Problem Name : Longest Common Prefix
LeetCode ID  : 14
NeetCode ID  : longest-common-prefix
Difficulty   : Easy
Topic        : Arrays & Hashing / Strings
Date Solved  : 2026-11-10

Problem Statement:
Write a function to find the longest common prefix string amongst an array 
of strings. If there is no common prefix, return an empty string "".

Approach:
Horizontal Scanning (Iterative Prefix Truncation):
- Assume the first string `strs[0]` is the candidate `prefix`.
- Iterate through each subsequent string `strs[i]` from index 1 to N - 1:
  - While `strs[i]` does not start with `prefix` (`strs[i].find(prefix) != 0`):
    - Truncate the candidate prefix by removing its last character:
      `prefix = prefix.substr(0, prefix.length() - 1)`.
    - If `prefix` becomes empty (`prefix.empty()`), no common prefix 
      exists among all strings -> return "" immediately.
- Once all strings match the running prefix, return `prefix`.

Time Complexity  : O(S) where S is the sum of all characters across all strings
Space Complexity : O(1) auxiliary space (modifying candidate string in-place)
============================================================
*/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string prefix = strs[0];

        for (size_t i = 1; i < strs.size(); ++i) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }
};