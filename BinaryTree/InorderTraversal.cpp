/*
=========================================================
Problem: Binary Tree Inorder Traversal (LeetCode 94)
Topic: Binary Tree, DFS
Difficulty: Easy

Approach 1: Recursive DFS
1. Traverse the left subtree.
2. Visit the current node.
3. Traverse the right subtree.
4. Store each visited node in the answer vector.

Time Complexity:
- O(n)

Space Complexity:
- O(h)
  (h = height of the tree due to recursion stack)

Key Insight:
- Inorder traversal follows:
  Left → Root → Right
- Recursion automatically keeps track of parent nodes
  using the function call stack.

=========================================================
*/
#include <iostream>
#include <stack>
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
    vector<int> inorder;

public:
    void dfs(TreeNode* root) {

        if (root == NULL) {
            return;
        }
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
            return inorder;
    }

};


/*
=========================================================
Problem: Binary Tree Inorder Traversal (LeetCode 94)
Topic: Binary Tree, Stack
Difficulty: Easy

Approach 2: Iterative using Stack
1. Initialize an empty stack and set the current node
   to the root.
2. Continuously move to the left child while pushing
   each node onto the stack.
3. When no left child exists, pop the top node,
   visit it, and add its value to the answer.
4. Move to the popped node's right child.
5. Repeat until both the stack is empty and the current
   node becomes nullptr.

Time Complexity:
- O(n)

Space Complexity:
- O(h)
  (h = height of the tree due to stack)

Key Insight:
- The stack manually simulates the recursive call stack.
- Always travel as far left as possible before visiting
  a node.
- After visiting a node, continue with its right subtree.

=========================================================
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> inorder;
        TreeNode* curr = root;
        while (!st.empty() || curr != nullptr) {
            if (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            } else {
                curr = st.top();
                st.pop();
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
        return inorder;
    }
};