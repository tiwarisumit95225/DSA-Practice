// Problem: Linked List Cycle
// Topic: Linked List, Two Pointers
// Difficulty: Easy
// Pattern: Floyd's Cycle Detection (Tortoise and Hare)
// Time Complexity: O(n)
// Space Complexity: O(1)
// Key Learning: When one pointer moves twice as fast as another, they will eventually meet if a cycle exists.
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
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};