#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Problem: Reverse Linked List
// Topic: Linked List
// Difficulty: Easy
// Pattern: Iterative Pointer Manipulation
// Time Complexity: O(n)
// Space Complexity: O(1)
// Key Learning:
// Use three pointers (prev, curr, next) to reverse links one by one
// while traversing the list. The prev pointer becomes the new head.

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {

            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }
};

// Problem: Reverse Linked List
// Topic: Linked List, Recursion
// Difficulty: Easy
// Pattern: Recursive Pointer Reversal
// Time Complexity: O(n)
// Space Complexity: O(n)
// Key Learning:
// Recursively reverse the remaining list, then reverse the current link
// using head->next->next = head and break the old connection with
// head->next = NULL.

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* newHead = reverseList(head->next);

        head->next->next = head;
        head->next = NULL;

        return newHead;
    }
};