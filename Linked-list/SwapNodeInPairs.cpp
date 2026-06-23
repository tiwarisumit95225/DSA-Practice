/*
Problem: Swap Nodes in Pairs (LeetCode 24)
Topic: Linked List
Difficulty: Medium

Approach:
- Use a dummy node to simplify edge cases.
- Maintain prev, first, and second pointers.
- Swap nodes pairwise by changing links.
- Move pointers to the next pair after each swap.

Time Complexity: O(n)
Space Complexity: O(1)

Key Learning:
- Dummy nodes simplify linked-list manipulations.
- Track the node before the pair (prev) to reconnect swapped pairs correctly.
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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *first = head;
        ListNode *second = head->next;
        while (first != NULL && second != NULL)
        {
            first->next = second->next;
            second->next = first;
            prev->next = second;
            prev = first;
            first = prev->next;
            if (first)
            {
                second = first->next;
            }
            else
            {
                second = NULL;
            }
        }
        return dummy->next;
    }
};

// recursive approach
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* first = head;
        ListNode* second = head->next;

        first->next = swapPairs(second->next);
        second->next = first;

        return second;
    }
};