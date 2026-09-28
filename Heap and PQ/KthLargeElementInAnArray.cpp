#include <iostream>
#include<queue>
#include<vector>
using namespace std;

/*
=========================================================
Problem: Kth Largest Element in an Array
LeetCode: 215
Topic: Heap / Priority Queue
Difficulty: Medium

Approach:
- Use a max-heap to store all elements of the array.
- In a max-heap, the largest element is always available
  at the top.
- Insert every element into the priority queue.
- Remove the largest element k times.
- The kth removed element is the kth largest element.

Example:

nums = [3,2,1,5,6,4]
k = 2

Max Heap:
        6
       / \
      5   4
     / \
    2   3
         \
          1

Removal:
1st largest → 6
2nd largest → 5

Answer = 5

Time Complexity:
- Building the heap by inserting n elements:
  O(n log n)
- Removing k elements:
  O(k log n)
- Overall:
  O(n log n + k log n)

Space Complexity:
- O(n)
- The priority queue stores all n elements.

Key Insight:
- A max-heap always keeps the largest element at the top.
- Therefore, repeatedly removing the top k times gives
  the kth largest element.

Optimization:
- Instead of storing all n elements, we can maintain a
  min-heap of size k.
- That reduces the complexity to O(n log k) time and
  O(k) space.

=========================================================
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // Max-heap
        priority_queue<int> pq;

        // Insert all elements into the max-heap
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }

        int max = 0;

        // Remove the largest element k times
        for (int j = 0; j < k; j++) {
            max = pq.top();
            pq.pop();
        }

        return max;
    }
};

/*
=========================================================
Problem: Kth Largest Element in an Array
LeetCode: 215
Topic: Heap / Priority Queue
Difficulty: Medium

Optimized Approach:
- Use a min-heap of size k.
- Traverse the array and insert every element.
- Whenever the heap size becomes greater than k, remove
  the smallest element.
- Therefore, the heap always contains the k largest elements
  encountered so far.
- At the end, the smallest element among those k elements is
  the kth largest element.

Example:

nums = [3,2,1,5,6,4]
k = 2

Final heap:

    [5, 6]

The heap is a min-heap, therefore:

    pq.top() = 5

Answer = 5

Time Complexity:
- O(n log k)

Space Complexity:
- O(k)

Key Insight:
- Keep only the k largest elements.
- The smallest element among those k elements is exactly
  the kth largest element.

=========================================================
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // Min-heap
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < nums.size(); i++) {

            pq.push(nums[i]);

            // Keep only k largest elements
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Smallest among the k largest = kth largest
        return pq.top();
    }
};