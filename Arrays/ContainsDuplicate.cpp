// Problem: Contains Duplicate
// Topic: Arrays, Sorting
// Difficulty: Easy
// Pattern: Sort and Compare Adjacent Elements
// Time Complexity: O(n log n)
// Space Complexity: O(1)  // Ignoring the space used by the sorting algorithm
// Key Learning: After sorting, duplicate elements become adjacent and can be detected with a single traversal.

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] == nums[i])
            {
                return true;
            }
        }

        return false;
    }
};
