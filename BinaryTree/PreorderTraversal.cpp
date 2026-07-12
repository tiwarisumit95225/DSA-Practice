/*
=========================================================
Problem: Binary Tree Preorder Traversal (LeetCode 144)
Topic: Binary Tree, DFS
Difficulty: Easy

Approach 1: Recursive DFS
1. Visit the current node first.
2. Traverse the left subtree.
3. Traverse the right subtree.
4. Store each visited node in the answer vector.

Time Complexity:
- O(n)

Space Complexity:
- O(h)
  (h = height of the tree due to recursion stack)

Key Insight:
- Preorder traversal follows:
  Root → Left → Right
- Visit the node immediately before exploring its children.
- Recursion naturally keeps track of parent nodes using
  the function call stack.

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
    vector<int>preorder;
public:
void dfs(TreeNode*root){
    if(root==nullptr){
        return;
    }
    preorder.push_back(root->val);
    dfs(root->left);
    dfs(root->right);
}
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return preorder;
    }
};

/*
=========================================================
Problem: Binary Tree Preorder Traversal (LeetCode 144)
Topic: Binary Tree, Stack
Difficulty: Easy

Approach 2: Iterative using Stack
1. Initialize an empty stack and set the current node
   to the root.
2. Visit the current node and store its value.
3. Push the current node onto the stack.
4. Move to the left child.
5. When no left child exists, pop a node from the stack
   and move to its right child.
6. Repeat until both the current node becomes nullptr
   and the stack is empty.

Time Complexity:
- O(n)

Space Complexity:
- O(h)
  (h = height of the tree due to stack)

Key Insight:
- The stack simulates the recursive call stack.
- Unlike inorder traversal, the node is visited before
  moving to its left child.
- Every node is processed exactly once.

=========================================================
*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while (!st.empty() || curr != nullptr) {
            if (curr != nullptr) {
                preorder.push_back(curr->val);
                st.push(curr);
                curr = curr->left;
            } else {
                curr = st.top();
                st.pop();
                curr = curr->right;
            }
        }
        return preorder;
    }
};
