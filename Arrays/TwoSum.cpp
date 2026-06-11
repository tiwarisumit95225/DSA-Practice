// Problem: Two Sum
// Topic: Arrays
// Difficulty: Easy
// Pattern: Brute Force / Pair Search
// Time Complexity: O(n²)
// Space Complexity: O(1)
// Key Learning: Check every possible pair and return indices when their sum equals the target.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = 1;

        for (i = 0; i < nums.size(); i++) {
            for (j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {i, j};
    }
};