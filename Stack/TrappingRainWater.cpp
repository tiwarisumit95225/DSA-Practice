/*
=========================================================
Problem: Trapping Rain Water (LeetCode 42)
Topic: Arrays (Prefix & Suffix Maximum)
Difficulty: Hard

Approach:
1. Compute the maximum height to the left of every index.
2. Compute the maximum height to the right of every index.
3. Water trapped at each index is:
      min(leftMax, rightMax) - height[i]
4. Sum the trapped water for all indices.

Time Complexity: O(n)
Space Complexity: O(n)

=========================================================
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int water = 0;
        for (int i = 0; i < n; i++) {
            water += min(leftMax[i], rightMax[i]) - height[i];
        }

        return water;
    }
};

/*
=========================================================
Problem: Trapping Rain Water (LeetCode 42)
Topic: Stack (Monotonic Increasing Stack)
Difficulty: Hard

Approach:
1. Traverse the elevation map while maintaining a
   monotonic increasing stack of indices.
2. Whenever the current bar is taller than the stack top,
   pop the valley (bottom).
3. The current index becomes the right boundary and the
   new stack top becomes the left boundary.
4. Calculate:
      Water Height = min(leftWall, rightWall) - bottomHeight
      Width = right - left - 1
5. Add trapped water and continue until the stack
   maintains increasing heights.

Time Complexity: O(n)
Space Complexity: O(n)

=========================================================
*/

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int water = 0;
        for (int i = 0; i < height.size(); i++) {
            int ht = height[i];
            while (!st.empty() && height[st.top()] < ht) {
                int bottom = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                int left = st.top();
                int right = i;
                int waterHeight =
                    min(height[left], height[right]) - height[bottom];

                int width = right - left - 1;

                 water =water+ waterHeight * width;

            }
            st.push(i);
        }
        return water;
    }
};


/*
=========================================================
Problem: Trapping Rain Water (LeetCode 42)
Topic: Two Pointers
Difficulty: Hard

Approach:
1. Initialize two pointers at both ends of the array.
2. Maintain the maximum height seen from the left and
   right sides.
3. Always process the side with the smaller maximum
   height, since it determines the water level.
4. Update the corresponding maximum or accumulate
   trapped water.
5. Continue until both pointers meet.

Time Complexity: O(n)
Space Complexity: O(1)

=========================================================
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int water=0;
        int leftmax = height[left];
        int rightmax = height[right];
        while (left <= right) {
            if (leftmax < rightmax) {
                if (height[left] >= leftmax) {
                    leftmax = height[left];
                }

                else {
                    water += leftmax - height[left];
                }

                left++;
            } else {
                if (height[right] >= rightmax) {
                    rightmax = height[right];
                } else {
                    water += rightmax - height[right];
                }
                right--;
            }
        }
        return water;
    }
};