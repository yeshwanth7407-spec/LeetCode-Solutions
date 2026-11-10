/*
============================================================
Problem Name : Search a 2D Matrix
LeetCode ID  : 74
NeetCode ID  : search-a-2d-matrix
Difficulty   : Medium
Topic        : Binary Search
Date Solved  : 2026-11-10

Problem Statement:
You are given an m x n integer matrix matrix with the following two properties:
- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity.

Approach:
Two-Level Binary Search (Row Selection + Column Search):
- The matrix is sorted continuously across rows from top-left to bottom-right.
- Step 1: Binary search across rows (`binary_index`):
  - Find the single row where `target` could potentially reside.
  - Check the midpoint row `mid`:
    - If `target >= v[mid][0] && target <= v[mid].back()`, target lies within 
      row `mid`'s boundaries -> return `mid`.
    - Else if `target >= v[low][0] && target <= v[mid][0]`, search the upper half (`high = mid - 1`).
    - Otherwise, search the lower half (`low = mid + 1`).
  - If no row contains target in its range, return -1.
- Step 2: Standard binary search within the candidate row (`binary_search`):
  - If a valid row index `i` is found, search within row `matrix[i]` using standard 
    1D binary search.
  - If `matrix[i][mid] == target`, return true.
  - Adjust `low` and `high` pointers accordingly until found or search space exhausts.

Time Complexity  : O(log M + log N) = O(log(M * N)), where M is rows and N is columns
Space Complexity : O(1) auxiliary space
============================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    int binary_index(vector<vector<int>>& v, int target) {
        int n = v.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (target >= v[mid][0] && target <= v[mid].back()) return mid;
            else if (target >= v[low][0] && target <= v[mid][0]) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }

    bool binary_search(vector<int>& v, int target) {
        int n = v.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (v[mid] == target) return true;
            else if (v[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = binary_index(matrix, target);
        if (i == -1) return false;
        return binary_search(matrix[i], target);
    }
};