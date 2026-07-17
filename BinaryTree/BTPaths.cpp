/*
=========================================================
Problem: Binary Tree Paths (LeetCode 257)
Topic: Binary Tree, DFS, Recursion, String Manipulation
Difficulty: Easy

Approach: Recursive Depth-First Search (DFS)
1. Start DFS from the root with an empty path string.
2. Append the current node's value to the path.
3. If the current node is a leaf node
   (both left and right children are null),
   store the complete path in the answer.
4. Otherwise, append "->" and recursively
   traverse the left and right subtrees.
5. Return all root-to-leaf paths.

Time Complexity:
- O(n)
  (Each node is visited exactly once)

Space Complexity:
- O(h)
  (h = height of the tree due to recursion stack)
  - Best Case (Balanced Tree): O(log n)
  - Worst Case (Skewed Tree): O(n)

Output Space:
- O(k)
  (k = total length of all root-to-leaf path strings)

Key Insight:
- Pass the current path as a string during recursion.
- Since the path string is passed by value, each recursive
  call gets its own copy, eliminating the need for
  explicit backtracking.
- Record the path only when a leaf node is reached.

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
    vector<string> ans;
    void findpath(TreeNode *root, string currpath)
    {
        if (root == nullptr)
        {
            return;
        }
        currpath += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(currpath);
        }
        else
        {
            currpath += "->";
        }
        findpath(root->left, currpath);
        findpath(root->right, currpath);
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        string currpath = "";
        findpath(root, currpath);
        return ans;
    }
};