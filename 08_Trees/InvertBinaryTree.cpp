/*
============================================================
Problem Name : Invert Binary Tree
LeetCode ID  : 226
NeetCode ID  : invert-binary-tree
Difficulty   : Easy
Topic        : Trees
Date Solved  : 2026-09-20

Problem Statement:
Given the root of a binary tree, invert the tree, and return its root.
Inverting a binary tree means swapping every left and right child 
subtree across all levels.

Approach:
Recursive Depth-First Search (DFS) / Post-Order Inversion:
- Base Case:
  - If `root == nullptr`, the tree is empty; return `nullptr`.
- Recursive Steps:
  - Recursively invert the right subtree: `leftS = invertTree(root->right)`.
  - Recursively invert the left subtree: `rightS = invertTree(root->left)`.
  - Reassign the inverted subtrees to their swapped opposite child pointers:
    `root->left = leftS;`
    `root->right = rightS;`
- Return `root`.

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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        TreeNode* leftS = invertTree(root->right);
        TreeNode* rightS = invertTree(root->left);
        root->left = leftS;
        root->right = rightS;
        return root;
    }
};