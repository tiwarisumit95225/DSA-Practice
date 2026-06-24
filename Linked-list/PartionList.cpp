/*
Problem: Partition List (LeetCode 86)
Topic: Linked List
Difficulty: Medium

Approach:
- Maintain two separate chains:
  1. Nodes with values less than x
  2. Nodes with values greater than or equal to x
- Traverse the list once and append nodes to the appropriate chain.
- Connect the two chains at the end.

Time Complexity: O(n)
Space Complexity: O(1)

Key Learning:
- Dummy nodes simplify linked-list construction.
- Building multiple chains is often easier than inserting nodes in-place.
*/
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *lesshead = new ListNode(0);
        ListNode *greterhead = new ListNode(0);
        ListNode *lesstail = lesshead;
        ListNode *gretertail = greterhead;
        ListNode *curr = head;
        while (curr != NULL)
        {
            ListNode *nextnode = curr->next;
            curr->next = NULL;
            if (curr->val < x)
            {
                lesstail->next = curr;
                curr = nextnode;
                lesstail = lesstail->next;
            }
            else
            {
                gretertail->next = curr;
                curr = nextnode;
                gretertail = gretertail->next;
            }
        }
        gretertail->next = NULL;
        lesstail->next = greterhead->next;
        return lesshead->next;
    }
};