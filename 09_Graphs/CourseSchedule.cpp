/*
============================================================
Problem Name : Course Schedule
LeetCode ID  : 207
NeetCode ID  : course-schedule
Difficulty   : Medium
Topic        : Graphs / Topological Sort
Date Solved  : 2026-10-18

Problem Statement:
There are a total of numCourses courses you have to take, labeled from 
0 to numCourses - 1. You are given an array prerequisites where 
prerequisites[i] = [ai, bi] indicates that you must take course bi first 
if you want to take course ai. Return true if you can finish all courses. 
Otherwise, return false (i.e., if there is a circular dependency / cycle).

Approach:
Kahn's Algorithm (BFS-Based Topological Sort via In-Degree Counting):
- Model courses as vertices in a directed graph where directed edge 
  bi -> ai indicates that taking course bi is a prerequisite for ai:
  - In-degree of ai increases by 1 for each prerequisite required.
- Initialize an in-degree vector `inedges(numCourses, 0)`:
  - Populate `inedges[prerequisites[i][0]]++`.
- Enqueue all courses with an in-degree of 0 (courses with no prerequisites).
- Maintain `total = numCourses` and decrement `total--` each time a valid 
  course with 0 incoming dependencies is enqueued.
- BFS Level Processing:
  - Dequeue course `t`.
  - For all prerequisite pairs where `prerequisites[j][1] == t`:
    - Decrement the dependent course's in-degree: `inedges[prerequisites[j][0]]--`.
    - If its in-degree reaches 0, all its prerequisites have been fulfilled:
      - Enqueue `prerequisites[j][0]` and decrement `total--`.
- If `total == 0` at the end, all courses were successfully ordered without 
  encountering a cycle -> Return true; otherwise return false.

Time Complexity  : O(V + E) with adjacency list (currently O(V * E) due to linear scans over prerequisites)
Space Complexity : O(V) auxiliary space for in-degrees and BFS queue
============================================================
*/

// better approach was using adjacent list so we do not have to explore the prerequisites vector again and again 

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int total = numCourses;
        int n = prerequisites.size();
        vector<int> inedges(numCourses, 0);

        for (int i = 0; i < n; i++) {
            inedges[prerequisites[i][0]]++;
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
                q.pop();

                for (int j = 0; j < n; j++) {
                    if (prerequisites[j][1] == t) {
                        inedges[prerequisites[j][0]]--;
                        if (inedges[prerequisites[j][0]] == 0) {
                            q.push(prerequisites[j][0]);
                            total--;
                        }
                    }
                }
            }
        }

        return (total == 0);
    }
};