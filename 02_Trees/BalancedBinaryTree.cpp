/*
============================================================
Problem Name : Balanced Binary Tree
LeetCode ID  : 110
NeetCode ID  : balanced-binary-tree
Difficulty   : Easy
Topic        : Trees
Date Solved  : 2026-09-20

Problem Statement:
Given a binary tree, determine if it is height-balanced. 
A height-balanced binary tree is defined as a binary tree in which 
the depth of the two subtrees of every node never differs by more than one.

Approach:
Bottom-up DFS with Sentinel Early Failure (-1):
- Use a helper function `BalanceCheck(root)` that returns the subtree height 
  if balanced, or `-1` immediately if an imbalance is detected.
- Base Case:
  - If `root == nullptr`, depth is 0.
- Recursive Steps:
  - Recursively compute the left subtree height `leftH = BalanceCheck(root->left)`.
  - If `leftH == -1`, propagate failure upwards immediately without extra work.
  - Recursively compute the right subtree height `rightH = BalanceCheck(root->right)`.
  - If `rightH == -1`, propagate failure upwards immediately.
  - Evaluate balance condition: If `abs(leftH - rightH) > 1`, return `-1`.
  - If balanced, return the current node's height: `1 + max(leftH, rightH)`.
- In `isBalanced`, return true if `BalanceCheck(root) != -1`, else false.

Time Complexity  : O(N) where N is the total number of nodes (each node visited at most once)
Space Complexity : O(H) auxiliary recursion stack space, where H is tree height (O(N) worst-case)
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

    int BalanceCheck(TreeNode* root){
        if(root == nullptr) return 0;

        int leftH = BalanceCheck(root->left);
        if(leftH == -1) return -1;
        int rightH = BalanceCheck(root->right);
        if(rightH == -1) return -1;
        if(abs(leftH-rightH) > 1) return -1;
        return 1+max(leftH,rightH);
    }
    bool isBalanced(TreeNode* root) {
        return (BalanceCheck(root) != -1);
    }
};