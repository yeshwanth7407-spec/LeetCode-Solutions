/*
============================================================
Problem Name : Concatenation of Array
LeetCode ID  : 1929
NeetCode ID  : concatenation-of-array
Difficulty   : Easy
Topic        : Arrays & Hashing
Date Solved  : 2026-09-18

Problem Statement:
Given an integer array nums of length n, you want to create an array ans 
of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).
Specifically, ans is the concatenation of two nums arrays. Return the array ans.

Approach:
Single-pass dual-assignment using pre-allocated vector:
- Determine the original array size `s = nums.size()`.
- Allocate a new result vector `v` of fixed size `2 * s` upfront.
- Iterate from `i = 0` to `s - 1`:
  - Assign `nums[i]` simultaneously to index `i` (first half) and 
    index `i + s` (second half) via chained assignment: `v[i] = v[i + s] = nums[i]`.
- Return the concatenated array `v`.

Time Complexity  : O(N) where N is nums.size()
Space Complexity : O(1) auxiliary space (O(2N) for the output array)
============================================================
*/

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int s = nums.size();
        vector<int> v(s*2);
        for(int i=0;i<s;i++){
            v[i] = v[i+s] = nums[i];
            
        }
        return v;
    }
};