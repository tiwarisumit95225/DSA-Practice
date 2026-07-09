/*
=========================================================
Problem: Implement Stack using Queues (LeetCode 225)
Topic: Queue
Difficulty: Easy

Approach:
1. Use a single queue to simulate stack behavior.
2. Push the new element into the queue.
3. Rotate the previous elements to the back of the queue.
4. After rotation, the newly inserted element becomes the front.
5. Pop and top operations are performed directly from the front.

Time Complexity:
- push(): O(n)
- pop(): O(1)
- top(): O(1)
- empty(): O(1)

Space Complexity: O(n)

=========================================================
*/
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}

    void push(int x) {
        q.push(x);
        int n = q.size();
        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int ans = q.front();
        q.pop();
        return ans;
    }

    int top() { return q.front(); }

    bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */