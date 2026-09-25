#include <iostream>
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
Problem: Range Sum of BST
LeetCode: 938
Topic: Binary Search Tree / Recursion
Difficulty: Easy

Approach:
- Traverse the entire BST using recursion.
- For every node, check whether its value lies within
  the given range [low, high].
- If the value is within the range, add it to the sum.
- Recursively visit the left and right subtrees.
- The sum is maintained using a class-level variable.

Important:
- The range is inclusive.
- Therefore, a node is included when:

      root->val >= low && root->val <= high

Example:

        10
       /  \
      5    15
     / \     \
    3   7     18

low = 7
high = 15

Valid values:
7 + 10 + 15 = 32

Time Complexity:
- O(n)
- Every node may be visited once.

Space Complexity:
- O(h)
- h = height of the BST.
- This is the recursion stack.

Key Insight:
- Every node is checked against the given range.
- The BST property is not being used for pruning in this
  version.

Optimization:
- Since this is a BST, we can avoid traversing subtrees
  that cannot contain values inside [low, high].

=========================================================
*/

class Solution {
    int sum = 0;

public:

    int findSum(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return sum;
        }

        // Add current node if it lies inside [low, high]
        if (root->val >= low && root->val <= high) {
            sum += root->val;
        }

        // Traverse both subtrees
        findSum(root->left, low, high);
        findSum(root->right, low, high);

        return sum;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        return findSum(root, low, high);
    }
};

/*
=========================================================
Problem: Range Sum of BST
LeetCode: 938
Topic: Binary Search Tree / Recursion
Difficulty: Easy

Approach:
- Use the Binary Search Tree property to avoid visiting
  unnecessary subtrees.
- For every node, there are three possible cases:

  1. root->val < low
     - The current value is too small.
     - Because this is a BST, every value in the left
       subtree will also be smaller.
     - Therefore, skip the left subtree and only search
       the right subtree.

  2. root->val > high
     - The current value is too large.
     - Every value in the right subtree will also be larger.
     - Therefore, skip the right subtree and only search
       the left subtree.

  3. low <= root->val <= high
     - The current value is valid.
     - Add it to the sum.
     - Both left and right subtrees may contain valid values,
       so recursively calculate their sums.

Example:

        10
       /  \
      5    15
     / \     \
    3   7     18

low = 7
high = 15

Valid values:
7 + 10 + 15 = 32

Time Complexity:
- Worst Case: O(n)
- In the worst case, we may still need to visit every node.
- BST pruning can reduce the number of nodes visited when
  large portions of the tree are outside the given range.

Space Complexity:
- O(h)
- h = height of the BST.
- This is the maximum recursion stack depth.

Key Insight:
- The important part of this problem is using the BST
  property for pruning.
- We don't need to blindly traverse both subtrees.
- If a node is outside the range, one entire subtree can
  be safely ignored.

Why this is better than normal DFS:
- A normal binary-tree solution visits every node.
- This solution uses BST ordering to skip irrelevant
  subtrees.

=========================================================
*/

class Solution {
public:

    int findSum(TreeNode* root, int low, int high) {

        // Empty subtree contributes 0
        if (root == nullptr) {
            return 0;
        }

        // Current value is smaller than the range.
        // Left subtree will also contain smaller values,
        // so only search the right subtree.
        if (root->val < low) {
            return findSum(root->right, low, high);
        }

        // Current value is larger than the range.
        // Right subtree will also contain larger values,
        // so only search the left subtree.
        if (root->val > high) {
            return findSum(root->left, low, high);
        }

        // Current node lies inside [low, high].
        int sum = root->val;

        // Both subtrees may contain valid values.
        sum += findSum(root->left, low, high);
        sum += findSum(root->right, low, high);

        return sum;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        return findSum(root, low, high);
    }
};