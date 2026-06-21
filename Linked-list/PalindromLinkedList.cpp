// Problem: Palindrome Linked List
// Topic: Linked List, Two Pointers
// Difficulty: Easy
// Pattern: Find Middle + Reverse Second Half
// Time Complexity: O(n)
// Space Complexity: O(1)
// Key Learning: Use slow/fast pointers to find the middle, reverse the second half in-place, and compare both halves node by node.
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = NULL;
        ListNode *curr = slow;

        while (curr != NULL)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        while (prev != NULL)
        {
            if (head->val != prev->val)
            {
                return false;
            }

            head = head->next;
            prev = prev->next;
        }

        return true;
    }
};