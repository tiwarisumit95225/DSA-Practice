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
Problem: Lowest Common Ancestor of a Binary Search Tree
         (LeetCode 235)
Topic: Binary Search Tree, DFS, Recursion
Difficulty: Medium

Approach: Recursive BST Property
1. Start from the root of the BST.
2. If the current node is equal to either p or q,
   the current node is the Lowest Common Ancestor.
3. If both p and q are smaller than the current node,
   both nodes must exist in the left subtree.
4. If both p and q are greater than the current node,
   both nodes must exist in the right subtree.
5. If one node is smaller and the other is greater
   than the current node, they lie on different sides
   of the current node.
6. In that case, the current node is their Lowest
   Common Ancestor.
7. Return the result of the corresponding recursive
   call.

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
- The BST property allows us to eliminate an entire
  subtree at every step.
- If both nodes are smaller, move left.
- If both nodes are greater, move right.
- Otherwise, the current node is the LCA.

Example:

        6
       / \
      2   8
     / \ / \
    0  4 7  9
      / \
     3   5

For p = 2 and q = 8:

    2 < 6 < 8

Therefore, 6 is the Lowest Common Ancestor.

For p = 2 and q = 4:

    Both 2 and 4 are smaller than 6
        ↓
    Move to left subtree

    At node 2:
    2 == p

Therefore, 2 is the Lowest Common Ancestor.

Optimization:
- The BST property allows us to visit only one path
  instead of traversing the entire tree.
- No additional data structure is required.

=========================================================
*/

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root->val == p->val || root->val == q->val)
        {
            return root;
        }

        if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else
        {
            return root;
        }
    }
};