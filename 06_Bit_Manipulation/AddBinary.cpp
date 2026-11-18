/*
============================================================
Problem Name : Add Binary
LeetCode ID  : 67
NeetCode ID  : add-binary
Difficulty   : Easy
Topic        : Bit Manipulation / Strings / Math
Date Solved  : 2026-11-18

Problem Statement:
Given two binary strings a and b, return their sum as a binary string.

Approach:
Right-to-Left Digit-by-Digit Addition with Carry:
- Initialize pointers `as = a.length() - 1` and `bs = b.length() - 1` at the 
  least significant bits of strings `a` and `b`, along with `carry = '0'`.
- Process digits from right to left while indices remain above 0 (`as > 0 || bs > 0`):
  - Extract current bits `ac` and `bc` (defaulting to `'0'` if one string is exhausted).
  - Evaluate all bit + carry combinations:
    - Different bits (`'0'` and `'1'`): appends `'0'` if `carry == '1'` (carry stays `'1'`), 
      else appends `'1'`.
    - Both `'0'`: appends `carry` and resets `carry = '0'`.
    - Both `'1'`: appends `carry` and sets `carry = '1'`.
  - Decrement `as--` and `bs--`.
- Handle the most significant index (`0`) of the longer string along with any 
  remaining carry overflow.
- Reverse `ans` (`reverse(ans.begin(), ans.end())`) to restore MSB-to-LSB order 
  and return `ans`.

Time Complexity  : O(max(N, M)) where N and M are the lengths of strings a and b
Space Complexity : O(max(N, M)) auxiliary space for the output string
============================================================
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int as = a.length() - 1;
        int bs = b.length() - 1;
        string ans = "";
        char carry = '0';

        while (as > 0 || bs > 0) {
            char ac = (as >= 0) ? a[as] : '0';
            char bc = (bs >= 0) ? b[bs] : '0';
            if ((ac == '0' && bc == '1') || (ac == '1' && bc == '0')) {
                ans += (carry == '1') ? '0' : '1';
            } else if (ac == '0' && bc == '0') {
                ans += (carry == '1') ? '1' : '0';
                carry = '0';
            } else if (ac == '1' && bc == '1') {
                if (carry == '1') {
                    ans += '1';
                } else {
                    ans += '0';
                    carry = '1';
                }
            }
            as--;
            bs--;
        }

        char ac = (a.length() < b.length()) ? '0' : a[0];
        char bc = (b.length() < a.length()) ? '0' : b[0];
        if ((ac == '0' && bc == '1') || (ac == '1' && bc == '0')) {
            if (carry == '1') {
                ans += '0';
                ans += '1';
            } else {
                ans += '1';
            }
        } else if (ac == '0' && bc == '0') {
            ans += (carry == '1') ? '1' : '0';
        } else {
            if (carry == '1') {
                ans += '1';
                ans += '1';
            } else {
                ans += '0';
                ans += '1';
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};