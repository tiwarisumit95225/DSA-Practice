#include <iostream>
#include <unordered_set>
using namespace std;
 struct TreeNode {
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
Problem: Two Sum IV - Input is a BST
LeetCode: 653
Topic: Binary Search Tree / Hashing
Difficulty: Easy

Approach:
- Traverse every node of the BST using DFS.
- For each node, calculate the value required to make the
  sum equal to k.

    complement = k - root->val

- Check whether this complement already exists in the
  unordered_set.
- If it exists, we have found two different nodes whose
  values add up to k.
- Otherwise, insert the current node's value into the set.
- Continue traversing the left and right subtrees.

Why check before inserting?
- We check the complement before inserting the current value.
- This prevents the current node from being paired with itself.

Example:

        5
       / \
      3   6
     / \   \
    2   4   7

k = 9

Traversal:
5 → complement = 4 → not found → store 5
3 → complement = 6 → not found → store 3
2 → complement = 7 → not found → store 2
4 → complement = 5 → found!

Therefore, 4 + 5 = 9 → true.

Time Complexity:
- O(n)
- Every node is visited once.
- unordered_set lookup and insertion take O(1) average time.

Space Complexity:
- O(n) for storing node values in unordered_set.
- O(h) additional recursion stack, where h is the height
  of the tree.
- Overall auxiliary space: O(n).

Key Insight:
- We do not need to use the BST property.
- This problem can be treated as the classic Two Sum
  problem on a tree.
- For every value x, we simply check whether (k - x)
  has already been seen.

Optimization:
- The hashmap approach gives O(n) average time.
- It is simpler than performing a separate BST search
  for every node.
- A two-iterator BST approach can reduce auxiliary space
  to O(h), but is more complex.

=========================================================
*/

class Solution {
    unordered_set<int> seen;

public:
    bool traverse(TreeNode* root, int k) {
        if (root == nullptr) {
            return false;
        }

        int complement = k - root->val;

        // Check if the required complement was already seen
        if (seen.count(complement)) {
            return true;
        }

        // Store current node's value
        seen.insert(root->val);

        // Traverse left and right subtrees
        return traverse(root->left, k) ||
               traverse(root->right, k);
    }

    bool findTarget(TreeNode* root, int k) {
        return traverse(root, k);
    }
};