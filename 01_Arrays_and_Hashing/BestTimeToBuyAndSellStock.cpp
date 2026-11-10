/*
============================================================
Problem Name : Best Time to Buy and Sell Stock
LeetCode ID  : 121
NeetCode ID  : buy-and-sell-crypto
Difficulty   : Easy
Topic        : Arrays & Hashing / Sliding Window
Date Solved  : 2026-11-10

Problem Statement:
You are given an array prices where prices[i] is the price of a given 
stock on the i-th day. You want to maximize your profit by choosing a 
single day to buy one stock and choosing a different day in the future 
to sell that stock. Return the maximum profit you can achieve from this 
transaction. If you cannot achieve any profit, return 0.

Approach:
Single-Pass Greedy Running Minimum Tracking:
- Maintain two scalar variables:
  - `q`: Tracks the lowest buy price encountered so far (initialized to `prices[0]`).
  - `p`: Tracks the maximum profit found so far (initialized to `0`).
- Traverse through the price array:
  - For each day's price `prices[i]`:
    - Update `q = min(q, prices[i])` to capture any lower purchase opportunity.
    - Calculate potential profit if sold today (`prices[i] - q`) and update `p = max(p, prices[i] - q)`.
- Return `p`.

Time Complexity  : O(N) single-pass traversal over prices
Space Complexity : O(1) auxiliary space
============================================================
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p = 0;
        int n = prices.size();
        int q = prices[0];
        for (int i = 0; i < n; i++) {
            q = min(q, prices[i]);
            p = max(p, prices[i] - q);
        }
        return p;
    }
};