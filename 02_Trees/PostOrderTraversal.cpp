/*
============================================================
Problem Name : Binary Tree Postorder Traversal
LeetCode ID  : 145
NeetCode ID  : binary-tree-postorder-traversal
Difficulty   : Easy
Topic        : Trees
Date Solved  : 2026-09-20

Problem Statement:
Given the root of a binary tree, return the postorder traversal 
of its nodes' values (Left -> Right -> Root).

Approach:
Recursive Depth-First Search (DFS) postorder traversal:
- Use a helper function `traverse(root, result)` to pass the output vector by reference.
- Base Case:
  - If `root == nullptr`, return immediately.
- Recursive Steps:
  - 1. Recursively traverse the left subtree: `traverse(root->left, result)`.
  - 2. Recursively traverse the right subtree: `traverse(root->right, result)`.
  - 3. Process current node: Push `root->val` into `result`.
- In `postorderTraversal`, initialize `result`, invoke `traverse(root, result)`, and return `result`.

Time Complexity  : O(N) where N is the total number of nodes (each node visited once)
Space Complexity : O(H) auxiliary recursion stack space, where H is the tree height (O(N) worst-case)
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
    void traverse(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        
        traverse(root->left, result);  // 1. Left
        traverse(root->right, result); // 2. Right
        result.push_back(root->val);   // 3. Root
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
};
