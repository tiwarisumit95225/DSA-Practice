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
Problem: Trim a Binary Search Tree (LeetCode 669)
Topic: Binary Search Tree, Recursion, DFS
Difficulty: Medium

Approach: Recursive BST Pruning
1. Traverse the BST recursively.
2. If the current node's value is smaller than low,
   the current node and its entire left subtree are
   invalid because all values in the left subtree are
   even smaller.
3. Therefore, discard the current node and left subtree
   and continue trimming the right subtree.
4. If the current node's value is greater than high,
   the current node and its entire right subtree are
   invalid because all values in the right subtree are
   even greater.
5. Therefore, discard the current node and right subtree
   and continue trimming the left subtree.
6. If the current node is within [low, high], keep it and
   recursively trim both its left and right subtrees.
7. Return the root of the trimmed subtree.
8. If the root is nullptr, return nullptr.

Time Complexity:
- O(n) worst case
  (Each node may be visited once.)

Space Complexity:
- O(h)
  (h = height of the BST due to recursion stack.)
  - Balanced BST: O(log n)
  - Skewed BST: O(n)

Key Insight:
- The BST property allows us to discard entire subtrees
  without visiting every node in them.
- If root->val < low:
      discard root + left subtree
      continue with right subtree
- If root->val > high:
      discard root + right subtree
      continue with left subtree
- Otherwise, keep the current node and trim both sides.

Example:

        3
       / \
      0   4
       \
        2
       /
      1

low = 1
high = 3

Trimmed Tree:

        3
       /
      2
     /
    1

Optimization:
- No additional data structure is required.
- The BST property is directly used to skip invalid
  subtrees.
- The solution is already optimal in time complexity
  for the general case: O(n).
- Auxiliary space is O(h) because of recursion.

=========================================================
*/

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val < low) {
            return trimBST(root->right, low, high);
        }

        if (root->val > high) {
            return trimBST(root->left, low, high);
        }

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};