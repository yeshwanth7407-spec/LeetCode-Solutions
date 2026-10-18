/*
============================================================
Problem Name : Course Schedule II
LeetCode ID  : 210
NeetCode ID  : course-schedule-ii
Difficulty   : Medium
Topic        : Graphs / Topological Sort
Date Solved  : 2026-10-18

Problem Statement:
There are a total of numCourses courses you have to take, labeled from 
0 to numCourses - 1. You are given an array prerequisites where 
prerequisites[i] = [ai, bi] indicates that you must take course bi first 
if you want to take course ai. Return the ordering of courses you should 
take to finish all courses. If there are many valid answers, return any of 
them. If it is impossible to finish all courses (due to a cycle), return 
an empty array.

Approach:
Kahn's Algorithm (Adjacency-List-Based BFS Topological Sort):
- Graph & Dependency Construction:
  - Directed edge: prerequisite -> course (`bi -> ai`), representing that 
    finishing `bi` unlocks progress on `ai`.
  - Build an adjacency list `adj` of size `numCourses` where `adj[bi]` holds 
    all outgoing dependent courses.
  - Compute in-degrees: `inedges[ai]++` counts how many prerequisites course `ai` requires.
- Queue Initialization:
  - Enqueue all courses with `inedges[i] == 0` (courses with zero prerequisites).
  - Decrement `total--` for each initial independent course.
- Topological Traversal:
  - While `q` is non-empty, pop the front course `t`.
  - Append `t` to `ans` as the next valid course in the completion order.
  - Traverse all direct dependents in `adj[t]`:
    - Decrement neighbor in-degree: `inedges[neighbor]--`.
    - If `inedges[neighbor] == 0`, all prerequisite dependencies have 
      been cleared -> enqueue `neighbor` and decrement `total--`.
- Cycle Validation:
  - If `total != 0`, a circular dependency exists preventing all courses 
    from completing -> return empty vector `{}`.
  - Otherwise, return `ans`.

Improvements Compared to Course Schedule (LeetCode 207):
- Transitioned from an edge-list linear scan to an explicit adjacency list (`adj`):
  Eliminated the inner O(E) search loop over prerequisites on every queue pop, 
  reducing overall graph traversal time from O(V * E) down to optimal O(V + E).
- Added ordered path reconstruction (`ans` vector):
  Records the chronological topological sequence as nodes reach in-degree 0, 
  rather than only returning a boolean existence check.

Time Complexity  : O(V + E) where V is numCourses and E is prerequisites.size()
Space Complexity : O(V + E) auxiliary space for adjacency list, in-degree vector, and queue
============================================================
*/

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int total = numCourses;
        int n = prerequisites.size();
        vector<int> inedges(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            inedges[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> q;
        for (int i = 0; i < inedges.size(); i++) {
            if (inedges[i] == 0) {
                q.push(i);
                total--;
            }
        }

        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                int t = q.front();
                ans.push_back(t);
                q.pop();

                for (int j = 0; j < adj[t].size(); j++) {
                    inedges[adj[t][j]]--;
                    if (inedges[adj[t][j]] == 0) {
                        q.push(adj[t][j]);
                        total--;
                    }
                }
            }
        }

        if (total != 0) ans = {};
        return ans;
    }
};