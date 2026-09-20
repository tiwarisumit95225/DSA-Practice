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
Problem: Delete Node in a BST (LeetCode 450)
Topic: Binary Search Tree, DFS, Recursion
Difficulty: Medium

Approach: Recursive BST Deletion using Inorder Successor
1. Search for the node containing the given key using
   the BST property.
2. If key is smaller than the current node, recursively
   search in the left subtree.
3. If key is greater than the current node, recursively
   search in the right subtree.
4. Once the node is found, handle three deletion cases.

Case 1: Node has no children
- Delete the node.
- Return nullptr to the parent.

Case 2: Node has one child
- Save the existing child.
- Delete the current node.
- Return the child so the parent can reconnect
  directly to it.

Case 3: Node has two children
- Find the inorder successor.
- The inorder successor is the smallest node in
  the right subtree.
- Copy the successor's value into the current node.
- Recursively delete the original successor node
  from the right subtree.

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
- The BST property allows us to search only one
  subtree at every step.
- When a node has two children, replacing it with
  its inorder successor preserves the BST property.

Inorder Successor:
- The smallest value in the right subtree.
- Find it by moving to the right child and then
  continuously moving left.

Example:

        5
       / \
      3   8
         / \
        6   9

Delete 5:

1. Node 5 has two children.
2. Right subtree starts at 8.
3. Smallest node in the right subtree is 6.
4. Replace 5's value with 6.
5. Delete the original node containing 6.

Result:

        6
       / \
      3   8
           \
            9

Optimization:
- Only the required search path is traversed.
- No additional tree or vector is created.
- The inorder successor is found by traversing
  only the left side of the right subtree.

=========================================================
*/

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root->val == key)
        {
            // Case 1: No children
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }

            // Case 2: Only left child
            else if (root->left != nullptr && root->right == nullptr)
            {
                TreeNode *child = root->left;
                delete root;
                return child;
            }

            // Case 2: Only right child
            else if (root->right != nullptr && root->left == nullptr)
            {
                TreeNode *child = root->right;
                delete root;
                return child;
            }

            // Case 3: Two children
            else
            {
                TreeNode *successor = root->right;

                while (successor->left != nullptr)
                {
                    successor = successor->left;
                }

                root->val = successor->val;

                root->right =
                    deleteNode(root->right, successor->val);
            }
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            root->left = deleteNode(root->left, key);
        }

        return root;
    }
};