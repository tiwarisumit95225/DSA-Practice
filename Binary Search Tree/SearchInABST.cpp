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
Problem: Search in a Binary Search Tree (LeetCode 700)
Topic: Binary Search Tree, DFS, Recursion
Difficulty: Easy

Approach: Recursive BST Search
1. If the root is nullptr, the value does not exist
   in the tree, so return nullptr.
2. If the current node's value is equal to val,
   return the current node.
3. If val is greater than the current node's value,
   search in the right subtree.
4. If val is smaller than the current node's value,
   search in the left subtree.
5. Return the result of the recursive call so that
   the found node is propagated back to the caller.

Time Complexity:
- O(h)
  (h = height of the BST)
  - Best/Average Case for Balanced BST: O(log n)
  - Worst Case for Skewed BST: O(n)

Space Complexity:
- O(h)
  (h = height of the tree due to recursion stack)
  - Balanced BST: O(log n)
  - Skewed BST: O(n)

Key Insight:
- A Binary Search Tree follows the property:
    Left subtree  < Root < Right subtree
- Therefore, at every node we can eliminate one
  entire subtree from consideration.
- Unlike a normal Binary Tree search, we do not need
  to visit every node.

Important:
- When the target value is found, return root directly.
- The recursive call must also be returned so that
  the result is not lost while returning from recursion.

=========================================================
*/

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        else if (root->val == val)
        {
            return root;
        }
        else if (val > root->val)
        {
            return searchBST(root->right, val);
        }

        return searchBST(root->left, val);
    }
};