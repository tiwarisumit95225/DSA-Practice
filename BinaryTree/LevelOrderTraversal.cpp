/*
=========================================================
Problem: Binary Tree Level Order Traversal (LeetCode 102)
Topic: Binary Tree, BFS, Queue
Difficulty: Medium

Approach: Breadth-First Search (BFS)
1. If the tree is empty, return an empty answer.
2. Push the root node into a queue.
3. While the queue is not empty:
   - Store the current queue size (number of nodes at
     the current level).
   - Process exactly those nodes.
   - Store their values in a temporary vector.
   - Push their left and right children into the queue
     if they exist.
4. Add the current level to the final answer.
5. Return the level-order traversal.

Time Complexity:
- O(n)

Space Complexity:
- O(w)
  (w = maximum width of the tree)

Key Insight:
- A queue processes nodes in FIFO order, making it
  ideal for level-by-level traversal.
- The queue size before processing a level determines
  how many nodes belong to that level.

=========================================================
*/
#include <iostream>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        if (root != nullptr)
        {
            q.push(root);
        }
        while (!q.empty())
        {
            int s = q.size();
            vector<int> level;
            for (int i = 0; i < s; i++)
            {
                TreeNode *node = q.front();
                level.push_back(node->val);
                q.pop();
                if (node->left != nullptr)
                    q.push(node->left);

                if (node->right != nullptr)
                    q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
