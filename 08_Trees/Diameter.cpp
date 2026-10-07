/*
============================================================
Problem Name : Diameter of Binary Tree
LeetCode ID  : 543
NeetCode ID  : diameter-of-binary-tree
Difficulty   : Easy
Topic        : Trees
Date Solved  : 2026-09-29

Problem Statement:
Given the root of a binary tree, return the length of the diameter 
of the tree. The diameter of a binary tree is the length of the longest 
path between any two nodes in a tree. This path may or may not pass 
through the root. The length of a path between two nodes is represented 
by the number of edges between them.

Approach:
Bottom-Up Depth-First Search (DFS) / Height Aggregation:
- The longest path passing through any specific node is the sum of the 
  maximum depths of its left and right subtrees: `leftH + rightH`.
- Maintain a running maximum variable `diameter` tracking the longest path 
  found across all nodes.
- Helper function `Height(root)`:
  - Base Case: If `root == nullptr`, depth is 0.
  - Recursively compute the left subtree height: `leftH = Height(root->left)`.
  - Recursively compute the right subtree height: `rightH = Height(root->right)`.
  - Update `diameter = max(diameter, (long long)leftH + rightH)`.
  - Return the height of the current subtree: `1 + max(leftH, rightH)`.
- In `diameterOfBinaryTree`:
  - Call `Height(root)` to populate `diameter`.
  - Return `diameter`.

Time Complexity  : O(N) where N is the total number of nodes in the binary tree
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
    long long diameter = INT_MIN;
    int Height(TreeNode* root){
        if(root==nullptr) return 0;
        int leftH = Height(root->left);
        int rightH = Height(root->right);
        diameter = max(diameter,(long long)leftH+rightH);
        return 1+max(leftH,rightH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        Height(root);
        return diameter;
    }
    
};