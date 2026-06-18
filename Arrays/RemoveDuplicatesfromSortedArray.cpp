// Problem: Remove Duplicates from Sorted Array
// Topic: Arrays, Two Pointers
// Difficulty: Easy
// Pattern: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)
// Key Learning: Use one pointer to track the last unique element and another to scan the array.

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;

        while (j < nums.size()) {
            if (nums[j] != nums[i]) {
                nums[i + 1] = nums[j];
                i++;
            }
            j++;
        }

        return i + 1;
    }
};