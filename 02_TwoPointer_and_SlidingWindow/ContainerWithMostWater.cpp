/*
============================================================
Problem Name : Container With Most Water
LeetCode ID  : 11
NeetCode ID  : container-with-most-water
Difficulty   : Medium
Topic        : Two Pointers
Date Solved  : 2026-11-10

Problem Statement:
You are given an integer array height of length n. There are n vertical 
lines drawn such that the two endpoints of the i-th line are (i, 0) and 
(i, height[i]). Find two lines that together with the x-axis form a container, 
such that the container contains the most water. Return the maximum amount 
of water a container can store. Notice that you may not slant the container.

Approach:
Two-Pointer Greedy Inward Convergence:
- The area between two boundaries at indices `l` and `h` is governed by:
  `area = min(height[l], height[h]) * (h - l)`.
- Start with the widest possible base by placing two pointers at the extremes:
  `l = 0` and `h = height.size() - 1`.
- While `l < h`:
  - Calculate the current area and update the running maximum (`area`).
  - To maximize potential area as the width `(h - l)` shrinks, greedily advance 
    the pointer pointing to the shorter vertical line:
    - If `height[l] < height[h]`: Moving `h` inward cannot possibly produce a 
      larger area (the height is limited by `height[l]`, and width decreases). 
      Hence, advance `l++`.
    - Otherwise: Decrement `h--`.
- Return `area`.

Time Complexity  : O(N) single-pass traversal of the height array
Space Complexity : O(1) auxiliary space
============================================================
*/

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, h = height.size() - 1;
        int area = 0;

        while (l < h) {
            int x = min(height[l], height[h]);
            int d = h - l;
            area = max(area, x * d);

            if (height[l] < height[h]) {
                l++;
            } else {
                h--;
            }
        }

        return area;
    }
};