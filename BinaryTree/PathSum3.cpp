#include <iostream>
#include <unordered_map>
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
Problem: Path Sum III (LeetCode 437)
Topic: Binary Tree, DFS, Recursion
Difficulty: Medium

Approach (Brute Force DFS):
1. Use a helper function to count all valid downward paths
   starting from the current node.
2. For every node in the tree, treat it as a new starting point.
3. The helper recursively explores both left and right children
   while decreasing the remaining target.
4. Sum the results from the current node, left subtree,
   and right subtree.

Time Complexity:
- O(n²) Worst Case
- O(n log n) Average (Balanced Tree)

Space Complexity:
- O(h)
  (h = height of the tree due to recursion stack)

Key Insight:
- A valid path can start at any node.
- Therefore, two DFS traversals are required:
  1. One to count paths starting from a node.
  2. One to move the starting point to every node.

=========================================================
*/

class Solution {
public:
    int countFrom(TreeNode* root, long long target) {
        int curr = 0;
        if (root == nullptr) {
            return 0;
        }
        target -= root->val;

        if (target == 0) {
            curr = 1;
        }

        return curr + countFrom(root->left, target) +
               countFrom(root->right, target);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }
        return countFrom(root, targetSum) + pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum);
    }
};


/*
=========================================================
Problem:
437. Path Sum III

Topic:
Binary Tree, DFS, Prefix Sum, HashMap, Backtracking

Difficulty:
Medium

Approach:
- Use DFS while maintaining the prefix sum from the root to the current node.
- Store the frequency of each prefix sum in a HashMap.
- For every node:
  1. Update the current prefix sum.
  2. Compute:
        needed = currentPrefix - targetSum
  3. Add the frequency of 'needed' to the answer.
  4. Insert the current prefix sum into the HashMap.
  5. Recurse on the left and right subtrees.
  6. Remove the current prefix sum while backtracking.
- Initialize the HashMap with {0 : 1} so that paths starting from the root are counted.

Time Complexity:
O(n)

Space Complexity:
O(n)

Key Insight:
Instead of checking every starting node separately, maintain prefix sums
along the current root-to-node path. Any previous prefix sum equal to
(currentPrefix - targetSum) forms a valid path ending at the current node.
Backtracking ensures the HashMap only represents the current DFS path.

=========================================================
*/

class Solution {
public:
    unordered_map<long long, int> map;
    int ans = 0;
    void countFrom(TreeNode* root, long long currprefix, int target) {
        if (root == nullptr) {
            return;
        }

        currprefix += root->val;
        long long needed = currprefix - target;
        ans += map[needed];
        map[currprefix]++;

        countFrom(root->left, currprefix, target);
        countFrom(root->right, currprefix, target);
        map[currprefix]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }
        map.clear();
        ans = 0;
        map[0] = 1;
        countFrom(root, 0, targetSum);
        return ans;
    }
};