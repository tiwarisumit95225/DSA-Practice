// Problem: Rotate Array
// Topic: Arrays
// Difficulty: Medium
// Pattern: Array Reversal
// Time Complexity: O(n)
// Space Complexity: O(1)
// Key Learning: Reverse whole array, then reverse first k elements, then reverse remaining elements.
#include <iostream>
#include <vector>
using namespace std;    


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int i = 0;
        int j = nums.size() - 1;
        int x = k;
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        int a = x - 1;
        int b = 0;
        while (b < a) {
            swap(nums[b], nums[a]);
            b++;
            a--;
        }
        int y = nums.size() - 1;
        while (k < y) {
            swap(nums[k], nums[y]);
            k++;
            y--;
        }
    }
};