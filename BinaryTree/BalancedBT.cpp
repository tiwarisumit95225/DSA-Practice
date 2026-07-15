/*
=========================================================
Problem: Balanced Binary Tree (LeetCode 110)
Topic: Binary Tree, DFS, Recursion
Difficulty: Easy

Approach 1: Naive Recursive DFS
1. Compute the height of the left subtree.
2. Compute the height of the right subtree.
3. If the height difference is greater than 1,
   return false.
4. Recursively check whether the left and right
   subtrees are balanced.
5. Return true only if both subtrees are balanced.

Time Complexity:
- O(n²)
  (Height is recomputed for every node.)

Space Complexity:
- O(h)
  (h = height of the tree due to recursion stack)
  - Best Case (Balanced Tree): O(log n)
  - Worst Case (Skewed Tree): O(n)

Key Insight:
- This approach separately computes subtree heights
  for every node.
- Although simple to understand, it repeatedly
  recalculates heights, making it inefficient for
  large trees.

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

class Solution
{
public:
    int maxdepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = maxdepth(root->left);
        int right = maxdepth(root->right);
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        int leftheight = maxdepth(root->left);
        int rightheight = maxdepth(root->right);
        if (abs(leftheight - rightheight) > 1)
        {
            return false;
        }
        else
        {
            return isBalanced(root->left) && isBalanced(root->right);
        }
    }
};

/*
=========================================================
Problem: Balanced Binary Tree (LeetCode 110)
Topic: Binary Tree, DFS, Recursion
Difficulty: Easy

Approach 2: Optimized Recursive DFS
1. Compute the height of each subtree recursively.
2. If either subtree is already unbalanced,
   immediately return -1.
3. If the current node's left and right subtree
   heights differ by more than 1, return -1.
4. Otherwise, return the height of the current
   subtree.
5. The tree is balanced if the final height is
   not -1.

Time Complexity:
- O(n)

Space Complexity:
- O(h)
  (h = height of the tree due to recursion stack)
  - Best Case (Balanced Tree): O(log n)
  - Worst Case (Skewed Tree): O(n)

Key Insight:
- A sentinel value (-1) is used to indicate that
  a subtree is already unbalanced.
- This combines height calculation and balance
  checking into a single DFS traversal.
- Every node is visited exactly once, eliminating
  repeated height calculations.

=========================================================
*/

class Solution
{
public:
    int height(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        if (left == -1 || right == -1)
        {
            return -1;
        }
        if (abs(left - right) > 1)
        {
            return -1;
        }
        else
        {
            return 1 + max(left, right);
        }
    }
    bool isBalanced(TreeNode *root) { return height(root) != -1; }
};