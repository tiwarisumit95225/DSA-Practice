#include <iostream>
#include <vector>
#include <climits>
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
Problem: Minimum Absolute Difference in BST (LeetCode 530)
Topic: Binary Search Tree, Inorder Traversal
Difficulty: Easy

Approach: Inorder Traversal + Sorted Array
1. Perform an inorder traversal of the BST.
2. Inorder traversal of a BST always gives the node
   values in sorted order.
3. Store all the inorder values in a vector.
4. Since the values are sorted, the minimum absolute
   difference can only occur between two adjacent values.
5. Traverse the vector and calculate the difference
   between inorder[i] and inorder[i - 1].
6. Keep track of the minimum difference.
7. Return the minimum difference.

Time Complexity:
- O(n)
  (Every node is visited once during inorder traversal
   and the resulting vector is traversed once.)

Space Complexity:
- O(n)
  (The inorder vector stores all n node values.)
- O(h) recursion stack
  (h = height of the BST)

Key Insight:
- Inorder traversal of a BST produces values in sorted
  order.
- Therefore, we only need to compare adjacent values
  to find the minimum absolute difference.
- There is no need to compare every pair of nodes.

Example:

        4
       / \
      2   6
     / \
    1   3

Inorder:
    1 2 3 4 6

Differences:
    2 - 1 = 1
    3 - 2 = 1
    4 - 3 = 1
    6 - 4 = 2

Answer:
    1

Optimization:
- The current solution stores the complete inorder
  traversal in a vector, resulting in O(n) extra space.
- We can optimize the space to O(h) by keeping only:
      1. Previous visited value
      2. Current minimum difference
- Time complexity remains O(n).

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

    int getMinimumDifference(TreeNode *root)
    {
        sort(root);

        int minimum = INT_MAX;
        int diff = 0;

        for (int i = 1; i < inorder.size(); i++)
        {
            diff = inorder[i] - inorder[i - 1];
            minimum = min(minimum, diff);
        }

        return minimum;
    }
};

/*
=========================================================
Problem: Minimum Absolute Difference in BST (LeetCode 530)
Topic: Binary Search Tree, Inorder Traversal, DFS
Difficulty: Easy

Approach: Optimized Inorder Traversal
1. Perform an inorder traversal of the BST.
2. Inorder traversal of a BST visits the nodes in
   sorted order.
3. The minimum absolute difference can therefore only
   occur between two adjacent values in the inorder
   traversal.
4. Instead of storing all inorder values in a vector,
   maintain only the previous visited value.
5. For every node after the first node:
       difference = current value - previous value
6. Update the minimum difference whenever a smaller
   difference is found.
7. The first visited node has no previous value, so we
   skip the difference calculation for that node.
8. Continue until the complete inorder traversal is done.

Time Complexity:
- O(n)
  (Every node is visited exactly once.)

Space Complexity:
- O(h)
  (h = height of the BST due to recursion stack.)
  - Balanced BST: O(log n)
  - Skewed BST: O(n)

Key Insight:
- Inorder traversal of a BST produces values in sorted
  order.
- Therefore, we only need to compare each node with the
  previous node visited during inorder traversal.
- This eliminates the need to store all node values in
  a vector and reduces auxiliary space from O(n) to O(h).

Dry Run:

        4
       / \
      2   6
     / \
    1   3

Inorder Traversal:
    1 → 2 → 3 → 4 → 6

Differences:
    2 - 1 = 1
    3 - 2 = 1
    4 - 3 = 1
    6 - 4 = 2

Minimum Difference:
    1

Example:
Input:
    [4,2,6,1,3]

Output:
    1

Optimization:
- Previous approach:
      Inorder vector → O(n) extra space
- Optimized approach:
      Previous value + minimum difference → O(h) space
- Time complexity remains O(n), which is optimal because
  every node may need to be examined.

=========================================================
*/

class Solution
{
    int mini = INT_MAX;
    int prev = 0;
    bool first = true;

public:
    void sort(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        sort(root->left);

        if (!first)
        {
            int diff = root->val - prev;
            mini = min(mini, diff);
        }

        prev = root->val;
        first = false;

        sort(root->right);
    }

    int getMinimumDifference(TreeNode *root)
    {
        sort(root);
        return mini;
    }
};