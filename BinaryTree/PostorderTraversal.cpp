/*
=========================================================
Problem: Binary Tree Postorder Traversal (LeetCode 145)
Topic: Binary Tree, Stack
Difficulty: Easy

Approach 1: Recursive DFS
1. Traverse the left subtree.
2. Traverse the right subtree.
3. Visit the current node.
4. Store each visited node in the answer vector.

Time Complexity:
- O(n)

Space Complexity:
- O(h)
  (h = height of the tree due to recursion stack)

Key Insight:
- Postorder traversal follows:
  Left → Right → Root
- The current node is processed only after both
  subtrees have been completely traversed.

=========================================================
*/
#include <iostream>
#include <stack>
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
    vector<int>postorder;
public:
 void dfs(TreeNode*root){
    if(root==nullptr){
        return;
    }
    dfs(root->left);
    dfs(root->right);
    postorder.push_back(root->val);
 }
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return postorder;
    }
};


/*
=========================================================
Problem: Binary Tree Postorder Traversal (LeetCode 145)
Topic: Binary Tree, Stack
Difficulty: Easy

Approach 2: Iterative using Stack (Reverse Modified Preorder)
1. Push the root node into the stack.
2. Pop a node and store its value.
3. Push its left child followed by its right child.
4. Continue until the stack becomes empty.
5. Reverse the collected traversal to obtain
   postorder traversal.

Time Complexity:
- O(n)

Space Complexity:
- O(n)

Key Insight:
- Perform a modified preorder traversal:
  Root → Right → Left
- Reversing the result produces:
  Left → Right → Root (Postorder)

=========================================================
*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> postorder;
        TreeNode* node = root;
        if (root != nullptr) {
            st.push(node);
        }
        while (!st.empty()) {
            node = st.top();
            st.pop();
            postorder.push_back(node->val);
            if (node->left) {
                st.push(node->left);
            }
            if (node->right) {
                st.push(node->right);
            }
        }
        reverse(postorder.begin(), postorder.end());
        return postorder;
    }
};