/*
============================================================
Problem Name : Convert Sorted Array to Binary Search Tree
LeetCode ID  : 108
NeetCode ID  : convert-sorted-array-to-binary-search-tree
Difficulty   : Easy
Topic        : Trees
Date Solved  : 2026-09-20

Problem Statement:
Given an integer array nums where the elements are sorted in 
ascending order, convert it to a height-balanced binary search tree (BST).
A height-balanced binary tree is a binary tree in which the depth of 
the two subtrees of every node never differs by more than one.

Approach:
Divide-and-Conquer / Recursive Binary Search Construction:
- To guarantee height-balance, pick the middle element of the current subarray 
  as the root node. This ensures the left and right subtrees have equal or 
  near-equal (differing by at most 1) numbers of nodes.
- Helper function `BST(v, start, end)`:
  - Base Case 1: If `start > end`, no elements exist; return `nullptr`.
  - Base Case 2: If `start == end`, a single element exists; return `new TreeNode(v[start])`.
  - Recursive Step:
    - Compute middle index: `mid = start + (end - start) / 2`.
    - Create a new node with `v[mid]` as the current subtree root.
    - Recursively construct the left subtree from `start` to `mid - 1`.
    - Recursively construct the right subtree from `mid + 1` to `end`.
    - Attach the resulting child subtrees and return `root`.
- In `sortedArrayToBST`, initiate recursion over the full range: `0` to `nums.size() - 1`.

Time Complexity  : O(N) where N is the number of elements in nums (every node is created once)
Space Complexity : O(log N) auxiliary recursion stack space (the tree is guaranteed balanced)
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

    TreeNode* BST(vector<int>& v,int start,int end){
        if(start>end) return nullptr;
        if(start==end) return new TreeNode(v[start]);
        int mid = start + (end-start)/2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = BST(v,start,mid-1);
        root->right = BST(v,mid+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST(nums,0,nums.size()-1);
    }
};