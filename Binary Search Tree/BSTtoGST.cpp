#include <iostream>
using namespace std;
 struct TreeNode {
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
Problem: Binary Search Tree to Greater Sum Tree
         (LeetCode 1038)
Topic: Binary Search Tree, Reverse Inorder Traversal, DFS
Difficulty: Medium

Approach: Reverse Inorder Traversal
1. In a BST, normal inorder traversal gives values in
   ascending order:
       Left → Root → Right
2. For a Greater Sum Tree, we need to process values from
   largest to smallest.
3. Therefore, perform a reverse inorder traversal:
       Right → Root → Left
4. Maintain a running sum of all previously visited
   greater values.
5. When visiting a node:
       sum = sum + root->val
       root->val = sum
6. Continue recursively through the left subtree.
7. Since the tree is modified in-place, no additional
   tree or vector is required.
8. Return the modified root.

Time Complexity:
- O(n)
  (Every node is visited exactly once.)

Space Complexity:
- O(h)
  (h = height of the BST due to recursion stack.)
  - Balanced BST: O(log n)
  - Skewed BST: O(n)

Key Insight:
- Reverse inorder traversal of a BST visits nodes in
  descending order.
- Therefore, when processing a node, the running sum
  already contains the values greater than that node.
- Adding the current value to the running sum gives the
  required Greater Sum Tree value.

Example:

Original BST:

        4
       / \
      1   6
         / \
        5   7

Reverse Inorder:
    7 → 6 → 5 → 4 → 1

Running Sum:
    7 → 13 → 18 → 22 → 23

Greater Sum Tree:

        22
       /  \
     23    13
          /  \
         18   7

Optimization:
- No vector or additional data structure is required.
- The tree is modified directly in-place.
- Time complexity is O(n), which is optimal because
  every node must be processed.
- Auxiliary space is O(h), which is caused only by the
  recursion stack.

=========================================================
*/

class Solution {
    int sum = 0;

public:
    void reverseinorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        reverseinorder(root->right);

        sum = sum + root->val;
        root->val = sum;

        reverseinorder(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        reverseinorder(root);
        return root;
    }
};