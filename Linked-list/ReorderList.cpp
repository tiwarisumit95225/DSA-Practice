/*
Problem: Reorder List (LeetCode 143)
Topic: Linked List
Difficulty: Medium

Approach:
1. Find the middle of the linked list.
2. Split the list into two halves.
3. Reverse the second half.
4. Merge both halves alternately:
   L0 → Ln → L1 → Ln-1 → ...

Time Complexity: O(n)
Space Complexity: O(1)

Key Learning:
- Combine multiple linked list patterns:
  • Finding the middle node
  • Reversing a linked list
  • Merging two lists alternately
- Splitting the list before reversing prevents pointer conflicts.
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
    void reorderList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        int len = 0;
        ListNode *temp = head;

        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }

        ListNode *mid = head;
        for (int i = 1; i < len / 2; i++)
        {
            mid = mid->next;
        }

        ListNode *prev = NULL;
        ListNode *curr = mid->next;

        mid->next = NULL;

        while (curr != NULL)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode *first = head;
        ListNode *second = prev;

        while (second != NULL)
        {
            ListNode *next1 = first->next;
            ListNode *next2 = second->next;

            first->next = second;
            second->next = next1;

            first = next1;
            second = next2;
        }
    }
};