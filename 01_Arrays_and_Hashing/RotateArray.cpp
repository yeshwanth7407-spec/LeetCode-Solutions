/*
============================================================
Problem Name : Rotate Array
LeetCode ID  : 189
NeetCode ID  : rotate-array
Difficulty   : Medium
Topic        : Arrays & Hashing
Date Solved  : 2026-10-07

Problem Statement:
Given an integer array nums, rotate the array to the right by k steps, 
where k is non-negative. Modifying the array in-place with O(1) extra 
memory is required.

Approach:
Three-Step Reversal Algorithm (In-Place O(1) Auxiliary Space):
- Normalize `k` using modulo arithmetic: `k %= n`.
- If `k == 0`, no rotation is required; return immediately.
- Execute three successive range reversals:
  1. Reverse the entire array: `reverse(nums.begin(), nums.end())`.
     This brings the last `k` elements to the front, but in reversed order.
  2. Reverse the first `k` elements: `reverse(nums.begin(), nums.begin() + k)`.
     This restores the original relative order of the rotated elements.
  3. Reverse the remaining `n - k` elements: `reverse(nums.begin() + k, nums.end())`.
     This restores the original relative order of the unrotated elements.

Time Complexity  : O(N) where N is nums.size() (each element swapped at most twice)
Space Complexity : O(1) auxiliary space (operates strictly in-place)
============================================================
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int n = nums.size();
       k %= n;
       if(k==0) return;
       reverse(nums.begin(),nums.end());
       reverse(nums.begin(),nums.begin()+k);
       reverse(nums.begin()+k,nums.end());
    }

    vector<int> Sol(vector<int>& v,int k){
        rotate(v,k);
        return v;
    }
};