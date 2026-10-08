/*
============================================================
Problem Name : Longest Substring Without Repeating Characters
LeetCode ID  : 3
NeetCode ID  : longest-substring-without-repeating-characters
Difficulty   : Medium
Topic        : Two Pointers / Sliding Window
Date Solved  : 2026-10-08

Problem Statement:
Given a string s, find the length of the longest substring 
without duplicate characters.

Approach:
Sliding Window using Hash Set:
- Maintain an active window `[left, i]` representing the current valid 
  substring of unique characters.
- Use an `unordered_set<char> st` to track characters present in the window.
- Iterate the right boundary `i` across `s`:
  - If `s[i]` already exists in `st`, a duplicate is found:
    - Shrink the window from the left by erasing `s[left]` from `st` and 
      incrementing `left` until `s[i]` is no longer present.
  - Insert the incoming character `s[i]` into `st`.
  - Update `maxCount = max(st.size(), maxCount)`.
- Return `maxCount`.

Time Complexity  : O(N) where N is s.length() (each character visited at most twice)
Space Complexity : O(min(N, M)) auxiliary space, where M is the character set size
============================================================
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        size_t maxCount = 0;
        int left = 0;
        for(int i=0;i<s.length();i++){
            while(st.find(s[i])!=st.end()){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[i]);
            maxCount = max(st.size(),maxCount);
        }
        return maxCount;
    }
};