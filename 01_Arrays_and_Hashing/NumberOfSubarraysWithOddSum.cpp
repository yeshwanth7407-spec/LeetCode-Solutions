/*
============================================================
Problem Name : Number of Sub-arrays With Odd Sum
LeetCode ID  : 1524
NeetCode ID  : number-of-sub-arrays-with-odd-sum
Difficulty   : Medium
Topic        : Arrays & Hashing / Prefix Sums / Math
Date Solved  : 2026-11-15

Problem Statement:
Given an array of integers arr, return the number of subarrays with an odd sum.
Since the answer can be very large, return it modulo 10^9 + 7.

Approach:
Prefix Sum Parity Counting:
- The sum of subarray `arr[i..j]` is given by `prefix[j] - prefix[i - 1]`.
- For `prefix[j] - prefix[i - 1]` to be odd, the two prefix sums must have 
  opposite parities (one odd, one even).
- Maintain running counts of prefix sum parities seen so far:
  - `even_count = 1` (accounts for the empty prefix sum 0 before index 0).
  - `odd_count = 0`.
- Iterate through each element `num` in `arr`:
  - Accumulate `prefix_sum += num`.
  - If `prefix_sum` is odd (`prefix_sum % 2 != 0`):
    - Any prior even prefix sum forms an odd-sum subarray ending at the 
      current index -> add `even_count` to `ans` modulo `1e9 + 7`.
    - Increment `odd_count++`.
  - Else (`prefix_sum` is even):
    - Any prior odd prefix sum forms an odd-sum subarray ending at the 
      current index -> add `odd_count` to `ans` modulo `1e9 + 7`.
    - Increment `even_count++`.
- Return `ans`.

Time Complexity  : O(N) single-pass traversal of arr
Space Complexity : O(1) auxiliary space
============================================================
*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long prefix_sum = 0;
        int even_count = 1;
        int odd_count = 0;
        int ans = 0;

        for (int num : arr) {
            prefix_sum += num;
            if (prefix_sum % 2 != 0) {
                ans = (ans + even_count) % MOD;
                odd_count++;
            } else {
                ans = (ans + odd_count) % MOD;
                even_count++;
            }
        }
        return ans;
    }
};