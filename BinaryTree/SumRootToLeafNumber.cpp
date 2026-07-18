/*
=========================================================
Problem: Sum Root to Leaf Numbers (LeetCode 129)
Topic: Binary Tree, DFS, Recursion
Difficulty: Medium

Approach:
1. Traverse the tree using DFS.
2. Form the current number by:
      current = current * 10 + node->val
3. If a leaf node is reached, return the formed number.
4. Recursively compute the sum of numbers from the left and right
   subtrees.
5. Return the sum of both recursive calls.

Time Complexity:
- O(n)
  (Each node is visited exactly once)

Space Complexity:
- O(h)
  (h = height of the tree due to recursion stack)

Key Insight:
- Instead of storing the entire path, carry the number formed so far.
- Every root-to-leaf path contributes exactly one number to the final
  answer.

=========================================================
*/
#include <iostream>
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
    int findsum(TreeNode*root,int sum){
        if(root==nullptr){
            return 0;
        }
        sum=sum*10+root->val;
        if(root->left==nullptr && root->right==nullptr){
            return sum;
        }
        int left=findsum(root->left,sum);
        int right=findsum(root->right,sum);
        return left+right;
    }
    int sumNumbers(TreeNode* root) {
        return findsum(root,0);
    }
};