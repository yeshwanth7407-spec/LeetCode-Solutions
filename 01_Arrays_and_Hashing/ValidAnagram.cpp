/*
============================================================
Problem Name : Valid Anagram
LeetCode ID  : 242
NeetCode ID  : valid-anagram
Difficulty   : Easy
Topic        : Arrays & Hashing
Date Solved  : 2026-09-18

Problem Statement:
Given two strings s and t, return true if t is an anagram of s, 
and false otherwise.

Approach:
Frequency counter using a fixed-size direct-address array:
- First check lengths: If `s.length() != t.length()`, return false immediately.
- Allocate a frequency vector `v` of size 256 initialized to 0 to cover all ASCII characters.
- In a single loop over string length:
  - Increment the frequency corresponding to character `s[i]`.
  - Decrement the frequency corresponding to character `t[i]`.
- Iterate through the frequency vector:
  - If any count `x != 0`, character distributions do not match; return false.
- If all counts remain 0, strings are valid anagrams; return true.

Time Complexity  : O(N) where N is the length of strings s and t
Space Complexity : O(1) auxiliary space (fixed alphabet array size 256)
============================================================
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> v(256,0);
        for(int i=0;i<s.length();i++){
            v[s[i]]++;
            v[t[i]]--;
        }

        for(auto x : v){
            if(x != 0) return false;
        }
        return true;
    }
};
