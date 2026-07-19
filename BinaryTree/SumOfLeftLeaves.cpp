/*
=========================================================
Problem: Sum of Left Leaves (LeetCode 404)
Topic: Binary Tree, DFS, Recursion
Difficulty: Easy

Approach:
1. Traverse the binary tree using DFS.
2. At each node, check whether its left child exists and is a leaf.
3. If it is a left leaf, add its value to the answer.
4. Continue traversing both left and right subtrees.
5. Return the total sum of all left leaves.

Time Complexity:
- O(n)
  (Each node is visited exactly once)

Space Complexity:
- O(h)
  (h = height of the tree due to recursion stack)

Key Insight:
- A node cannot determine whether it is a left child.
- Instead, the parent checks whether its left child is a leaf and
  adds its value to the answer.

=========================================================
*/
#include <iostream>
#include <vector>
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
    int findsum(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int curr = 0;

        if (root->left != nullptr && root->left->left == nullptr &&
            root->left->right == nullptr)
        {
            curr = root->left->val;
        }

        int left = findsum(root->left);
        int right = findsum(root->right);

        return curr + left + right;
    }

    int sumOfLeftLeaves(TreeNode *root) { return findsum(root); }
};