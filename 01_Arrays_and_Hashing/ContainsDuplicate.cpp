/*
============================================================
Problem Name : Contains Duplicate
LeetCode ID  : 217
NeetCode ID  : contains-duplicate
Difficulty   : Easy
Topic        : Arrays & Hashing
Date Solved  : 2026-09-18

Problem Statement:
Given an integer array nums, return true if any value appears 
at least twice in the array, and return false if every element 
is distinct.

Approach:
Hash set lookup with early exit:
- Maintain an auxiliary `unordered_set<int> m` to store seen numbers.
- Iterate through each element `i` in `nums`:
  - Check if `i` already exists in `m` via `m.count(i)`.
  - If found, a duplicate exists; immediately return true.
  - Otherwise, insert `i` into `m`.
- If the loop finishes without returning, all elements are unique; return false.

Time Complexity  : O(N) average time
Space Complexity : O(N) auxiliary space for the hash set
============================================================
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
         unordered_set<int> m;
        for(int i : nums){
            if(m.count(i)){
                return true;
            }
            m.insert(i);
        }
        return false;
    }
};