============================================================
Problem Name : Remove Element
LeetCode ID  : 27
NeetCode ID  : remove-element
Difficulty   : Easy
Topic        : Arrays & Hashing
Date Solved  : 2026-09-17

Problem Statement:
Given an integer array nums and an integer val, remove all occurrences 
of val in nums in-place. The order of the elements may be changed. 
Then return the number of elements in nums which are not equal to val.

Approach:
Two-pointer swap with the end (Optimized for minimal writes):
- Maintain an active array boundary `n` (initialized to nums.size()) 
  and a current index pointer `i = 0`.
- While `i < n`:
  - If `nums[i] == val`:
    - Overwrite `nums[i]` with the element at the current end `nums[n - 1]`.
    - Decrement `n` to discard the last element.
    - Do not increment `i`, because the element swapped from the end 
      must also be inspected in the next step.
  - If `nums[i] != val`:
    - Safely advance `i++`.
- When `i == n`, the first `n` elements contain all numbers != val. 
  Return `n` as the resulting length.

Time Complexity  : O(N) where the loop runs at most N total steps
Space Complexity : O(1) auxiliary space
============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                n--;                   
            } else {
                i++;                   
            }
        }
        return n;
    }
};