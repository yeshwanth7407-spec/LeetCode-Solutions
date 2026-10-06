/*
============================================================
Problem Name : Minimum Add to Make Parentheses Valid
LeetCode ID  : 921
NeetCode ID  : minimum-add-to-make-parentheses-valid
Difficulty   : Medium
Topic        : Stack
Date Solved  : 2026-10-06

Problem Statement:
A parentheses string is valid if and only if:
1. It is the empty string,
2. It can be written as AB (A concatenated with B), where A and B are valid strings, or
3. It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis 
at any position of the string. Return the minimum number of moves required to make s valid.

Approach:
Stack-based tracking of unmatched brackets:
- Maintain an explicit LIFO `stack<char> st` to store unmatched opening parentheses.
- Maintain a counter `opening` (unmatched closing brackets) to track closing parentheses 
  encountered when no corresponding opening bracket exists in the stack.
- Traverse through string `s`:
  - If the character is an opening parenthesis `'('`, push it onto `st`.
  - If the character is a closing parenthesis `')'`:
    - If `st` is non-empty and the top matches, pop the opening bracket.
    - If `st` is empty, no opening bracket can match this closing parenthesis; 
      increment `opening`.
- The total additions required equal the unmatched closing brackets (`opening`) 
  plus the remaining unmatched opening brackets sitting in `st.size()`.
- Return `opening + st.size()`.

Time Complexity  : O(N) where N is s.length()
Space Complexity : O(N) auxiliary space for the stack
============================================================
*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int opening = 0;
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i] =='[' || s[i] == '{'){
                st.push(s[i]);
            }else if(s[i]==')' || s[i] ==']' || s[i] == '}'){
                if(!st.empty()){
                    if(s[i]==')' && st.top() == '('){
                    st.pop();
                    }else if(s[i]==']' && st.top() == '['){
                        st.pop();
                    }else if(s[i]=='}' && st.top() == '{'){
                        st.pop();
                    }
            }else{
                    opening++;
                }
            }
        }
        return (opening+st.size());
    }
};