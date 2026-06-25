/*
=========================================================
LeetCode 739. Daily Temperatures
Difficulty: Medium

Approach: Monotonic Decreasing Stack

Algorithm:
1. Create an answer array initialized with 0.
2. Use a stack to store indices of days whose
   next warmer temperature hasn't been found.
3. Traverse the temperature array:
   - While the current temperature is greater than
     the temperature at the index on top of the stack:
       • Pop the previous index.
       • Calculate the number of waiting days.
       • Store it in the answer array.
   - Push the current index onto the stack.
4. Return the answer array.

Time Complexity:
O(n)

Space Complexity:
O(n)

Key Learning:
- Learned the Monotonic Stack pattern.
- Store indices instead of values to calculate distances.
- Each element is pushed and popped at most once,
  resulting in an O(n) solution.

=========================================================
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> st;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int previdx = st.top();
                int val = i - previdx;
                ans[previdx] = val;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};