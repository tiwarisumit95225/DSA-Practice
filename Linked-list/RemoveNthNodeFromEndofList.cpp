// Problem: Remove Nth Node From End of List
// Topic: Linked List
// Difficulty: Medium
// Pattern: Length Calculation + Node Deletion
// Time Complexity: O(n)
// Space Complexity: O(1)
// Key Learning:
// First calculate the length of the linked list.
// Convert the nth node from the end into a position from the beginning.
// Handle head deletion separately and then remove the target node.
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head;
        int len = 0;

        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }

        if (len == n)
        {
            ListNode *del = head;
            head = head->next;
            delete del;
            return head;
        }

        ListNode *nodeToDelete = head;
        ListNode *prev = head;

        for (int i = 0; i < len - n; i++)
        {
            nodeToDelete = nodeToDelete->next;
        }

        for (int i = 0; i < len - n - 1; i++)
        {
            prev = prev->next;
        }

        prev->next = nodeToDelete->next;
        delete nodeToDelete;

        return head;
    }
};

// Problem: Remove Nth Node From End of List
// Topic: Linked List, Two Pointers
// Difficulty: Medium
// Pattern: Fast & Slow Pointer
// Time Complexity: O(n)
// Space Complexity: O(1)
// Key Learning:
// Move the fast pointer n nodes ahead.
// Then move both pointers together.
// When fast reaches the last node, slow will be just before
// the node that needs to be removed.

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        if (fast == NULL)
        {
            ListNode *del = head;
            head = head->next;
            delete del;
            return head;
        }

        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *del = slow->next;
        slow->next = slow->next->next;
        delete del;

        return head;
    }
};