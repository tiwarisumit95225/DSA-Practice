// Problem: Merge Two Sorted Lists
// Topic: Linked List
// Difficulty: Easy
// Pattern: Dummy Node + Two Pointers
// Time Complexity: O(n + m)
// Space Complexity: O(1)
// Key Learning: A dummy node simplifies linked list construction and avoids special handling for the head node.
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;

        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val <= list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1 != NULL)
        {
            tail->next = list1;
        }
        else
        {
            tail->next = list2;
        }

        return dummy->next;
    }
};