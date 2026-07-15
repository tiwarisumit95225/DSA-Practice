/*
=========================================================
Problem: Path Sum (LeetCode 112)
Topic: Binary Tree, DFS, Recursion
Difficulty: Easy

Approach: Recursive DFS
1. If the current node is nullptr, return false.
2. Subtract the current node's value from the remaining target sum.
3. If the current node is a leaf:
   - Return true if the remaining sum becomes 0.
   - Otherwise, return false.
4. Recursively check the left and right subtrees.
5. Return true if either subtree contains a valid root-to-leaf path.

Time Complexity:
- O(n)

Space Complexity:
- O(h)
  (h = height of the tree due to recursion stack)
  - Best Case (Balanced Tree): O(log n)
  - Worst Case (Skewed Tree): O(n)

Key Insight:
- Instead of computing the total path sum, keep reducing the
  remaining target sum while moving from the root to a leaf.
- A valid path exists only if a leaf node makes the remaining
  sum equal to zero.

=========================================================
*/
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
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

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr) {
            targetSum -= root->val;
            return targetSum == 0;
        } else {
            targetSum -= root->val;
            return hasPathSum(root->left, targetSum) ||
                   hasPathSum(root->right, targetSum);
        }
    }
};
