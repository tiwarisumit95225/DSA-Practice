/*
=========================================================
Problem: Find Bottom Left Tree Value (LeetCode 513)
Topic: Binary Tree, DFS, Recursion
Difficulty: Medium

Approach:
1. Perform DFS while keeping track of the current depth.
2. Maintain two variables:
   - maxDepth: deepest level visited so far.
   - ans: leftmost value at the deepest level.
3. Whenever a node is visited for the first time at a deeper level,
   update maxDepth and ans.
4. Always traverse the left subtree before the right subtree.
5. Return the recorded answer after DFS completes.

Time Complexity:
- O(n)
  (Each node is visited exactly once)

Space Complexity:
- O(h)
  (h = height of the tree due to recursion stack)

Key Insight:
- Visiting the left subtree first guarantees that the first node
  encountered at every depth is the leftmost node.
- Updating the answer only when reaching a new maximum depth
  ensures the correct bottom-left value is stored.

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

class Solution {
public:
    int maxdepth = -1;
    int ans = 0;
    void dfs(TreeNode* root, int depth) {
        if (root == nullptr) {
            return;
        }
        if (depth > maxdepth) {
            maxdepth = depth;
            ans = root->val;
        }
          dfs(root->left,depth+1);
          dfs(root->right,depth+1);
        return ;
    }
    int findBottomLeftValue(TreeNode* root) {
         dfs(root,0);
         return ans;
    }
};