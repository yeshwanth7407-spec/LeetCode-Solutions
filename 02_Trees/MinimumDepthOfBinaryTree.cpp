/*
============================================================
Problem Name : Minimum Depth of Binary Tree
LeetCode ID  : 111
NeetCode ID  : minimum-depth-of-binary-tree
Difficulty   : Easy
Topic        : Trees
Date Solved  : 2026-09-20

Problem Statement:
Given a binary tree, find its minimum depth. The minimum depth 
is the number of nodes along the shortest path from the root node 
down to the nearest leaf node. A leaf is a node with no children.

Approach:
Level-Order Breadth-First Search (BFS) for Shortest Path:
- Base Case: If `root == nullptr`, the tree is empty; return 0.
- Initialize an auxiliary queue with `root` and set current `depth = 1`.
- While the queue is non-empty:
  - Determine the number of nodes at the current level (`s = q.size()`).
  - Process all `s` nodes at this depth level:
    - Pop front node `x`.
    - Check leaf condition: If `x->left == nullptr && x->right == nullptr`, 
      the first encountered leaf represents the global minimum depth; 
      immediately return `depth`.
    - Otherwise, push non-null children (`x->left`, `x->right`) into the queue.
  - Increment `depth` by 1 and proceed to the next level.
- Return `depth`.

Time Complexity  : O(N) worst-case, but optimal O(K) where K is nodes visited up to the first leaf
Space Complexity : O(W) where W is the maximum tree width (at most N/2 in a balanced tree)
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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int depth = 1;
        queue<TreeNode*> q ;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode* x = q.front();
                q.pop();
                if(x->left == nullptr && x->right == nullptr) return depth;
                if(x->left != nullptr) q.push(x->left);
                if(x->right != nullptr) q.push(x->right);
            }
            depth++;
        }
        return depth;
    }
};