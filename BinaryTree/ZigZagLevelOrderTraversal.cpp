/*
=========================================================
Problem: Binary Tree Zigzag Level Order Traversal (LeetCode 103)
Topic: Binary Tree, BFS, Queue
Difficulty: Medium

Approach: Breadth-First Search (BFS)
1. Perform a normal level-order traversal using a queue.
2. Store all nodes of the current level.
3. Reverse the current level if the traversal direction
   is right-to-left.
4. Toggle the traversal direction after every level.
5. Return the zigzag level-order traversal.

Time Complexity:
- O(n)

Space Complexity:
- O(w)
  (w = maximum width of the tree)

Key Insight:
- Perform a standard BFS.
- Alternate the direction after every level.
- Reverse the current level whenever the traversal
  direction changes.

=========================================================
*/
#include <iostream>
#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root != nullptr) {
            q.push(root);
        }
        bool isleft = false;
        while (!q.empty()) {
            vector<int> level;
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* node = q.front();
                level.push_back(node->val);
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            if (isleft) {
                reverse(level.begin(), level.end());
                ans.push_back(level);
            } else {
                ans.push_back(level);
            }
            isleft = !isleft;
        }
        return ans;
    }
};
