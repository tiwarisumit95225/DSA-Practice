// Problem: Move Zeroes
// Topic: Arrays, Two Pointers
// Difficulty: Easy
// Pattern: Two Pointers (In-Place Rearrangement)
// Time Complexity: O(n)
// Space Complexity: O(1)
// Key Learning: Use one pointer to track the position of the next non-zero element and another pointer to scan the array. This allows moving all non-zero elements forward while maintaining their relative order.

#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int i = 0;

        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] != 0)
            {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};