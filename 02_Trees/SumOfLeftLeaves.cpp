/*
============================================================
Problem Name : Sum of Left Leaves
LeetCode ID  : 404
NeetCode ID  : sum-of-left-leaves
Difficulty   : Easy
Topic        : Trees
Date Solved  : 2026-09-28

Problem Statement:
Given the root of a binary tree, return the sum of all left leaves.
A leaf is a node with no children. A left leaf is a leaf that is the 
left child of another node.

Approach:
Depth-First Search (DFS) with Parent-Relative Leaf Check:
- Helper function `leaf(root)`:
  - Returns true if the node is non-null and has no left or right children 
    (`root->left == nullptr && root->right == nullptr`).
- Helper function `Traverse(root, sum)`:
  - Base Case: If `root == nullptr`, return immediately.
  - If the current node possesses a valid left child and that left child 
    is a leaf (`leaf(root->left)`), add `root->left->val` to the running `sum`.
  - Recursively explore both subtrees:
    - `Traverse(root->left, sum)`
    - `Traverse(root->right, sum)`
- In `sumOfLeftLeaves`, initialize `sum = 0`, call `Traverse(root, sum)`, 
  and return the accumulated sum.

Time Complexity  : O(N) where N is the total number of nodes in the binary tree
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

    bool leaf(TreeNode* root){
        if(root==nullptr) return false;
        return (root->left==nullptr && root->right==nullptr);
    }
    void Traverse(TreeNode* root,int& sum){
        if(root==nullptr) return;
        if(leaf(root->left)){
            sum += root->left->val;
        }
        Traverse(root->left,sum);
        Traverse(root->right,sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        Traverse(root,sum);
        return sum;
    }
};