/*
=========================================================
Problem: Lowest Common Ancestor of a Binary Tree (LeetCode 236)
Topic: Binary Tree, DFS, Recursion
Difficulty: Medium

Approach: Recursive DFS
1. If the current node is null, return nullptr.
2. If the current node is either p or q,
   return the current node.
3. Recursively search the left and right subtrees.
4. If both recursive calls return non-null pointers,
   the current node is the Lowest Common Ancestor.
5. If only one subtree returns a non-null pointer,
   propagate that node upward.
6. Return the final Lowest Common Ancestor.

Time Complexity:
- O(n)
  (Each node is visited exactly once)

Space Complexity:
- O(h)
  (h = height of the tree due to recursion stack)
  - Best Case (Balanced Tree): O(log n)
  - Worst Case (Skewed Tree): O(n)

Key Insight:
- Each recursive call returns one of three things:
  1. nullptr (neither target found)
  2. Pointer to p or q (or their LCA) found in one subtree
  3. Current root if both targets are found in different
     subtrees.
- The answer is built while recursion unwinds from the
  leaves back to the root.

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr) {
            return right;
        } else if (right == nullptr) {
            return left;
        } else {
            return root;
        }
        
    }
};
