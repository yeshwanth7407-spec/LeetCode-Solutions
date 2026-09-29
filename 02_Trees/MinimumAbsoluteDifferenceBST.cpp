/*
============================================================
Problem Name : Minimum Absolute Difference in BST
LeetCode ID  : 530
NeetCode ID  : minimum-absolute-difference-in-bst
Difficulty   : Easy
Topic        : Trees
Date Solved  : 2026-09-29

Problem Statement:
Given the root of a Binary Search Tree (BST), return the minimum 
absolute difference between the values of any two different nodes 
in the tree.

Approach:
In-Order Traversal with Previous Node Tracking:
- An in-order traversal (Left -> Root -> Right) of a Binary Search Tree 
  visits the node values in strictly non-decreasing sorted order.
- In a sorted sequence, the minimum absolute difference must occur between 
  two adjacent elements.
- Maintain:
  - `mini`: tracks the running minimum absolute difference, initialized to INT_MAX.
  - `old`: pointer to the previously visited node in the in-order sequence.
- Helper function `Traverse(root)`:
  - Base Case: If `root == nullptr`, return immediately.
  - Recursively visit the left subtree: `Traverse(root->left)`.
  - Process Current Node:
    - If `old != nullptr`, compute the difference `root->val - old->val` and 
      update `mini = min(mini, root->val - old->val)`.
    - Update `old = root`.
  - Recursively visit the right subtree: `Traverse(root->right)`.
- In `getMinimumDifference`, invoke `Traverse(root)` and return `mini`.

Time Complexity  : O(N) where N is the total number of nodes in the BST
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
    int mini = INT_MAX;
    TreeNode* old = nullptr;
    void Traverse(TreeNode* root){
        if(root==nullptr) return;
        Traverse(root->left);
        if (old != nullptr) {
            mini = min(mini, root->val - old->val);
        }
        old = root;
        Traverse(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        Traverse(root);
        return mini;
    }
};