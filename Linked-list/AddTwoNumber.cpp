// Problem: Add Two Numbers
// Topic: Linked List
// Difficulty: Medium
// Pattern: Linked List Simulation
// Time Complexity: O(max(n, m))
// Space Complexity: O(max(n, m))
// Key Learning:
// Traverse both linked lists simultaneously.
// Use a carry variable to handle sums greater than 9.
// Use a dummy node to simplify result list construction.
// Continue processing while either list has nodes or carry exists.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *s1 = l1;
        ListNode *s2 = l2;
        ListNode *newlist = new ListNode(0);
        ListNode *newnode = newlist;
        int carry = 0;
        while (s2 != NULL || s1 != NULL || carry)
        {

            int digit1 = (s1 != NULL) ? s1->val : 0;
            int digit2 = (s2 != NULL) ? s2->val : 0;
            int sum = digit1 + digit2 + carry;

            carry = sum / 10;
            sum = sum % 10;

            newnode->next = new ListNode(sum);
            if (s1 != NULL)
            {
                s1 = s1->next;
            }
            if (s2 != NULL)
            {
                s2 = s2->next;
            }

            newnode = newnode->next;
        }
        return newlist->next;
    }
};