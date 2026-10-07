/*
============================================================
Problem Name : Binary Tree Preorder Traversal
LeetCode ID  : 144
NeetCode ID  : binary-tree-preorder-traversal
Difficulty   : Easy
Topic        : Trees
Date Solved  : 2026-09-20

Problem Statement:
Given the root of a binary tree, return the preorder traversal 
of its nodes' values (Root -> Left -> Right).

Approach:
Iterative traversal using an explicit LIFO stack:
- Base Case: If `root == nullptr`, the tree is empty; return an empty vector `{}`.
- Initialize an explicit stack of TreeNode pointers and push `root`.
- While the stack is non-empty:
  - Pop the top node `x` from the stack.
  - Record `x->val` into the result vector `v` (processing Root first).
  - Push the right child (`x->right`) onto the stack first if non-null.
  - Push the left child (`x->left`) onto the stack second if non-null.
    (Because stacks are LIFO, pushing Right before Left guarantees 
    that the Left child is popped and processed first).
- Continue until all reachable nodes are traversed and return `v`.

Time Complexity  : O(N) where N is the total number of nodes (each node visited once)
Space Complexity : O(H) auxiliary space for the stack, where H is the tree height (O(N) worst-case)
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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> v;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* x = s.top();
            s.pop();
            v.push_back(x->val);
            if(x->right != nullptr) s.push(x->right);
            if(x->left != nullptr) s.push(x->left);
        }
        return v;

    }
};