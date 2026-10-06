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
Reverse-then-ripple simulation with dynamic carry reset:
- Reverse the `digits` array so that the least significant digit (LSD) 
  is positioned at index 0.
- Add the initial +1 increment directly to `digits[0]`.
- Iterate through each index `i` from 0 to `digits.size() - 1`:
  - Add the carry `n` propagated from the previous digit: `digits[i] += n`.
  - Calculate the new carry: `n = digits[i] / 10`.
    (Note: If `digits[i] < 10`, `n` automatically resets to 0, preventing stale carries).
  - Update the current digit to its modulo-10 remainder: `digits[i] %= 10`.
- After processing all elements, if a final carry remains (`n > 0`), 
  append `n` to the end of the array (e.g., 999 -> 000 with carry 1 -> 0001).
- Reverse the array back to restore the original most-to-least significant order.
- Return the modified `digits`.

Time Complexity  : O(N) where N is digits.size()
Space Complexity : O(1) auxiliary space (modifying vector in-place)
============================================================
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = 0;
        reverse(digits.begin(), digits.end());
        
        digits[0] += 1;
        
        for(int i = 0; i < digits.size(); i++){
            digits[i] += n;
            n = digits[i] / 10; 
            digits[i] = digits[i] % 10;
        }
        
        if(n > 0) digits.push_back(n);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
