/*
=========================================================
Problem: Online Stock Span (LeetCode 901)
Topic: Stack (Monotonic Stack)
Difficulty: Medium

Approach:
1. Maintain a monotonic decreasing stack storing
   (price, span) pairs.
2. Initialize the span of the current price as 1.
3. While the stack is not empty and the top price is
   less than or equal to the current price:
   - Add the top element's span to the current span.
   - Remove the top element from the stack.
4. Push the current (price, span) pair onto the stack.
5. Return the calculated span.

Time Complexity: O(n) Amortized
Space Complexity: O(n)

=========================================================
*/
#include <iostream>
#include <stack>
using namespace std;
class StockSpanner {
private:
    stack<pair<int, int>> st;

public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

