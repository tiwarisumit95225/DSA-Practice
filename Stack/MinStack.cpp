#include <iostream>
#include <stack>
using namespace std;

/*
=========================================================
LeetCode 155. Min Stack
Difficulty: Medium

Approach 1: Two Stacks

Algorithm:
1. Maintain two stacks:
   - st     -> Stores all elements.
   - minSt  -> Stores the minimum element at every stage.
2. During push:
   - Push the value into st.
   - If minSt is empty or value <= current minimum,
     push it into minSt.
3. During pop:
   - If the top of st is equal to the top of minSt,
     pop from both stacks.
   - Otherwise, pop only from st.
4. top() returns st.top().
5. getMin() returns minSt.top().

Time Complexity:
push()    -> O(1)
pop()     -> O(1)
top()     -> O(1)
getMin()  -> O(1)

Space Complexity:
O(n)

Key Learning:
- Learned how to design a custom data structure.
- Used an auxiliary stack to maintain the minimum element.
- Achieved O(1) time for all operations.

=========================================================
*/

class MinStack {
private:
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {}

    void push(int value) {
        st.push(value);

        if (minSt.empty() || value <= minSt.top()) {
            minSt.push(value);
        }
    }

    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

/*
=========================================================
LeetCode 155. Min Stack
Difficulty: Medium

Approach 2: Single Stack using Pair

Algorithm:
1. Store a pair:
      (value, currentMinimum)
2. During push:
   - If stack is empty:
        push(value, value)
   - Otherwise:
        currentMin = min(value, previous minimum)
        push(value, currentMin)
3. pop() removes the top pair.
4. top() returns the value.
5. getMin() returns the stored minimum.

Time Complexity:
push()    -> O(1)
pop()     -> O(1)
top()     -> O(1)
getMin()  -> O(1)

Space Complexity:
O(n)

Key Learning:
- Each stack element stores both its value and the
  minimum value up to that point.
- Eliminates the need for a second stack.
- A cleaner and elegant implementation.

=========================================================
*/

class MinStack {
private:
    stack<pair<int, int>> st;

public:
    MinStack() {}

    void push(int value) {
        int currentMin = st.empty() ? value : min(value, st.top().second);
        st.push({value, currentMin});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};