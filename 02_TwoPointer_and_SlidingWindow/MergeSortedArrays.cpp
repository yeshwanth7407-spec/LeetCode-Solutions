/*
============================================================
Problem Name : Merge Sorted Array
LeetCode ID  : 88
NeetCode ID  : merge-sorted-array
Difficulty   : Easy
Topic        : Arrays & Hashing / Two Pointers
Date Solved  : 2026-10-07

Problem Statement:
You are given two integer arrays nums1 and nums2, sorted in non-decreasing 
order, and two integers m and n, representing the number of elements in nums1 
and nums2 respectively. Merge nums1 and nums2 into a single array sorted 
in non-decreasing order. The final sorted array should not be returned by 
the function, but instead be stored inside the array nums1. To accommodate 
this, nums1 has a length of m + n, where the first m elements denote the 
elements that should be merged, and the last n elements are set to 0 and 
should be ignored. nums2 has a length of n.

Approach:
Two-pointer swap with repeated inner sorting:
- Traverse nums1 from index `i = 0` to `m - 1` comparing against nums2[j] (where j = 0):
  - If `nums1[i] <= nums2[j]`, nums1[i] is already in its valid relative position; increment `i`.
  - Else, swap `nums1[i]` with `nums2[j]`, then sort `nums2` to restore its non-decreasing order.
- After comparing the first `m` positions, copy the remaining elements of `nums2` 
  into the reserved trailing space of `nums1` (`nums1[m + j] = nums2[j]`).
- Return `nums1` (Note: LeetCode requires modifying `nums1` in-place with `void` return type).

Time Complexity  : O(m * n log n) due to repeated sorting of nums2 on swaps 
Space Complexity : O(1) auxiliary space
============================================================
*/

class Solution {
public:
    vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums1.empty() || nums2.empty()){
            return (nums1.empty())?nums2:nums1;
        }
        int i = 0,j=0;
        while(i<m){
            if(nums1[i]<=nums2[j]){
                i++;
            }else{
                swap(nums1[i],nums2[j]);
                sort(nums2.begin(),nums2.end());
                i++;
            }
        }

        while(j<n){
            nums1[m+j] = nums2[j];
            j++;
        }
        return nums1;
    }
};