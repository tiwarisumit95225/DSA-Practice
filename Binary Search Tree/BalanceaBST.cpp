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

/*
=========================================================
Problem: Balance a Binary Search Tree (LeetCode 1382)
Topic: Binary Search Tree, Inorder Traversal, Recursion
Difficulty: Medium

Approach: Inorder Traversal + Balanced BST Construction
1. Perform an inorder traversal of the given BST.
2. Since the input is a BST, inorder traversal produces
 all node values in sorted ascending order.
3. Use the sorted values to construct a new height-balanced
 BST.
4. Choose the middle element of the current range as the
 root of the subtree.
5. Recursively use the left half to construct the left
 subtree.
6. Recursively use the right half to construct the right
 subtree.
7. If left becomes greater than right, there are no
 elements remaining, so return nullptr.
8. Return the newly constructed balanced BST.

Time Complexity:
- O(n)
- Inorder traversal visits every node once.
- Building the balanced BST uses every value once.
- Total: O(n)

Space Complexity:
- O(n)
(The inorder vector stores all n node values.)
- O(log n) recursion stack while constructing the
balanced BST.

Key Insight:
- A BST's inorder traversal is already sorted.
- A sorted array can be converted into a balanced BST by
repeatedly choosing the middle element as the root.
- Therefore, LeetCode 1382 can be solved by combining the
ideas from BST inorder traversal and LeetCode 108.

Example:

Input:

      1
       \
        2
         \
          3
           \
            4

Inorder:
  [1, 2, 3, 4]

Choose middle elements recursively:

      2
     / \
    1   3
         \
          4

Output:
  A height-balanced BST containing the same values.

Optimization:
- The original BST is not modified.
- No sorting operation is required because inorder
traversal already provides sorted values.
- The vector is passed by reference to avoid copying it
during recursive calls.
- Middle index is calculated as:
    left + (right - left) / 2
to avoid possible integer overflow.

=========================================================
*/

class Solution
{
    vector<int> inorder;

public:
    void sort(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        sort(root->left);
        inorder.push_back(root->val);
        sort(root->right);
    }

    TreeNode *BST(vector<int> &inorder, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        int mid = left + (right - left) / 2;

        TreeNode *root = new TreeNode(inorder[mid]);

        root->left = BST(inorder, left, mid - 1);
        root->right = BST(inorder, mid + 1, right);

        return root;
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        sort(root);

        return BST(inorder, 0, inorder.size() - 1);
    }
};