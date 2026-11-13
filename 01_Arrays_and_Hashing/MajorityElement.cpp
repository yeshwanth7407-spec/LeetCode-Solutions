/*
============================================================
Problem Name : Majority Element
LeetCode ID  : 169
NeetCode ID  : majority-element
Difficulty   : Easy
Topic        : Arrays & Hashing
Date Solved  : 2026-11-13

Problem Statement:
Given an array nums of size n, return the majority element. 
The majority element is the element that appears more than floor(n / 2) times. 
You may assume that the majority element always exists in the array.

Approach:
Frequency Hash Map Counting:
- Build an `unordered_map<int, int>` to count the occurrences of every integer in `nums`.
- Initialize `maxi` and `val` with the key and count of the first entry in the map (`m.begin()`).
- Iterate through all key-value pairs in the map:
  - Whenever an element's frequency (`x.second`) exceeds `val`, update `val` and `maxi`.
- Return `maxi` as the element with the highest frequency.

Time Complexity  : O(N) average time to populate and scan the frequency map
Space Complexity : O(N) auxiliary space for storing up to N/2 + 1 distinct keys
============================================================
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int x : nums) {
            m[x]++;
        }
        int maxi = m.begin()->first;
        int val = m.begin()->second;
        for (auto x : m) {
            if (x.second > val) {
                val = x.second;
                maxi = x.first;
            }
        }
        return maxi;
    }
};