/*
============================================================
Problem Name : Symmetric Tree
LeetCode ID  : 101
NeetCode ID  : symmetric-tree
Difficulty   : Easy
Topic        : Trees
Date Solved  : 2026-09-20

Problem Statement:
Given the root of a binary tree, check whether it is a mirror 
of itself (i.e., symmetric around its center).

Approach:
Recursive dual-pointer tree mirroring check:
- Delegate the evaluation to a helper function `check(p, q)` initialized 
  with the root's left and right children (`check(root->left, root->right)`).
- Base Case 1 (Both empty):
  - If `p == nullptr && q == nullptr`, both subtrees are mirrored and empty; return true.
- Base Case 2 (Structural or value asymmetry):
  - If exactly one pointer is null (`p == nullptr || q == nullptr`), structure is asymmetric; return false.
  - If values mismatch (`p->val != q->val`), values are asymmetric; return false.
- Recursive Step (Cross-mirror validation):
  - Check outer subtree symmetry: `check(p->left, q->right)`.
  - Check inner subtree symmetry: `check(p->right, q->left)`.
  - Return true only if both outer and inner pairs are symmetric (`&&`).

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
    bool check(TreeNode* p,TreeNode* q){
        if(p == nullptr && q == nullptr) return true;
        if(p== nullptr || q == nullptr) return false;
        if(p->val != q->val) return false;
        return check(p->left,q->right) && check(p->right,q->left);
    }

    bool isSymmetric(TreeNode* root) {
       return check(root->left,root->right);
    }
};