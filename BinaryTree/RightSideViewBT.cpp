/*
=========================================================
Problem: Binary Tree Right Side View (LeetCode 199)
Topic: Binary Tree, BFS, Queue
Difficulty: Medium

Approach: Breadth-First Search (BFS)
1. Perform a level-order traversal using a queue.
2. For each level, process all nodes currently in the queue.
3. The last node processed in each level represents the
   rightmost visible node.
4. Add its value to the answer.
5. Continue until all levels are processed.

Time Complexity:
- O(n)

Space Complexity:
- O(w)
  (w = maximum width of the tree)

Key Insight:
- In level-order traversal, the last node visited at each
  level is the node visible from the right side.
- No extra vector is needed to store the entire level;
  directly record the last node of each level.

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if (root != nullptr) {
            q.push(root);
        }
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (i == s - 1) {
                    ans.push_back(node->val);
                }
               
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};

/*
=========================================================
Problem: Binary Tree Right Side View (LeetCode 199)
Topic: Binary Tree, DFS, Recursion
Difficulty: Medium

Approach: Right-First Depth-First Search (DFS)
1. Traverse the tree recursively.
2. Visit the right child before the left child.
3. When visiting a level for the first time, store the
   node's value.
4. Continue recursively for both subtrees.

Time Complexity:
- O(n)

Space Complexity:
- O(h)
  (h = height of the tree)
  - Best Case (Balanced Tree): O(log n)
  - Worst Case (Skewed Tree): O(n)

Key Insight:
- Visiting the right subtree first ensures that the first
  node encountered at each depth is the one visible from
  the right side.

=========================================================
*/
class Solution {
public:
    void dfs(TreeNode* root, int level, vector<int>& ans) {
        if (root == nullptr)
            return;

        // First node visited at this level
        if (level == ans.size()) {
            ans.push_back(root->val);
        }

        // Visit right subtree first
        dfs(root->right, level + 1, ans);

        // Then visit left subtree
        dfs(root->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
};