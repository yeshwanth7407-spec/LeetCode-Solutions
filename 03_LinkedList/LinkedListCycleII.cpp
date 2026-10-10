/*
============================================================
Problem Name : Linked List Cycle II
LeetCode ID  : 142
NeetCode ID  : linked-list-cycle-ii
Difficulty   : Medium
Topic        : Linked List
Date Solved  : 2026-10-09

Problem Statement:
Given the head of a linked list, return the node where the cycle 
begins. If there is no cycle, return null. There is a cycle in a 
linked list if there is some node in the list that can be reached 
again by continuously following the next pointer. Do not modify 
the linked list.

Approach:
Hash Table / Address Visited Set Traversal:
- Maintain an `unordered_map<ListNode*, int> m` to record the memory 
  addresses of visited nodes.
- Traverse the linked list starting from `head` using pointer `curr`:
  - Before advancing, check if the current node `curr` is already recorded in `m`:
    - If `m[curr] == 1`, this node has been visited previously, confirming it 
      is the exact entrance node where the cycle begins -> return `curr`.
  - Otherwise, mark `curr` as visited by setting `m[curr] = 1`.
  - Advance `curr` to its next node (`curr = curr->next`).
- If `curr` reaches `nullptr`, the list terminates naturally with no cycle -> return `nullptr`.

Time Complexity  : O(N) where N is the number of nodes in the linked list
Space Complexity : O(N) auxiliary space used by the hash map
============================================================
*/

#include<unordered_map>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> m;
        ListNode* curr = head;

        while (curr != nullptr) {
            if (m[curr] == 1) return curr;
            m[curr] = 1;
            curr = curr->next;
        }

        return nullptr;
    }
};