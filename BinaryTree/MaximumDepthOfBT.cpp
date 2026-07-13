/*
=========================================================
Problem: Maximum Depth of Binary Tree (LeetCode 104)
Topic: Binary Tree, DFS, Recursion
Difficulty: Easy

Approach: Recursive DFS
1. If the current node is nullptr, return 0.
2. Recursively find the maximum depth of the left subtree.
3. Recursively find the maximum depth of the right subtree.
4. Return 1 + max(leftDepth, rightDepth) to include the
   current node in the depth.

Time Complexity:
- O(n)

Space Complexity:
- O(h)
  (h = height of the tree due to recursion stack)
  - Best Case (Balanced Tree): O(log n)
  - Worst Case (Skewed Tree): O(n)

Key Insight:
- Each recursive call returns the maximum depth of the
  subtree rooted at the current node.
- The current node combines the depths of its left and
  right subtrees by taking the maximum and adding one.
- This follows the Bottom-Up DFS approach, where child
  nodes compute their answers before the parent node.

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

class Solution {
public:
    int depth(TreeNode*root){
        if(root==nullptr){
            return 0;
        }
        int left=depth(root->left);
        int right=depth(root->right);
        return 1+max(left,right);
    }
    int maxDepth(TreeNode* root) {
        return   depth(root);
    }
};