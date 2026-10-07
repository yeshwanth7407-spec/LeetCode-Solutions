/*
============================================================
Problem Name : Valid Palindrome
LeetCode ID  : 125
NeetCode ID  : valid-palindrome
Difficulty   : Easy
Topic        : Two Pointers
Date Solved  : 2026-10-07

Problem Statement:
A phrase is a palindrome if, after converting all uppercase letters 
into lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward. Alphanumeric characters include 
letters and numbers. Given a string s, return true if it is a palindrome, 
or false otherwise.

Approach:
Two-pointer bidirectional scan with alphanumeric filtering:
- Initialize two pointers: `l = 0` (left) and `r = s.length() - 1` (right).
- Loop while `l < r`:
  - If `!isalnum(s[l])`: Advance the left pointer (`l++`) and continue to skip non-alphanumeric characters.
  - Else if `!isalnum(s[r])`: Decrement the right pointer (`r--`) and continue to skip non-alphanumeric characters.
  - When both pointers reference alphanumeric characters:
    - Compare their lowercase values via `tolower(s[l]) != tolower(s[r])`.
    - If they differ, set `valid = false` and terminate early.
    - If they match, advance both pointers inward (`l++`, `r--`).
- Return `valid`.

Time Complexity  : O(N) where N is s.length() (each character visited at most twice)
Space Complexity : O(1) auxiliary space (operates strictly in-place)
============================================================
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,r=s.length()-1;
        bool valid = true;
        while(l<r){
            if(!isalnum(s[l])){
                l++;
                continue;
            }else if (!isalnum(s[r])){
                r--;
                continue;
            }
            if(tolower(s[l])!=tolower(s[r])){
                valid = false;
                break;
            }
            l++; r--;
        }
        return valid;
    }
};