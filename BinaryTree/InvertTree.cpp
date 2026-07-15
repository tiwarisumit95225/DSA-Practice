/*
=========================================================
Problem: Invert Binary Tree (LeetCode 226)
Topic: Binary Tree, DFS, Recursion
Difficulty: Easy

Approach: Recursive DFS
1. If the current node is nullptr, return nullptr.
2. Swap the left and right child of the current node.
3. Recursively invert the left subtree.
4. Recursively invert the right subtree.
5. Return the current root after inversion.

Time Complexity:
- O(n)

Space Complexity:
- O(h)
  (h = height of the tree due to recursion stack)
  - Best Case (Balanced Tree): O(log n)
  - Worst Case (Skewed Tree): O(n)

Key Insight:
- Every node swaps its left and right children.
- The inversion is performed recursively for every
  subtree.
- The root of each subtree remains the same after
  inversion.

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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        swap(root->left, root->right);

        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};