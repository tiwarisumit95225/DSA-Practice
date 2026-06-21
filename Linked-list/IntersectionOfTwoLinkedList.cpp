// Problem: Intersection of Two Linked Lists
// Topic: Linked List
// Difficulty: Easy
// Pattern: Length Alignment
// Time Complexity: O(m + n)
// Space Complexity: O(1)
// Key Learning: Find lengths of both lists, move the pointer of the longer list ahead by the length difference, then move both pointers together until they meet.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        int m = 0, n = 0;

        ListNode *temp1 = headA;
        while (temp1 != NULL)
        {
            m++;
            temp1 = temp1->next;
        }

        ListNode *temp2 = headB;
        while (temp2 != NULL)
        {
            n++;
            temp2 = temp2->next;
        }

        ListNode *i = headA;
        ListNode *j = headB;

        if (m < n)
        {
            for (int k = 0; k < n - m; k++)
            {
                j = j->next;
            }
        }
        else
        {
            for (int k = 0; k < m - n; k++)
            {
                i = i->next;
            }
        }

        while (i != j)
        {
            i = i->next;
            j = j->next;
        }

        return i;
    }
};

// Problem: Intersection of Two Linked Lists
// Topic: Linked List, Two Pointers
// Difficulty: Easy
// Pattern: Pointer Switching
// Time Complexity: O(m + n)
// Space Complexity: O(1)
// Key Learning: When a pointer reaches the end of one list, redirect it to the head of the other list. Both pointers travel the same total distance and meet at the intersection node.

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        ListNode *pA = headA;
        ListNode *pB = headB;

        while (pA != pB)
        {
            pA = (pA == NULL) ? headB : pA->next;
            pB = (pB == NULL) ? headA : pB->next;
        }

        return pA;
    }
};