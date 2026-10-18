/*
============================================================
Problem Name : Alien Dictionary
LeetCode ID  : 269
NeetCode ID  : foreign-dictionary
Difficulty   : Hard
Topic        : Graphs / Topological Sort
Date Solved  : 2026-10-18

Problem Statement:
There is a foreign language which uses the Latin alphabet, but the order 
among letters is not "a", "b", "c" ... "z". You receive a list of non-empty 
strings words from the dictionary, where words are sorted lexicographically 
by the rules of this new language. Derive the order of letters in this language. 
If the order is invalid, return an empty string. If there are multiple valid 
orders, return any of them.

Approach:
Kahn's Algorithm (DAG Topological Sort with Prefix Invalidation):
- Unique Character Identification:
  - Identify all unique characters present across all words (`present` vector).
  - Count `total` distinct characters that must appear in the final alphabet sequence.
- Directed Edge Extraction & Prefix Validation:
  - Compare adjacent words `words[i - 1]` and `words[i]`:
    - Find the first index `j` where `words[i - 1][j] != words[i][j]`.
    - Establish directed relationship `u -> v` (where `u` precedes `v` in the alphabet).
    - If edge `(u, v)` does not already exist, add `v` to `adj[u]` and increment `inedge[v]++`.
    - Edge Case Check: If no differing character is found up to `min_len`, but 
      `words[i - 1].size() > words[i].size()` (e.g., ["abc", "ab"]), the lexicon 
      order is invalid -> return "" immediately.
- BFS Topological Sort:
  - Enqueue all present characters with `inedge[i] == 0`.
  - While queue is not empty, pop character `u`, append `char('a' + u)` to `ans`, 
    and decrement incoming edges for all its neighbors.
  - If a neighbor's `inedge` reaches 0, push it to the queue.
- Cycle Detection:
  - If `ans.size() != total`, a cycle exists (contradictory ordering) -> return "".
  - Otherwise, return `ans`.

Time Complexity  : O(C + V + E) where C is the total characters across all words, V <= 26, E <= 26^2
Space Complexity : O(1) auxiliary space (bounded by fixed alphabet size 26)
============================================================
*/

#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        vector<int> inedge(26, 0);
        vector<bool> present(26, false);

        int total = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                int ch = words[i][j] - 'a';
                if (!present[ch]) {
                    present[ch] = true;
                    total++;
                }
            }
        }

        for (int i = 1; i < words.size(); i++) {
            int s = min(words[i - 1].size(), words[i].size());
            bool found = false;

            for (int j = 0; j < s; j++) {
                if (words[i - 1][j] != words[i][j]) {
                    int u = words[i - 1][j] - 'a';
                    int v = words[i][j] - 'a';
                    bool exists = false;

                    for (int neighbor : adj[u]) {
                        if (neighbor == v) {
                            exists = true;
                            break;
                        }
                    }

                    if (!exists) {
                        adj[u].push_back(v);
                        inedge[v]++;
                    }

                    found = true;
                    break;
                }
            }

            if (!found && words[i - 1].size() > words[i].size()) {
                return "";
            }
        }

        queue<int> q;

        for (int i = 0; i < 26; i++) {
            if (present[i] && inedge[i] == 0) {
                q.push(i);
            }
        }

        string ans;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            ans.push_back(char('a' + u));

            for (int v : adj[u]) {
                inedge[v]--;

                if (inedge[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (ans.size() != total) {
            return "";
        }

        return ans;
    }
};