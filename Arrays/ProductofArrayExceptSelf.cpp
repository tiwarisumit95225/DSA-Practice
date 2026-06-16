// Problem: Product of Array Except Self
// Topic: Arrays, Prefix Product, Suffix Product
// Difficulty: Medium
// Pattern: Prefix & Suffix Products
// Time Complexity: O(n)
// Space Complexity: O(1)  // Excluding the output array
// Key Learning:
// Instead of calculating the product for each index separately,
// store the prefix (left) product in the answer array and use a
// single variable to maintain the suffix (right) product while
// traversing from right to left. This avoids using extra arrays.

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> ans(nums.size());

        ans[0] = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int rightProduct = 1;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            ans[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return ans;
    }
};