/*
============================================================
Problem Name : Find Eventual Safe States
LeetCode ID  : 802
NeetCode ID  : find-eventual-safe-states
Difficulty   : Medium
Topic        : Graphs / Topological Sort
Date Solved  : 2026-10-19

Problem Statement:
There is a directed graph of n nodes with each node labeled from 0 to n - 1. 
The graph is represented by a 0-indexed 2D integer array graph where graph[i] 
is an integer array of nodes adjacent to node i, meaning there is an edge 
from node i to each node in graph[i]. A node is a terminal node if there are 
no outgoing edges. A node is a safe node if every possible path starting 
from that node leads to a terminal node (or another safe node).
Return an array containing all the safe nodes of the graph, sorted in 
ascending order.

Approach:
Kahn's Algorithm on Reversed Graph (Out-Degree Topological Sort):
- Key Observation:
  - Terminal nodes have an out-degree of 0 and are inherently safe.
  - Any node whose outgoing edges ONLY lead to terminal/safe nodes is also safe.
  - Nodes that can reach or be part of a directed cycle can never terminate.
- Reversed Graph Modeling:
  - If we reverse all edges (`u -> v` becomes `v -> u`), terminal nodes 
    become nodes with an in-degree of 0 in the reversed graph.
  - Track `outcount[i]` representing the original out-degree of node `i`.
  - Construct the reverse adjacency list `adj` where `adj[v].push_back(u)`.
- Topological Traversal:
  - Enqueue all nodes with `outcount[i] == 0` (terminal nodes) and mark `track[i] = true`.
  - While the queue is not empty:
    - Pop node `t`.
    - For every predecessor `pre` in `adj[t]`:
      - Decrement `outcount[pre]--`.
      - If `outcount[pre] == 0`, all paths originating from `pre` lead strictly 
        to known safe nodes -> mark `track[pre] = true` and enqueue `pre`.
- Result Assembly:
  - Collect all nodes `i` from 0 to n - 1 where `track[i] == true`.
  - Since indices are traversed sequentially from 0 to n - 1, the result 
    is naturally sorted in ascending order.

Time Complexity  : O(V + E) where V is graph.size() and E is the total directed edges
Space Complexity : O(V + E) auxiliary space for reversed adjacency list, tracking array, and queue
============================================================
*/

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outcount(n, 0);
        for (int i = 0; i < n; i++) {
            outcount[i] = graph[i].size();
        }

        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adj[graph[i][j]].push_back(i);
            }
        }

        vector<bool> track(n, false);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (outcount[i] == 0) {
                q.push(i);
                track[i] = true;
            }
        }

        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                int t = q.front();
                q.pop();

                for (int j = 0; j < adj[t].size(); j++) {
                    outcount[adj[t][j]]--;
                    if (outcount[adj[t][j]] == 0) {
                        q.push(adj[t][j]);
                        track[adj[t][j]] = true;
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (track[i] == true) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};