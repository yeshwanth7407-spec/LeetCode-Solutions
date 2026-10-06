/*
============================================================
Problem Name : Length of Last Word
LeetCode ID  : 58
NeetCode ID  : length-of-last-word
Difficulty   : Easy
Topic        : Arrays & Hashing
Date Solved  : 2026-10-06

Problem Statement:
Given a string s consisting of words and spaces, return the 
length of the last word in the string. A word is a maximal 
substring consisting of non-space characters only.

Approach:
String stream tokenization:
- Wrap string `s` in `std::stringstream ss(s)`.
- Use extraction operator `ss >> st` to parse whitespace-delimited tokens sequentially.
- On each valid token read into `st`, update length `c = st.length()`.
- Because extraction processes left-to-right, the final value retained 
  in `c` corresponds to the exact character count of the last word.
- Return `c`.

Time Complexity  : O(N) where N is s.length()
Space Complexity : O(N) auxiliary space used by stringstream buffer and token string
============================================================
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string st;
        int c = 0;
        while(ss>>st){
            c = st.length();
        }
        return c;
    }
};