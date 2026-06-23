/*
Problem: Rotate List (LeetCode 61)
Topic: Linked List
Difficulty: Medium

Approach:
- Find the length of the list.
- Reduce k using modulo with length.
- Locate the new tail at position (len - k - 1).
- New head is newTail->next.
- Connect old tail to old head.
- Break the link after newTail.

Time Complexity: O(n)
Space Complexity: O(1)

Key Learning:
- Rotating a linked list can be done by changing links rather than moving nodes.
- k should always be reduced using k % length.
*/
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* temp = head;
        int len = 0;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }

        k = k % len;

        if (k == 0) {
            return head;
        }
        ListNode* p1 = head;
        ListNode* p2 = head;
        for (int i = 0; i < len - k - 1; i++) {
            p2 = p2->next;
        }
        ListNode* newhead = p2->next;
        for (int i = 0; i < len - 1; i++) {
            p1 = p1->next;
        }
        p2->next = NULL;
        p1->next = head;
        return newhead;
    }
};