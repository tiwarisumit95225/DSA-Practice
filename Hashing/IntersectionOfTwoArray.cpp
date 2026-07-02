#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
/*
=========================================================
Problem: Intersection of Two Arrays (LeetCode 349)
Topic: HashSet (HashMap)
Difficulty: Easy

Approach:
1. Insert all elements of nums1 into an unordered_set.
2. Traverse nums2.
3. If an element exists in the set:
   - Add it to the answer.
   - Remove it from the set to avoid duplicates.
4. Return the answer.

Time Complexity: O(n + m)
Space Complexity: O(n)

Key Learning:
- unordered_set stores only unique elements.
- count() checks whether an element exists.
- erase() prevents duplicate values in the result.
=========================================================
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> common;
        vector<int> ans;
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);
        for (int a : nums1) {
            common.insert(a);
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (common.count(nums2[i])) {
                ans.push_back(nums2[i]);
                common.erase(nums2[i]);
            }
        }
        return ans;
    }
};