/*
=========================================================
Problem: Kth Smallest Element in a BST (LeetCode 230)
Topic: Binary Search Tree, DFS, Inorder Traversal
Difficulty: Medium

Approach 1: Inorder Traversal + Vector
1. Perform an inorder traversal of the BST.
2. During inorder traversal, store each node's
   value in a vector.
3. In a Binary Search Tree, inorder traversal
   visits values in sorted ascending order.
4. Since the vector uses 0-based indexing,
   the kth smallest element is stored at index k - 1.
5. Return inorder[k - 1].

Time Complexity:
- O(n)
  (Every node is visited once.)

Space Complexity:
- O(n)
  (The vector stores all n node values.)
- Recursion stack uses O(h), where h is the
  height of the tree.
- Overall auxiliary space: O(n + h) = O(n).

Key Insight:
- Inorder traversal of a BST produces values
  in sorted ascending order.

Example:
        5
       / \
      3   6
     / \
    2   4
   /
  1

Inorder:
    1 2 3 4 5 6

If k = 3:
    inorder[k - 1] = inorder[2] = 3

=========================================================
*/
#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> inorder;

public:
    void dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        dfs(root);
        return inorder[k - 1];
    }
};

/*
=========================================================
Problem: Kth Smallest Element in a BST (LeetCode 230)
Topic: Binary Search Tree, DFS, Inorder Traversal
Difficulty: Medium

Approach 1: Inorder Traversal + Vector
1. Perform an inorder traversal of the BST.
2. Store every visited node's value in a vector.
3. Inorder traversal of a BST produces values in
   sorted ascending order.
4. Since vector indexing starts from 0, the kth
   smallest element is stored at index k - 1.
5. Return inorder[k - 1].

Time Complexity:
- O(n)
  (Every node is visited once.)

Space Complexity:
- O(n)
  (The vector stores all node values.)
- Recursion stack uses O(h), where h is the
  height of the tree.
- Overall: O(n + h) = O(n).

Key Insight:
- Inorder traversal of a BST gives values in
  ascending sorted order.

=========================================================

Approach 2: Optimized Inorder Traversal + Counter
1. Perform inorder traversal without storing all
   node values in a vector.
2. Maintain a counter to keep track of the number
   of nodes visited.
3. Increment the counter when processing each node.
4. When count becomes equal to k, the current node
   contains the kth smallest value.
5. Store the current node's value in ans.
6. Return ans after the traversal.

Time Complexity:
- O(n) in the worst case.
- The traversal can stop once the kth node is found,
  so in practice fewer nodes may be processed.

Space Complexity:
- O(h)
  (Only the recursion stack is required.)
  - Balanced BST: O(log n)
  - Skewed BST: O(n)

Key Insight:
- Since inorder traversal already visits BST nodes
  in sorted order, we don't need to store every value.
- A counter is enough to identify the kth visited node.

Optimization:
- Approach 2 eliminates the vector used in Approach 1,
  reducing auxiliary space from O(n) to O(h).

Important:
- The counter must be a class member so that its value
  is shared across all recursive calls.
- The answer is stored when count == k.
- The DFS function uses return after finding the answer
  to stop the current recursive call.

=========================================================
*/

class Solution
{
    int count = 0;
    int ans;

public:
    void dfs(TreeNode *root, int k)
    {
        if (root == nullptr)
        {
            return;
        }

        dfs(root->left, k);

        count++;

        if (count == k)
        {
            ans = root->val;
            return;
        }

        dfs(root->right, k);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        dfs(root, k);
        return ans;
    }
};

/*
=========================================================
Problem: Kth Smallest Element in a BST (LeetCode 230)
Topic: Binary Search Tree, Inorder Traversal, Stack
Difficulty: Medium

Approach: Iterative Inorder Traversal
1. Inorder traversal of a BST visits nodes in
   ascending sorted order.
2. Use a stack to simulate recursive inorder traversal.
3. Keep moving to the leftmost node and push each
   node onto the stack.
4. Pop one node from the stack and increment k.
5. When k becomes 0, the current node is the
   kth smallest element.
6. Return the current node's value immediately.
7. There is no need to store all node values or
   traverse the remaining part of the tree.

Time Complexity:
- O(h + k)
  (h = height of the BST)
  - O(h) to reach the smallest element.
  - At most k nodes are processed before finding
    the kth smallest element.
- Worst Case: O(n)

Space Complexity:
- O(h)
  (The stack contains at most h nodes.)
  - Balanced BST: O(log n)
  - Skewed BST: O(n)

Key Insight:
- Inorder traversal of a BST produces values in
  ascending order.
- Therefore, the kth node visited during inorder
  traversal is the kth smallest element.

Optimization:
- No vector is required.
- No recursive call stack is required.
- The traversal stops immediately after finding
  the kth smallest element.

=========================================================
*/

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> st;

        while (root != nullptr || !st.empty())
        {
            while (root != nullptr)
            {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();

            k--;

            if (k == 0)
            {
                return root->val;
            }

            root = root->right;
        }

        return -1;
    }
};