
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
Problem: Construct Binary Search Tree from Preorder
         Traversal (LeetCode 1008)
Topic: Binary Search Tree, Recursion, Divide and Conquer
Difficulty: Medium

Approach: Recursive Subarray Splitting
1. In preorder traversal, the first element of a range
   is always the root of that subtree.
2. Create a node using preorder[left].
3. Find the first element greater than the root value.
4. This element marks the beginning of the right subtree.
5. All elements before it belong to the left subtree.
6. Recursively construct the left subtree using:
       left + 1 → mid - 1
7. Recursively construct the right subtree using:
       mid → right
8. If left > right, there are no elements remaining, so
   return nullptr.

Time Complexity:
- O(n^2) worst case
  (The array may be scanned repeatedly to find the
   boundary between left and right subtrees.)
- Average case can be better, but worst case is O(n^2).

Space Complexity:
- O(h)
  (h = height of the constructed BST due to recursion.)
  - Balanced BST: O(log n)
  - Skewed BST: O(n)

Key Insight:
- The first element of a preorder range is its root.
- The first value greater than the root separates the
  left subtree from the right subtree.
- No new arrays are required; only indices are used.

Example:

Preorder:
    [8, 5, 1, 7, 10, 12]

        8
       / \
      5   10
     / \    \
    1   7    12

For root 8:
    Left subtree  → [5, 1, 7]
    Right subtree → [10, 12]

Optimization:
- This approach repeatedly scans the preorder array to
  find the subtree boundary.
- This can be optimized to O(n) using a shared index and
  an upper-bound constraint.

=========================================================
*/

class Solution {
public:
    TreeNode* helper(vector<int>& preorder, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = right + 1;

        TreeNode* root = new TreeNode(preorder[left]);

        for (int i = left + 1; i <= right; i++) {
            if (preorder[i] > preorder[left]) {
                mid = i;
                break;
            }
        }

        root->left = helper(preorder, left + 1, mid - 1);
        root->right = helper(preorder, mid, right);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size() - 1);
    }
};

/*
=========================================================
Problem: Construct Binary Search Tree from Preorder
         Traversal (LeetCode 1008)
Topic: Binary Search Tree, Recursion, Preorder Traversal
Difficulty: Medium

Approach: Preorder Traversal with Upper Bound
1. Preorder traversal follows:
       Root → Left → Right
2. Therefore, preorder[index] is always the next node
   that needs to be created.
3. Maintain one shared index that moves forward through
   the preorder array only once.
4. Use an upper bound to determine whether the current
   value belongs to the current subtree.
5. If the current value is greater than the upper bound,
   it cannot belong to the current subtree, so return
   nullptr without increasing the index.
6. Create the current node and move index forward.
7. Build the left subtree with:
       upperBound = root->val
8. Build the right subtree with the previous upper bound.
9. Continue until every preorder value has been used.

Time Complexity:
- O(n)
  (Every element is processed exactly once.)

Space Complexity:
- O(h)
  (h = height of the constructed BST due to recursion.)
  - Balanced BST: O(log n)
  - Skewed BST: O(n)

Key Insight:
- Instead of repeatedly searching for where the right
  subtree begins, use an upper bound to determine whether
  the next preorder value belongs to the current subtree.
- The shared index only moves forward.
- Therefore, the entire preorder array is processed once.

Example:

Preorder:
    [8, 5, 1, 7, 10, 12]

Constructed BST:

        8
       / \
      5   10
     / \    \
    1   7    12

For node 8:
    Left subtree → values < 8

For node 5:
    Left subtree → values < 5
    Right subtree → values < 8

For node 10:
    Left subtree → values < 10
    Right subtree → values < INT_MAX

Optimization:
- Previous approach:
      Repeatedly search for subtree boundary → O(n^2)
- Optimized approach:
      Shared index + upper bound → O(n)
- No additional arrays or subtree copying are required.

=========================================================
*/

class Solution {
    int index = 0;

public:
    TreeNode* helper(vector<int>& preorder, int upperbound) {

        if (index == preorder.size() ||
            preorder[index] > upperbound) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[index]);

        index++;

        root->left = helper(preorder, root->val);
        root->right = helper(preorder, upperbound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, INT_MAX);
    }
};