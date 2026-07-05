/*
=========================================================
Problem: Next Greater Element I (LeetCode 496)
Topic: Monotonic Stack + HashMap
Difficulty: Easy

Approach:
1. Traverse nums2 from right to left.
2. Maintain a monotonic decreasing stack.
3. Remove all elements from the stack that are smaller than the current element.
4. If the stack is empty, store -1 as the next greater element.
5. Otherwise, the stack top is the next greater element.
6. Store the mapping in an unordered_map.
7. Push the current element onto the stack.
8. Traverse nums1 and build the answer using the HashMap.

Time Complexity: O(n + m)
Space Complexity: O(n)

Key Concept:
- Monotonic Decreasing Stack
- HashMap stores the next greater element for every value in nums2.
=========================================================
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> store;
        vector<int> ans;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int curr = nums2[i];
            if (st.empty()) {
                st.push(curr);
                store[curr] = -1;
            } else {
                while (!st.empty() && st.top() < curr) {
                    st.pop();
                }
                if (!st.empty()) {
                    store[curr] = st.top();

                } else {
                    store[curr] = -1;
                }
                st.push(curr);
            }
        }

        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(store[nums1[i]]);
        }
        return ans;
    }
};


/*
=========================================================
Problem: Next Greater Element I (LeetCode 496)
Topic: Stack
Difficulty: Easy

Approach (Brute Force):
1. Traverse each element in nums1.
2. Find its position in nums2.
3. From that position, scan towards the right.
4. The first element greater than the current element is the answer.
5. If no greater element is found, store -1.

Time Complexity: O(n * m)
Space Complexity: O(1)

Key Concept:
For every element in nums1, linearly search its next greater
element in nums2.
=========================================================
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    bool found =false;
                    for (int k = j + 1; k < nums2.size(); k++) {
                        if (nums2[j] < nums2[k]) {
                            ans.push_back(nums2[k]);
                            found=true;
                            break;
                        }
                    }
                    if(!found){
                        ans.push_back(-1);
                    }
                    break;
                }
            }
        }

        return ans;
    }
};