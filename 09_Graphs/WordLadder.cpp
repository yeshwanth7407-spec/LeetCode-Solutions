/*
============================================================
Problem Name : Word Ladder
LeetCode ID  : 127
NeetCode ID  : word-ladder
Difficulty   : Hard
Topic        : Graphs
Date Solved  : 2026-10-18

Problem Statement:
A transformation sequence from word beginWord to word endWord using a 
dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk 
such that:
- Every adjacent pair of words differs by exactly one letter.
- Every si for 1 <= i <= k is in wordList. Note that beginWord does not need 
  to be in wordList.
- sk == endWord.
Given two words, beginWord and endWord, and a dictionary wordList, return 
the number of words in the shortest transformation sequence from beginWord 
to endWord, or 0 if no such sequence exists.

Approach:
Breadth-First Search (BFS) Shortest Path via Character Mutation:
- Unweighted shortest path on an implicit state graph is optimally solved with BFS.
- Initialization:
  - Populate a hash table / set from `wordList` for O(1) existence checks.
  - If `endWord` does not exist in the dictionary, no valid sequence can reach it -> return 0.
  - If `beginWord == endWord`, return 1.
- Level-Order BFS Traversal:
  - Push `beginWord` into the queue and mark it visited (`m[beginWord] = 1`).
  - Initialize sequence step counter `count = 1`.
  - While the queue is non-empty:
    - Increment `count++` as we advance to the next transformation level.
    - Process all words at the current level using `q.size()`.
    - For each word `t`:
      - Try mutating each character position `j` from 'a' to 'z'.
      - For each candidate word `x`:
        - If `x` exists in the dictionary and is unvisited (`m[x] == 0`):
          - If `x == endWord`, the shortest path is found -> return `count`.
          - Otherwise, mark `m[x] = 1` and push `x` into the queue.
- If the queue exhausts without reaching `endWord`, return 0.

Time Complexity  : O(N * L * 26) = O(N * L), where N is wordList.size() and L is word length
Space Complexity : O(N * L) auxiliary space for queue and dictionary hash map
============================================================
*/

#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) return 1;

        unordered_map<string, int> m;
        for (const auto& x : wordList) {
            m[x] = 0;
        }

        if (m.find(endWord) == m.end()) return 0;

        queue<string> q;
        q.push(beginWord);
        m[beginWord] = 1;
        int count = 1;

        while (!q.empty()) {
            int s = q.size();
            count++;
            for (int i = 0; i < s; i++) {
                string t = q.front();
                q.pop();

                for (int j = 0; j < t.length(); j++) {
                    string x = t;
                    for (char k = 'a'; k <= 'z'; k++) {
                        x[j] = k;
                        if (m.find(x) != m.end() && m[x] == 0) {
                            if (x == endWord) return count;
                            q.push(x);
                            m[x] = 1;
                        }
                    }
                }
            }
        }

        return 0;
    }
};