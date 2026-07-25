/*
=========================================================
Problem: 124. Binary Tree Maximum Path Sum
Topic: Binary Tree, DFS, Tree DP
Difficulty: Hard

Approach:
- Use DFS to calculate the maximum gain from each node.
- Recursively compute the maximum gain from the left and right subtrees.
- Ignore negative gains by replacing them with 0.
- At each node, calculate the maximum path passing through it:
      leftGain + node->val + rightGain
- Update the global answer if this path is larger.
- Return to the parent only the maximum single-branch gain:
      node->val + max(leftGain, rightGain)

Time Complexity:
O(n)

Space Complexity:
O(h)
where h is the height of the tree.

Key Insight:
Each node has two responsibilities:
1. Update the global answer using both left and right gains.
2. Return only one branch to its parent, since a valid path cannot split upward.

=========================================================
*/
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

class Solution {
public:
    int ans = INT_MIN;
    int maxGain(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftgain = maxGain(root->left);
        int rightgain = maxGain(root->right);
        leftgain = max(0, leftgain);
        rightgain = max(0, rightgain);
        int currpath = leftgain + rightgain + root->val;
        ans = max(ans, currpath);
        return root->val + max(leftgain, rightgain);
    }
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return ans;
    }
};