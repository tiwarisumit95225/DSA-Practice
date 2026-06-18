// Problem: Majority Element
// Topic: Arrays
// Difficulty: Easy
// Pattern: Frequency Counting (Brute Force)
// Time Complexity: O(n²)
// Space Complexity: O(1)

#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int count = 0;

            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }

            if (count > nums.size() / 2) {
                return nums[i];
            }
        }

        return -1;
    }
};


// Problem: Majority Element
// Topic: Arrays
// Difficulty: Easy
// Pattern: Sorting
// Time Complexity: O(n log n)
// Space Complexity: O(1)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

// Problem: Majority Element
// Topic: Arrays
// Difficulty: Easy
// Pattern: Boyer-Moore Voting Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)
// Key Learning: Majority element survives all pairwise cancellations.

#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }

            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};