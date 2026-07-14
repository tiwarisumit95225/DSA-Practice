/*
=========================================================
Problem: Symmetric Tree (LeetCode 101)
Topic: Binary Tree, DFS, Recursion
Difficulty: Easy

Approach: Recursive DFS
1. If both nodes are nullptr, return true.
2. If exactly one node is nullptr, return false.
3. If node values are different, return false.
4. Recursively compare:
   - Left subtree of the left node with the right subtree of the right node.
   - Right subtree of the left node with the left subtree of the right node.
5. Return true only if both mirror comparisons are true.

Time Complexity:
- O(n)

Space Complexity:
- O(h)
  (h = height of the tree due to recursion stack)
  - Best Case (Balanced Tree): O(log n)
  - Worst Case (Skewed Tree): O(n)

Key Insight:
- A tree is symmetric if the left and right subtrees
  are mirror images of each other.
- Mirror comparison checks:
  Outside nodes (left->left vs right->right)
  Inside nodes (left->right vs right->left)

=========================================================
*/
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
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
    bool check(TreeNode *left, TreeNode *right)
    {
        if ((left == nullptr) && (right == nullptr))
        {
            return true;
        }
        if ((left != nullptr) != (right != nullptr))
        {
            return false;
        }

        if (left->val != right->val)
        {
            return false;
        }
        return check(left->left, right->right) &&
               check(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root) { return check(root->left, root->right); }
};

/*
=========================================================
Problem: Symmetric Tree (LeetCode 101)
Topic: Binary Tree, BFS, Queue
Difficulty: Easy

Approach: Iterative BFS using Queue
1. If the tree is empty, return true.
2. Store pairs of mirror nodes in a queue.
3. Pop one pair at a time and compare them:
   - If both nodes are nullptr, continue.
   - If exactly one node is nullptr, return false.
   - If node values are different, return false.
4. Push the mirror child pairs:
   - (left->left, right->right)
   - (left->right, right->left)
5. If all mirror pairs match, return true.

Time Complexity:
- O(n)

Space Complexity:
- O(w)
  (w = maximum width of the tree)

Key Insight:
- Instead of recursion, explicitly compare mirror node
  pairs using a queue.
- Each queue element stores two nodes that should be
  mirror images of each other.
- The algorithm performs a level-by-level mirror check
  using BFS.

=========================================================
*/
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        queue<pair<TreeNode *, TreeNode *>> q;
        if (root == nullptr)
            return true;

        q.push({root->left, root->right});

        while (!q.empty())
        {
            auto c = q.front();
            q.pop();
            if (c.first == nullptr && c.second == nullptr)
            {
                continue;
            }
            if ((c.first != nullptr) != (c.second != nullptr))
            {
                return false;
            }
            if (c.first->val != c.second->val)
            {
                return false;
            }
            q.push({c.first->left, c.second->right});
            q.push({c.first->right, c.second->left});
        }
        return true;
    }
};