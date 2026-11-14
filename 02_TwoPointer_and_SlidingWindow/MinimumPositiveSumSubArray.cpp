/*
============================================================
Problem Name : Minimum Positive Sum Subarray
LeetCode ID  : 3364
NeetCode ID  : minimum-positive-sum-subarray
Difficulty   : Easy
Topic        : Arrays & Hashing / Sliding Window
Date Solved  : 2026-11-14

Problem Statement:
You are given an integer array nums and two integers l and r. 
Your task is to find the minimum sum of a subarray whose size is 
between l and r (inclusive) and whose sum is greater than 0.
Return the minimum sum of such a subarray. If no such subarray 
exists, return -1.

Approach:
Brute Force Subarray Enumeration:
- Initialize `mini = INT_MAX` to track the smallest positive subarray sum found.
- Enumerate all possible contiguous subarrays using two nested loops for 
  start index `i` (0 to n - 1) and end index `j` (i to n - 1):
  - Compute the subarray sum across indices `k` from `i` to `j`.
  - Check if the subarray length `j - i + 1` falls within `[l, r]`.
  - If `sum > 0`, update `mini = min(mini, sum)`.
- After evaluating all subarrays, return `-1` if `mini == INT_MAX` (meaning 
  no positive-sum subarray of valid length exists); otherwise return `mini`.

Time Complexity  : O(N^3) due to three nested loops enumerating and summing subarrays
Space Complexity : O(1) auxiliary space
============================================================
*/

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int mini = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += nums[k];
                }
                if ((j - i + 1) >= l && (j - i + 1) <= r) {
                    mini = (sum > 0) ? min(mini, sum) : mini;
                }
            }
        }
        return (mini == INT_MAX) ? -1 : mini;
    }
};