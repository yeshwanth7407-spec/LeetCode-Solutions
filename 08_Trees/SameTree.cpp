/*
============================================================
Problem Name : Same Tree
LeetCode ID  : 100
NeetCode ID  : same-tree
Difficulty   : Easy
Topic        : Trees
Date Solved  : 2026-09-20

Problem Statement:
Given the roots of two binary trees p and q, write a function 
to check if they are the same or not. Two binary trees are 
considered the same if they are structurally identical, and 
the nodes have the same value.

Approach:
Recursive structural depth-first search (DFS):
- Base Case 1 (Both empty): If both `p == nullptr` and `q == nullptr`, 
  both subtrees are identical; return true.
- Base Case 2 (Structural or value mismatch):
  - If exactly one node is `nullptr` (`p == nullptr || q == nullptr`), 
    the tree structures differ; return false.
  - If neither is null but values differ (`p->val != q->val`), return false.
- Recursive Step:
  - Both current nodes match. Recursively check whether the left subtrees 
    match (`isSameTree(p->left, q->left)`) AND the right subtrees match 
    (`isSameTree(p->right, q->right)`).
  - Return the conjunction (`&&`) of both subtree checks.

Time Complexity  : O(min(N, M)) where N and M are the number of nodes in trees p and q
Space Complexity : O(min(H_p, H_q)) auxiliary recursion stack space, where H is tree height
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
      if(p == nullptr && q==nullptr) return true;
      if((p==nullptr || q==nullptr) || (p->val != q->val)) return false;
      return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};