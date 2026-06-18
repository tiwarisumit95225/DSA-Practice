// Problem: Maximum Subarray
// Topic: Arrays
// Difficulty: Medium
// Pattern: Brute Force
// Time Complexity: O(n³)
// Space Complexity: O(1)
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                int cursum = 0;

                for (int k = i; k <= j; k++) {
                    cursum += nums[k];
                }

                maxsum = max(maxsum, cursum);
            }
        }

        return maxsum;
    }
};

// Problem: Maximum Subarray
// Topic: Arrays
// Difficulty: Medium
// Pattern: Running Sum
// Time Complexity: O(n²)
// Space Complexity: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            int cursum = 0;

            for (int j = i; j < nums.size(); j++) {
                cursum += nums[j];
                maxsum = max(maxsum, cursum);
            }
        }

        return maxsum;
    }
};

// Problem: Maximum Subarray
// Topic: Arrays
// Difficulty: Medium
// Pattern: Kadane's Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)
// Key Learning: If the current sum becomes negative, discard it and start a new subarray.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int cursum = 0;

        for (int i = 0; i < nums.size(); i++) {
            cursum += nums[i];
            maxsum = max(maxsum, cursum);

            if (cursum < 0) {
                cursum = 0;
            }
        }

        return maxsum;
    }
};