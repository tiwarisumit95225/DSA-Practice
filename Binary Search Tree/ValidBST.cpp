#include <iostream>
#include <climits>
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
Problem: Validate Binary Search Tree (LeetCode 98)
Topic: Binary Search Tree, DFS, Recursion
Difficulty: Medium

Approach: Recursive DFS with Valid Range
1. Each node in a BST must satisfy a valid range
   determined by its ancestors.
2. Initially, the root can contain any value, so its
   valid range is:
       (-infinity, +infinity)
3. For the left subtree, every value must be smaller
   than the current node's value.
4. For the right subtree, every value must be greater
   than the current node's value.
5. Pass the updated minimum and maximum boundaries
   recursively to the left and right subtrees.
6. If a node's value is outside its allowed range,
   the tree is not a valid BST.
7. An empty subtree is considered valid.
8. The tree is a valid BST only if every node satisfies
   its corresponding range.

Time Complexity:
- O(n)
  (Every node is visited exactly once.)

Space Complexity:
- O(h)
  (h = height of the tree due to recursion stack)
  - Balanced BST: O(log n)
  - Skewed Tree: O(n)

Key Insight:
- Checking only the immediate left and right children
  is not sufficient.
- Every node must satisfy the restrictions imposed by
  all of its ancestors.
- Therefore, each node is validated using a minimum
  and maximum allowed boundary.

Example:

        5
       / \
      3   8
     / \
    2   4

For node 5:
    -infinity < 5 < +infinity

For node 3:
    -infinity < 3 < 5

For node 8:
    5 < 8 < +infinity

For node 2:
    -infinity < 2 < 3

For node 4:
    3 < 4 < 5

All nodes satisfy their valid ranges,
therefore the tree is a valid BST.

Important:
- Use long long for min and max boundaries so that
  INT_MIN and INT_MAX node values are handled correctly.
- BST uses strict inequalities:
      min < node->val < max
- Duplicate values are not allowed in this problem.

=========================================================
*/

class Solution
{
public:
    bool isvalid(TreeNode *root, long long min, long long max)
    {
        if (root == nullptr)
        {
            return true;
        }

        if (root->val <= min || root->val >= max)
        {
            return false;
        }

        return isvalid(root->left, min, root->val) &&
               isvalid(root->right, root->val, max);
    }

    bool isValidBST(TreeNode *root)
    {
        return isvalid(root, LLONG_MIN, LLONG_MAX);
    }
};