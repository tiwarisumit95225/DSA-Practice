/*
=========================================================
Problem: Count Complete Tree Nodes (LeetCode 222)
Topic: Binary Tree, Complete Binary Tree, DFS
Difficulty: Easy

Approach 1 (Recursive DFS):
1. Count nodes in the left subtree.
2. Count nodes in the right subtree.
3. Return 1 + left + right.

Time Complexity:
- O(n)

Space Complexity:
- O(h)

---------------------------------------------------------

Approach 2 (Optimized Complete Binary Tree):
1. Compute the leftmost and rightmost heights.
2. If both heights are equal, the tree is perfect.
3. Return (2^height - 1) directly.
4. Otherwise, recursively count nodes in both subtrees.

Time Complexity:
- O((log n)^2)

Space Complexity:
- O(log n)

Key Insight:
- In a perfect binary tree, the number of nodes is:
      2^height - 1
- A complete binary tree often contains large perfect subtrees.
- Instead of traversing every node, detect perfect subtrees using
  leftmost and rightmost heights and compute their node counts directly.

=========================================================
*/

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
class Solution {
public:
    int leftheight(TreeNode* root) {
        int h = 0;

        while (root) {
            h++;
            root = root->left;
        }

        return h;
    }
    int rightheight(TreeNode* root) {
        int h = 0;

        while (root) {
            h++;
            root = root->right;
        }

        return h;
    }
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int lh = leftheight(root);
        int rh = rightheight(root);
        if (rh == lh) {
            return (1 << rh) - 1;
        } else {
            int left = countNodes(root->left);
            int right = countNodes(root->right);
            return 1 + left + right;
        }
    }
};