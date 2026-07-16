/*
=========================================================
Problem: Diameter of Binary Tree (LeetCode 543)
Topic: Binary Tree, DFS, Recursion
Difficulty: Easy

Approach: Optimized Recursive DFS
1. Recursively compute the height of the left and
   right subtrees.
2. At each node, calculate the diameter passing
   through it as:
      leftHeight + rightHeight
3. Update the global maximum diameter if the current
   diameter is larger.
4. Return the height of the current subtree as:
      1 + max(leftHeight, rightHeight)
5. After the DFS traversal, return the maximum
   diameter found.

Time Complexity:
- O(n)

Space Complexity:
- O(h)
  (h = height of the tree due to recursion stack)
  - Best Case (Balanced Tree): O(log n)
  - Worst Case (Skewed Tree): O(n)

Key Insight:
- Height and diameter are different.
- Height is returned to the parent.
- Diameter is updated as a side effect during DFS.
- The longest path through any node is:
      leftHeight + rightHeight
- Every node is visited exactly once.

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
    int diameter = 0;
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        diameter = max(diameter, left + right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};