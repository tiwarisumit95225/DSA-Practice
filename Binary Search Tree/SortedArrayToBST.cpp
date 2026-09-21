#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

/*
=========================================================
Problem: Convert Sorted Array to Binary Search Tree
         (LeetCode 108)
Topic: Binary Search Tree, Recursion, Divide and Conquer
Difficulty: Easy

Approach: Recursive Divide and Conquer
1. The given array is sorted in ascending order.
2. To create a height-balanced BST, choose the middle
   element of the current range as the root.
3. All elements to the left of the middle belong to the
   left subtree.
4. All elements to the right of the middle belong to the
   right subtree.
5. Recursively repeat the same process for the left and
   right halves.
6. If left becomes greater than right, there are no
   elements left, so return nullptr.
7. Connect the returned left and right subtree roots
   to the current node.
8. Return the newly created node.

Time Complexity:
- O(n)
  (Every element is used exactly once to create a node.)

Space Complexity:
- O(log n)
  (The recursion depth is the height of the balanced BST.)
  - Since the tree is height-balanced, h = O(log n).

Key Insight:
- Choosing the middle element as the root keeps the
  number of elements on both sides approximately equal.
- This produces a height-balanced BST.
- The array does not need to be physically split.
  We only pass left and right indices to represent
  each subarray.

Example:

Input:
    [-10, -3, 0, 5, 9]

Choose middle:
    0

Left half:
    [-10, -3]

Right half:
    [5, 9]

Result:

        0
       / \
     -3   9
     /   /
  -10   5

Optimization:
- No additional arrays are created.
- The original sorted array is reused using left and
  right indices.
- Using:
      left + (right - left) / 2
  avoids possible integer overflow compared to:
      (left + right) / 2

=========================================================
*/

class Solution
{
public:
    TreeNode *helper(vector<int> &nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        int mid = left + (right - left) / 2;

        TreeNode *newnode = new TreeNode(nums[mid]);

        newnode->left = helper(nums, left, mid - 1);
        newnode->right = helper(nums, mid + 1, right);

        return newnode;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }
};