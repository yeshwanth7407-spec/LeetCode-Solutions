/*
============================================================
Problem Name : Find Mode in Binary Search Tree
LeetCode ID  : 501
NeetCode ID  : find-mode-in-binary-search-tree
Difficulty   : Easy
Topic        : Trees
Date Solved  : 2026-09-28

Problem Statement:
Given the root of a binary search tree (BST) with duplicates, 
return all the mode(s) (i.e., the most frequently occurred element(s)) in it.
If the tree has more than one mode, return them in any order.

Approach:
DFS tree traversal with hash map frequency counting:
- Helper function `Traverse(root, ans, freq)`:
  - Recursively visit every node in the binary search tree using DFS.
  - Increment the occurrence frequency of `root->val` in `freq[root->val]`.
- In `findMode`:
  - Execute `Traverse` to populate the frequency map `freq`.
  - Perform a first pass over `freq` to determine the maximum frequency `maxFreq`.
  - Perform a second pass over `freq` to collect all keys whose frequency 
    matches `maxFreq` into the `ans` vector.
- Return the collected modes `ans`.

Time Complexity  : O(N) where N is the total number of nodes in the BST
Space Complexity : O(N) auxiliary space for the hash map and recursion stack
============================================================
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void Traverse(TreeNode* root, vector<int>& ans, unordered_map<int, int>& freq) {
        if (root == nullptr) return;

        freq[root->val]++;

        Traverse(root->left, ans, freq);
        Traverse(root->right, ans, freq);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        unordered_map<int, int> freq;

        Traverse(root, ans, freq);

        int maxFreq = 0;

        for (auto& p : freq) {
            maxFreq = max(maxFreq, p.second);
        }

        for (auto& p : freq) {
            if (p.second == maxFreq) {
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};