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
Problem: Insert into a Binary Search Tree (LeetCode 701)
Topic: Binary Search Tree, DFS, Recursion
Difficulty: Medium

Approach: Recursive BST Insertion
1. Start from the root of the BST.
2. If the current node is nullptr, this is the
   correct position for the new value.
3. Create a new TreeNode with the given value and
   return it.
4. If val is greater than the current node's value,
   recursively insert val into the right subtree.
5. If val is smaller than the current node's value,
   recursively insert val into the left subtree.
6. Assign the returned subtree back to the appropriate
   left or right child.
7. Return the current root so that the complete tree
   structure is preserved.

Time Complexity:
- O(h)
  (h = height of the BST)
  - Balanced BST: O(log n)
  - Skewed BST: O(n)

Space Complexity:
- O(h)
  (Recursion stack)
  - Balanced BST: O(log n)
  - Skewed BST: O(n)

Key Insight:
- The BST property determines exactly where the new
  value must be inserted.
- Values smaller than the current node go to the
  left subtree.
- Values greater than the current node go to the
  right subtree.
- Once a nullptr position is reached, the new node
  is created there.

Important:
- The recursive result must be assigned back to
  root->left or root->right.
- The original root must be returned after insertion.

Optimization:
- The algorithm visits only one path from the root
  to the insertion position.
- No traversal of unrelated subtrees is required.

=========================================================
*/

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            TreeNode *newNode = new TreeNode(val);
            return newNode;
        }

        if (val > root->val)
        {
            root->right = insertIntoBST(root->right, val);
        }
        else
        {
            root->left = insertIntoBST(root->left, val);
        }

        return root;
    }
};