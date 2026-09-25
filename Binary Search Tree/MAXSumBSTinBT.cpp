#include <iostream>
#include <climits>
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
Problem: Maximum Sum BST in Binary Tree
LeetCode: 1373
Topic: Binary Tree / BST / Postorder Traversal / Tree DP
Difficulty: Hard

Approach:
- The main challenge is to find the BST with the maximum
  sum anywhere inside the given binary tree.
- The entire tree does NOT necessarily have to be a BST.
- Therefore, we process every subtree using postorder
  traversal.

- For every subtree, we need four pieces of information:

    1. isBST
       → Whether the current subtree is a valid BST.

    2. sum
       → Sum of all nodes in the current subtree.

    3. maxValue
       → Maximum value present in the current subtree.

    4. minValue
       → Minimum value present in the current subtree.

- These values are stored inside the 'info' structure.

Postorder Traversal:
- First solve the left subtree.
- Then solve the right subtree.
- Then use both results to determine whether the current
  subtree is a BST.

BST Condition:
- Left subtree must be a BST.
- Right subtree must be a BST.
- Maximum value in the left subtree must be smaller than
  the current node.
- Minimum value in the right subtree must be greater than
  the current node.

    left.maxValue < root->val < right.minValue

If the current subtree is a BST:
- Calculate its sum:

    currsum = left.sum + root->val + right.sum

- Update the global maximum sum.
- Calculate the minimum and maximum values of the current
  subtree.
- Return all this information to the parent.

Base Case:
- An empty subtree is considered a valid BST.
- Its sum is 0.
- Its maximum value is INT_MIN.
- Its minimum value is INT_MAX.

    {true, 0, INT_MIN, INT_MAX}

Why INT_MIN and INT_MAX?
- They allow a leaf node to satisfy:

    INT_MIN < root->val < INT_MAX

Example:

        5
       / \
      3   7

For node 5:
- Left subtree → BST, sum = 3, max = 3
- Right subtree → BST, sum = 7, min = 7

Therefore:

    3 < 5 < 7

Current BST sum:

    3 + 5 + 7 = 15

Time Complexity:
- O(n)
- Every node is processed exactly once.

Space Complexity:
- O(h)
- h = height of the binary tree.
- This is the recursion stack.
- No additional array, vector, or hashmap is required.

Key Insight:
- This problem uses Bottom-Up Tree DP.
- Instead of repeatedly checking every subtree separately,
  each subtree calculates its information once and passes
  it to its parent.

Important Pattern:
    solve(left)
         ↓
    solve(right)
         ↓
    combine left + root + right
         ↓
    return information to parent

=========================================================
*/

class Solution {
    int maxSum = 0;

public:

    struct info {
        bool isBST;
        int sum;
        int maxValue;
        int minValue;
    };

    info solve(TreeNode* root) {

        // Empty subtree is a valid BST
        if (root == nullptr) {
            return {true, 0, INT_MIN, INT_MAX};
        }

        // Get information from left and right subtrees
        info left = solve(root->left);
        info right = solve(root->right);

        // Check whether the current subtree is a BST
        if (left.isBST &&
            right.isBST &&
            left.maxValue < root->val &&
            right.minValue > root->val) {

            // Calculate sum of current BST
            int currsum = left.sum + root->val + right.sum;

            // Update maximum BST sum found so far
            maxSum = max(maxSum, currsum);

            // Find minimum and maximum values
            // of the current BST
            int minValue = min(left.minValue, root->val);
            int maxValue = max(right.maxValue, root->val);

            // Return information about current subtree
            return {true, currsum, maxValue, minValue};
        }

        // Current subtree is not a BST
        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};