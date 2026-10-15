/*
============================================================
Problem Name : Number of Provinces
LeetCode ID  : 547
NeetCode ID  : number-of-provinces
Difficulty   : Medium
Topic        : Graphs
Date Solved  : 2026-10-15

Problem Statement:
There are n cities. Some of them are connected, while some are not. 
If city a is connected directly with city b, and city b is connected 
directly with city c, then city a is connected indirectly with city c.
A province is a group of directly or indirectly connected cities and 
no other cities outside of the group. You are given an n x n matrix 
isConnected where isConnected[i][j] = 1 if the i-th city and the j-th 
city are directly connected, and isConnected[i][j] = 0 otherwise.
Return the total number of provinces.

Approach:
Depth-First Search (Connected Components Count):
- Model the cities and their connectivity as an undirected graph represented 
  by an adjacency matrix `isConnected` of size n x n.
- Maintain a `visited` array of size `n` initialized to 0 to track explored cities.
- Iterate through each city from index 0 to n - 1:
  - If city `i` has not been visited (`visited[i] == 0`):
    - Increment `count` (indicating the start of a new connected component/province).
    - Launch DFS recursion (`Helper`) starting from city `i`:
      - Mark current city `c` as visited (`visited[c] = 1`).
      - Check all possible neighbors `j` from 0 to n - 1:
        - If an edge exists (`isConnected[c][j] == 1`) and neighbor `j` is 
          unvisited (`visited[j] == 0`), recursively visit city `j`.
- Return the final province `count`.

Time Complexity  : O(N^2) where N is the number of cities (traversing the N x N adjacency matrix)
Space Complexity : O(N) auxiliary space for visited array and call stack recursion
============================================================
*/

class Solution {
public:
    void Helper(vector<vector<int>>& adj, vector<int>& visited, int c) {
        visited[c] = 1;
        for (int i = 0; i < adj.size(); i++) {
            if (adj[c][i] == 1 && visited[i] == 0) {
                Helper(adj, visited, i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                count++;
                Helper(isConnected, visited, i);
            }
        }
        return count;
    }
};