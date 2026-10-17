/*
============================================================
Problem Name : Is Graph Bipartite?
LeetCode ID  : 785
NeetCode ID  : is-graph-bipartite
Difficulty   : Medium
Topic        : Graphs
Date Solved  : 2026-10-17

Problem Statement:
There is an undirected graph with n nodes, where each node is numbered 
between 0 and n - 1. You are given a 2D array graph, where graph[u] is 
an array of nodes that node u is adjacent to. Return true if and only if 
it is bipartite. A graph is bipartite if the nodes can be partitioned 
into two independent sets A and B such that every edge in the graph 
connects a node in set A and a node in set B.

Approach:
Breadth-First Search (BFS) 2-Coloring:
- A graph is bipartite if and only if it does not contain an odd-length cycle, 
  which is equivalent to being 2-colorable.
- Initialize a `color` array of size `V` with `-1` (uncolored).
- Because the graph may be disconnected, iterate through all vertices `i` from `0` to `V - 1`:
  - If node `i` is uncolored (`color[i] == -1`):
    - Assign it an initial color (e.g., `color[i] = 1`) and enqueue it.
    - While the BFS queue is non-empty:
      - Dequeue the front vertex `t`.
      - For each adjacent neighbor `neighbor` in `graph[t]`:
        - If uncolored (`color[neighbor] == -1`):
          - Assign the opposite color (`color[neighbor] = (color[t] == 1) ? 2 : 1`).
          - Enqueue `neighbor`.
        - Else if already colored:
          - If `color[neighbor] == color[t]`, adjacent vertices share the 
            same color, violating bipartiteness -> Return false.
- If all connected components are 2-colored without conflict, return true.

Time Complexity  : O(V + E) where V is graph.size() and E is total edges
Space Complexity : O(V) auxiliary space for color array and BFS queue
============================================================
*/

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        queue<int> q;

        for (int i = 0; i < graph.size(); i++) {
            if (color[i] == -1) {
                q.push(i);
                color[i] = 1;

                while (!q.empty()) {
                    int t = q.front();
                    q.pop();

                    for (int j = 0; j < graph[t].size(); j++) {
                        int neighbor = graph[t][j];
                        if (color[neighbor] == -1) {
                            q.push(neighbor);
                            color[neighbor] = (color[t] == 1) ? 2 : 1;
                        } else {
                            if (color[t] == color[neighbor]) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};