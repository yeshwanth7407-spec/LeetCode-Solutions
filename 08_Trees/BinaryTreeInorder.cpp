/*
============================================================
Problem Name : Binary Tree Inorder Traversal
LeetCode ID  : 94
NeetCode ID  : binary-tree-inorder-traversal
Difficulty   : Easy
Topic        : Trees
Date Solved  : 2026-09-18

Problem Statement:
Given the root of a binary tree, return the inorder traversal 
of its nodes' values (Left -> Root -> Right).

Approach:
Iterative traversal using an explicit LIFO call stack:
- Initialize an auxiliary stack of TreeNode pointers and set `curr = root`.
- While the stack is non-empty or `curr != nullptr`:
  - Traverse left-first: Push `curr` onto the stack and set `curr = curr->left` 
    until reaching the leftmost descendant (`nullptr`).
  - Backtrack to the parent: Pop the top node from the stack, record its value 
    into the result list `v` (processing the Root).
  - Shift exploration to the right subtree: Set `curr = curr->right`.
- Repeat until all subtrees and stack frames are fully processed.

Time Complexity  : O(N) where N is the total number of nodes
Space Complexity : O(H) auxiliary space for the stack, where H is the tree height (O(N) worst-case)
============================================================
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> v;
        stack<TreeNode*> s;
        while(!s.empty() || curr != nullptr){
            while(curr != nullptr){
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            v.push_back(curr->val);
            curr = curr->right;
        }
        return v;
    }
};