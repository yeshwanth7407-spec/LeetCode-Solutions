/*
============================================================
Problem Name : Linked List Cycle
LeetCode ID  : 141
NeetCode ID  : linked-list-cycle
Difficulty   : Easy
Topic        : Linked List
Date Solved  : 2026-10-09

Problem Statement:
Given head, the head of a linked list, determine if the linked list 
has a cycle in it. There is a cycle in a linked list if there is some 
node in the list that can be reached again by continuously following 
the next pointer. Return true if there is a cycle in the linked list. 
Otherwise, return false.

Approach:
Hash Table / Node Address Frequency Map:
- Traverse the singly linked list using pointer `curr` initialized to `head`.
- Maintain an `unordered_map<ListNode*, int> m` storing visited node memory addresses.
- At each node:
  - Check if `m[curr] == 1`: If the node pointer has already been recorded, 
    the traversal has looped back onto an earlier node, confirming a cycle -> Return true.
  - Mark `m[curr] = 1`.
  - Advance `curr = curr->next`.
- If `curr` reaches `nullptr`, the end of the list was reached with no loop -> Return false.

Time Complexity  : O(N) where N is the number of nodes in the linked list
Space Complexity : O(N) auxiliary space stored in the hash map
============================================================
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int> m;
        ListNode* curr = head;
        while(curr != nullptr){
            if(m[curr]==1){
                return true;
            }
            m[curr] = 1;
            curr = curr->next;
        }
        return false;
    }
};