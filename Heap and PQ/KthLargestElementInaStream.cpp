#include <iostream>
#include<queue>
#include<vector>
using namespace std;
/*
=========================================================
Problem: 703. Kth Largest Element in a Stream
Topic: Heap / Priority Queue
Difficulty: Easy

Approach:
- Use a min-heap to maintain the K largest elements seen so far.
- The heap contains at most K elements.
- Whenever a new number is added:
    1. Push it into the min-heap.
    2. If the heap size becomes greater than K, remove
       the smallest element.
- Since the heap is a min-heap, the smallest element among
  the K largest elements is always at the top.
- Therefore, pq.top() gives the Kth largest element.

Why Min-Heap?
- We need to keep the K largest elements.
- Among those K elements, we need to remove the smallest
  whenever a new larger element arrives.
- A min-heap gives us that smallest element in O(1) access
  and O(log K) removal.

Time Complexity:
- Constructor: O(N log K)
- Each add(): O(log K)

Space Complexity:
- O(K)

Key Insight:
- Maintain only the K largest elements instead of storing
  the entire stream.
- The smallest element inside this K-sized min-heap is
  exactly the Kth largest element.

Example:
k = 3
nums = [4, 5, 8, 2]

Heap after processing:
[4]
[4, 5]
[4, 5, 8]
[4, 5, 8] -> 2 is added and immediately removed

Kth largest = 4

Optimization:
- A max-heap containing all elements would require
  O(N log N) construction and O(N) space.
- A min-heap of size K reduces this to O(N log K)
  construction and O(K) space.

=========================================================
*/

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);

            if (pq.size() > k) {
                pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);

        if (pq.size() > k) {
            pq.pop();
        }

        return pq.top();
    }
};