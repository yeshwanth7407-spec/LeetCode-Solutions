/*
============================================================
Problem Name : Number of Senior Citizens
LeetCode ID  : 2678
NeetCode ID  : number-of-senior-citizens
Difficulty   : Easy
Topic        : Arrays & Hashing
Date Solved  : 2026-09-20

Problem Statement:
You are given a 0-indexed array of strings details. Each element 
of details provides information about a passenger compressed into 
a string of length 15:
- The first 10 characters consist of the phone number.
- The next character denotes the gender ('M', 'F', 'O').
- The next 2 characters denote the age ('0' to '99').
- The last 2 characters denote the seat allotted.
Return the number of passengers who are strictly more than 60 years old.

Approach:
String parsing with substring extraction:
- Initialize a counter `count = 0` to track qualifying seniors.
- Iterate through each passenger's record string `i` in `details`:
  - Extract the 2-character age substring starting at index 11: `i.substr(11, 2)`.
  - Convert the substring to an integer using `std::stoi`.
  - If the parsed age is strictly greater than 60, increment `count`.
- Return the final count.

Time Complexity  : O(N) where N is details.size() (each string is fixed length 15)
Space Complexity : O(1) auxiliary space
============================================================
*/

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(auto i : details){
            if(stoi(i.substr(11,2)) > 60) count++;
        }
        return count;
    }
};