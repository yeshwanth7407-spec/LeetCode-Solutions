/*
============================================================
Problem Name : Replace Elements with Greatest Element on Right Side
LeetCode ID  : 1299
NeetCode ID  : replace-elements-with-greatest-element-on-right-side
Difficulty   : Easy
Topic        : Arrays & Hashing
Date Solved  : 2026-09-20

Problem Statement:
Given an array arr, replace every element in that array with the 
greatest element among the elements to its right, and replace the 
last element with -1. After doing so, return the array.

Approach:
Brute-force forward iteration with linear rightward search:
- Iterate through each index `i` from 0 to `arr.size() - 1`:
  - If `i` is the last index (`arr.size() - 1`), set `arr[i] = -1`.
  - Otherwise, call a helper function `findMax(arr, i)` that performs 
    a linear scan from index `i + 1` to the end of the array to find 
    the maximum element strictly to the right.
  - Overwrite `arr[i]` with the returned maximum value.
- Return the modified array `arr`.

Time Complexity  : O(N^2) where N is arr.size()
Space Complexity : O(1) auxiliary space (modifying in-place)
============================================================
*/

class Solution {
public:
     int findMax(vector<int>& v,int i){
        int x = v[i+1];
        for(int j=i+2;j<v.size();j++){
            if(v[j] > x) x = v[j];
        }
        return x;
    }
    vector<int> replaceElements(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            if(i==arr.size()-1){
                arr[i] = -1;
            }else{
                arr[i] = findMax(arr,i);
            }
        }
        return arr;
    }
};