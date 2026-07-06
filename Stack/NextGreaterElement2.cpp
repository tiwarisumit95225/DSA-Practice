/*
=========================================================
Problem: Next Greater Element II (LeetCode 503)
Topic: Stack (Monotonic Stack)
Difficulty: Medium

Approach:
1. Traverse the array from right to left twice (2 * n - 1 to 0)
   to simulate the circular nature of the array.
2. Use a monotonic decreasing stack to maintain possible
   next greater elements.
3. Remove all elements from the stack that are smaller than
   or equal to the current element, as they cannot be the
   next greater element.
4. During the second traversal (i < n), if the stack is not
   empty, the top element is the next greater element;
   otherwise, the answer is -1.
5. Push the current element onto the stack for future elements.

Time Complexity: O(n)
Space Complexity: O(n)

=========================================================
*/
#include <iostream>
#include <vector>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        stack<int> st;
        for (int i = 2 * nums.size() - 1; i >= 0; i--) {
            int curr = nums[i % nums.size()];

            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }
            if (i < nums.size()) {
                if (st.empty()) {
                    ans[i] = -1;
                } else {
                    ans[i] = st.top();
                }
            }
            st.push(curr);
        }

        return ans;
    }
};