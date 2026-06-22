// Problem: Odd Even Linked List
// Topic: Linked List
// Difficulty: Medium
// Pattern: Pointer Manipulation
// Time Complexity: O(n)
// Space Complexity: O(1)
// Key Learning:
// Separate odd-indexed and even-indexed nodes into two chains.
// Preserve relative order within both groups.
// Store the head of the even list and connect it to the end
// of the odd list after rearrangement.
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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenhead = head->next;
        while ((odd != NULL && odd->next != NULL) && (even != NULL && even->next != NULL))
        {
            ListNode *temp1 = odd;
            ListNode *temp2 = even;
            odd = odd->next->next;
            even = even->next->next;
            temp1->next = odd;

            temp2->next = even;
        }

        odd->next = evenhead;
        return head;
    }
};