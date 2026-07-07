/*
=========================================================
Problem: Largest Rectangle in Histogram (LeetCode 84)
Topic: Stack (Monotonic Stack)
Difficulty: Hard

Approach:
1. Find the Previous Smaller Element (PSE) for every bar
   using a monotonic increasing stack.
2. Find the Next Smaller Element (NSE) for every bar
   using another monotonic increasing stack.
3. For each bar:
   - Width = NSE - PSE - 1
   - Area = Height × Width
4. Return the maximum area among all bars.

Time Complexity: O(n)
Space Complexity: O(n)

=========================================================
*/
#include <iostream>
#include <stack>
#include<vector>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> leftboundary;
        vector<int> rightboundary(heights.size(), 0);
        stack<int> st;
        for (int i = 0; i < heights.size(); i++) {
            int height = heights[i];
            while (!st.empty() && heights[st.top()] >= height) {
                st.pop();
            }
            if (st.empty()) {
                leftboundary.push_back(-1);
            } else {
                leftboundary.push_back(st.top());
            }
            st.push(i);
        }

        while (!st.empty())
            st.pop();
        for (int i = heights.size() - 1; i >= 0; i--) {
            int height = heights[i];
            while (!st.empty() && heights[st.top()] >= height) {
                st.pop();
            }
            if (st.empty()) {
                rightboundary[i] = heights.size();
            } else {
                rightboundary[i] = st.top();
            }
            st.push(i);
        }
        int maxarea = 0;
        for (int i = 0; i < heights.size(); i++) {
            int height = heights[i];
            int left = leftboundary[i];
            int right = rightboundary[i];

            int width = right - left - 1;
            maxarea = max(maxarea, height * width);
        }
        return maxarea;
    }
};

/*
=========================================================
Problem: Largest Rectangle in Histogram (LeetCode 84)
Topic: Stack (Monotonic Stack)
Difficulty: Hard

Approach:
1. Traverse the histogram from left to right using a
   monotonic increasing stack storing indices.
2. While the current bar is smaller than the top of the
   stack (or a virtual bar of height 0 at the end),
   pop the stack and calculate the maximum rectangle
   using the popped bar as the height.
3. The current index acts as the Next Smaller Element,
   while the new stack top represents the Previous
   Smaller Element.
4. Compute:
      width = rightBoundary - leftBoundary - 1
      area = height × width
5. Push the current index onto the stack (except the
   virtual ending index).

Time Complexity: O(n)
Space Complexity: O(n)

=========================================================
*/ 

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {

            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {

                int height = heights[st.top()];

                st.pop();

                int right = i;
                int left;
                if (!st.empty()) {
                    left = st.top();
                } else {
                    left = -1;
                }

                int width = right - left - 1;

                maxArea = max(maxArea, height * width);
            }
            if (i < n) {
                st.push(i);
            }
        }

        return maxArea;
    }
};