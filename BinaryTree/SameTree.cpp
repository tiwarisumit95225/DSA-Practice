/*
=========================================================
Problem: Same Tree (LeetCode 100)
Topic: Binary Tree, DFS, Recursion
Difficulty: Easy

Approach: Recursive DFS
1. If both nodes are nullptr, return true.
2. If exactly one node is nullptr, return false.
3. If the node values are different, return false.
4. Recursively compare the left subtrees.
5. Recursively compare the right subtrees.
6. Return true only if both subtrees are identical.

Time Complexity:
- O(n)

Space Complexity:
- O(h)
  (h = height of the tree due to recursion stack)
  - Best Case (Balanced Tree): O(log n)
  - Worst Case (Skewed Tree): O(n)

Key Insight:
- Two trees are identical only if:
  • Current node values are equal.
  • Left subtrees are identical.
  • Right subtrees are identical.
- This follows the Divide and Conquer recursion pattern.

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
public:
    bool issame(TreeNode* p, TreeNode* q) {
        if (p ==nullptr && q == nullptr) {
            return true;
        } 
        if ((p == nullptr) != (q == nullptr) ){
          return false;
        }
        if(p->val!=q->val){
            return false;
        }

        return issame(p->left, q->left) && issame(p->right, q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) { 
        return issame(p, q);
         }
};