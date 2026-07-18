/*
=========================================================
Problem: Path Sum II (LeetCode 113)
Topic: Binary Tree, DFS, Backtracking
Difficulty: Medium

Approach:
1. Start DFS from the root while maintaining the current path.
2. Subtract the current node's value from the remaining target sum.
3. Add the current node to the current path.
4. If the current node is a leaf and the remaining target becomes 0,
   store the current path in the answer.
5. Recursively explore the left and right subtrees.
6. Remove the current node from the path before returning
   (Backtracking).

Time Complexity:
- O(n)
  (Every node is visited exactly once)

Space Complexity:
- O(h)
  (h = height of the tree due to recursion stack and current path)

Key Insight:
- The current path is shared among recursive calls using a reference.
- Backtracking (pop_back()) restores the path after exploring each
  subtree, ensuring sibling subtrees start with the correct path.

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
    vector<vector<int>> ans;
    void findpath(TreeNode* root, int targetSum, vector<int>& path) {
        if (root == nullptr) {
            return ;
        }
        targetSum -= root->val;
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {

            if (targetSum == 0) {
                ans.push_back(path);
            }
                path.pop_back();
                return;
            
            
        }
        findpath(root->left, targetSum, path);
        findpath(root->right, targetSum, path);
        path.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        findpath(root, targetSum, path);
        return ans;
    }
};