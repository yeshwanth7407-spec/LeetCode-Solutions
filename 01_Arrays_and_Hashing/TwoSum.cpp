/*
============================================================
Problem Name : Two Sum
LeetCode ID  : 1
NeetCode ID  : two-sum
Difficulty   : Easy
Topic        : Arrays & Hashing
Date Solved  : 2026-09-17

Problem Statement:
Given an array of integers nums and an integer target, return 
indices of the two numbers such that they add up to target.

Approach:
Use an unordered_map to store values and their indices.
For each element, check if (target - nums[i]) exists in the map.

Time Complexity  : O(N)
Space Complexity : O(N)
============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};