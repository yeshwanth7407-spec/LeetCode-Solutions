/*
============================================================
Problem Name : Longest Strictly Increasing or Strictly Decreasing Subarray
LeetCode ID  : 3105
NeetCode ID  : longest-strictly-increasing-or-strictly-decreasing-subarray
Difficulty   : Easy
Topic        : Arrays & Hashing
Date Solved  : 2026-11-12

Problem Statement:
You are given an array of integers nums. Return the length of the longest 
subarray of nums which is either strictly increasing or strictly decreasing.

Approach:
Single-Pass Dual Streak Tracking:
- Maintain three variables initialized to 1:
  - `inc`: Length of the current strictly increasing contiguous subarray.
  - `dec`: Length of the current strictly decreasing contiguous subarray.
  - `ans`: Global maximum length encountered across both directions.
- Traverse `nums` from index 1 to N - 1:
  - If `nums[i] > nums[i - 1]`:
    - The increasing streak continues (`inc++`), while any decreasing streak resets (`dec = 1`).
  - Else if `nums[i] < nums[i - 1]`:
    - The decreasing streak continues (`dec++`), while any increasing streak resets (`inc = 1`).
  - Else (`nums[i] == nums[i - 1]`):
    - Strict monotonicity breaks in both directions -> reset both `inc = 1` and `dec = 1`.
  - Update `ans = max({ans, inc, dec})`.
- Return `ans`.

Time Complexity  : O(N) single-pass traversal of nums
Space Complexity : O(1) auxiliary space
============================================================
*/

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dec = 1, ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                inc++;
                dec = 1;
            } else if (nums[i] < nums[i - 1]) {
                dec++;
                inc = 1;
            } else {
                inc = 1;
                dec = 1;
            }
            ans = max({ans, inc, dec});
        }
        return ans;
    }
};