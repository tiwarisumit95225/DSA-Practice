// Problem: Remove Linked List Elements
// Topic: Linked List
// Difficulty: Easy
// Pattern: Dummy Node Filtering
// Time Complexity: O(n)
// Space Complexity: O(1)
// Key Learning: Build a filtered linked list using a dummy node and keep only nodes whose value does not match the target.
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
    ListNode *removeElements(ListNode *head, int val)
    {

        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        ListNode *temp = head;

        while (temp != NULL)
        {

            if (temp->val != val)
            {
                tail->next = temp;
                tail = tail->next;
            }

            temp = temp->next;
        }

        tail->next = NULL;

        return dummy->next;
    }
};

// More Interview ready approach

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = dummy;

        while (curr->next != NULL) {

            if (curr->next->val == val) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};