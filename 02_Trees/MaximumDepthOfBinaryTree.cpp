/*
============================================================
Problem Name : Maximum Depth of Binary Tree
LeetCode ID  : 104
NeetCode ID  : maximum-depth-of-binary-tree
Difficulty   : Easy
Topic        : Trees
Date Solved  : 2026-09-20

Problem Statement:
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along 
the longest path from the root node down to the farthest leaf node.

Approach:
Recursive Depth-First Search (DFS) Post-Order Traversal:
- Base Case:
  - If `root == nullptr`, the tree is empty; return a depth of 0.
- Recursive Steps:
  - Recursively compute the maximum depth of the left subtree: `lH = maxDepth(root->left)`.
  - Recursively compute the maximum depth of the right subtree: `rH = maxDepth(root->right)`.
  - The maximum depth at the current node is 1 plus the larger of the two 
    subtree heights: `1 + max(lH, rH)`.
- Return the computed depth.

Time Complexity  : O(N) where N is the total number of nodes (each node visited once)
Space Complexity : O(H) auxiliary recursion stack space, where H is the height of the tree (O(N) worst-case)
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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int lH = maxDepth(root->left);
        int rH = maxDepth(root->right);
        return 1+max(lH,rH);
    }
};