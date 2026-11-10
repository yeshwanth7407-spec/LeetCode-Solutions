/*
============================================================
Problem Name : Add Two Numbers
LeetCode ID  : 2
NeetCode ID  : add-two-numbers
Difficulty   : Medium
Topic        : Linked List / Simulation
Date Solved  : 2026-11-10

Problem Statement:
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list. You may assume the two numbers 
do not contain any leading zero, except the number 0 itself.

Approach:
Digit-by-Digit Addition Simulation with Carry:
- Digits are ordered from least significant to most significant (reverse order), 
  allowing direct parallel traversal from the head of both lists.
- Initialize carry `c = 0` and construct the head node `root` using the sum of 
  the first digits of `l1` and `l2`:
  - `root = new ListNode((x + y + c) % 10)`.
  - Update `c = (x + y) / 10`.
- Maintain a pointer `temp` to track the tail of the resulting list.
- Traverse while either list has remaining nodes (`l1 != nullptr || l2 != nullptr`):
  - Extract current digit values `x` and `y` (defaulting to 0 if a list is exhausted).
  - Append a new node `temp->next` containing `(x + y + c) % 10`.
  - Update carry: `c = (x + y + c) / 10`.
  - Advance non-null input pointers and move `temp = temp->next`.
- Post-Loop Carry Handling:
  - If a non-zero carry remains (`c != 0`), append a final node `new ListNode(c)`.
- Return `root`.

Time Complexity  : O(max(N, M)) where N and M are the lengths of l1 and l2
Space Complexity : O(max(N, M)) auxiliary space allocated for the output linked list
============================================================
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int x = (l1 == nullptr) ? 0 : l1->val;
        int y = (l2 == nullptr) ? 0 : l2->val;
        int c = 0;
        ListNode* root = new ListNode((x + y + c) % 10);
        c = (x + y) / 10;
        l1 = (l1 != nullptr) ? l1->next : l1;
        l2 = (l2 != nullptr) ? l2->next : l2;
        ListNode* temp = root;

        while (l1 != nullptr || l2 != nullptr) {
            int x = (l1 == nullptr) ? 0 : l1->val;
            int y = (l2 == nullptr) ? 0 : l2->val;
            temp->next = new ListNode((x + y + c) % 10);
            c = (x + y + c) / 10;
            l1 = (l1 != nullptr) ? l1->next : l1;
            l2 = (l2 != nullptr) ? l2->next : l2;
            temp = temp->next;
        }

        if (c == 0) {
            temp->next = nullptr;
        } else {
            temp->next = new ListNode(c);
        }

        return root;
    }
};