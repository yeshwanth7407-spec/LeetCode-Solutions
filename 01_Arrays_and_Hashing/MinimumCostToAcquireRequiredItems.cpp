/*
============================================================
Problem Name : Minimum Cost to Acquire Required Items
LeetCode ID  : 3789
NeetCode ID  : minimum-cost-to-acquire-required-items
Difficulty   : Medium
Topic        : Greedy / Math
Date Solved  : 2026-11-11

Problem Statement:
You are given five integers cost1, cost2, costBoth, need1, and need2.
There are three types of items available:
- Item of type 1 costs cost1 and contributes 1 unit to the type 1 requirement only.
- Item of type 2 costs cost2 and contributes 1 unit to the type 2 requirement only.
- Item of type 3 costs costBoth and contributes 1 unit to both type 1 and type 2 requirements.
Return an integer representing the minimum possible total cost to achieve these requirements.

Approach:
Case Analysis / Closed-Form Greedy Comparison:
- We can satisfy the demands through three fundamental strategies:
  1. Buy only individual items:
     - Cost = 1LL * need1 * cost1 + 1LL * need2 * cost2.
  2. Buy bundles to cover the common requirement min(need1, need2), 
     then fulfill the remainder using individual items:
     - Bundles purchased: min(need1, need2).
     - Extra items: |need1 - need2| of the larger requirement's single item.
  3. Buy bundles for everything up to max(need1, need2):
     - Even if one requirement overflows, if costBoth is cheaper than the 
       individual items, it can be optimal to buy max(need1, need2) bundles.
     - Cost = 1LL * max(need1, need2) * costBoth.
- Compute each scenario using 64-bit integers (`long long`) to prevent overflow 
  (since need1, need2 <= 10^9 and costs <= 10^6).
- Return the minimum total across all valid candidate strategies.

Time Complexity  : O(1)
Space Complexity : O(1) auxiliary space
============================================================
*/

#include <algorithm>

using namespace std;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long only_singles = 1LL * cost1 * need1 + 1LL * cost2 * need2;
        long long only_bundles = 1LL * max(need1, need2) * costBoth;

        long long common = min(need1, need2);
        long long diff = (need1 < need2) ? (need2 - need1) : (need1 - need2);
        long long remainder_singles = (need1 < need2) ? (1LL * diff * cost2) : (1LL * diff * cost1);
        long long hybrid = 1LL * common * costBoth + remainder_singles;

        return min({only_singles, only_bundles, hybrid});
    }
};