/*
=========================================================
Problem: Implement Queue using Stacks (LeetCode 232)
Topic: Queue, Stack
Difficulty: Easy

Approach:
1. Use two stacks:
   - st1: Stores newly pushed elements.
   - st2: Stores elements in queue order.
2. Push every new element into st1.
3. Before pop() or peek():
   - If st2 is empty, move all elements from st1 to st2.
   - This reverses the order so the oldest element is on top.
4. Pop or peek from st2.
5. The queue is empty only when both stacks are empty.

Time Complexity:
- push(): O(1)
- pop(): Amortized O(1)
- peek(): Amortized O(1)
- empty(): O(1)

Space Complexity: O(n)

=========================================================
*/
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class MyQueue {
private:
    stack<int> st1;
    stack<int> st2;

public:
    MyQueue() {}

    void push(int x) { st1.push(x); }

    int pop() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int ans = st2.top();
        st2.pop();

        return ans;
    }

    int peek() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }

    bool empty() { return st1.empty() && st2.empty(); }
};

