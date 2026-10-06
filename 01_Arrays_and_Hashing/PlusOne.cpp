/*
============================================================
Problem Name : Plus One
LeetCode ID  : 66
NeetCode ID  : plus-one
Difficulty   : Easy
Topic        : Arrays & Hashing
Date Solved  : 2026-10-06

Problem Statement:
You are given a large integer represented as an integer array digits, 
where each digits[i] is the i-th digit of the integer. The digits 
are ordered from most significant to least significant in left-to-right 
order. The large integer does not contain any leading 0's. Increment 
the large integer by one and return the resulting array of digits.

Approach:
Array reversal with manual carry propagation:
- Reverse `digits` to align the least significant digit (LSD) at index 0.
- Add 1 to `digits[0]`.
- Iterate through the reversed vector:
  - If `digits[i] >= 10`, compute carry `n = digits[i] / 10` and set `digits[i] %= 10`.
  - Propagate carry forward to `digits[i + 1]` if within bounds.
- If carry `n > 0` remains after processing all elements (e.g., 99 -> 100), 
  append `n` to the end.
- Reverse `digits` back to restore most-to-least significant order.
- Return `digits`.

Time Complexity  : O(N) where N is digits.size()
Space Complexity : O(1) auxiliary space (modifying in-place)
============================================================
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=0;
        reverse(digits.begin(),digits.end());
        digits[0] += 1;
        for(int i=0;i<digits.size();i++){
            if(digits[i]>=10){
                n = digits[i]/10;
                digits[i] = digits[i]%10;
            }
            if(i+1 < digits.size()) digits[i+1] += n;
        }
        if(n>0) digits.push_back(n);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};