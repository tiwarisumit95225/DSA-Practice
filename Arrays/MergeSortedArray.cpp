// Problem: Merge Sorted Array
// Topic: Arrays, Sorting
// Difficulty: Easy
// Pattern: Copy and Sort
// Time Complexity: O((m+n) log(m+n))
// Space Complexity: O(1)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }

        sort(nums1.begin(), nums1.end());
    }
};
// Problem: Merge Sorted Array
// Topic: Arrays, Two Pointers
// Difficulty: Easy
// Pattern: Reverse Merge
// Time Complexity: O(m+n)
// Space Complexity: O(1)
// Key Learning: Fill nums1 from the back to avoid overwriting elements.

#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
};
