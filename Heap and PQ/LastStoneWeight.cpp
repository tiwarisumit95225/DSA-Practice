#include <iostream>
#include<queue>
#include<vector>
using namespace std;

/*
=========================================================
Problem: 1046. Last Stone Weight
Topic: Heap / Priority Queue
Difficulty: Easy

Approach:
- Use a max-heap to always get the two heaviest stones.
- Insert all stones into the max-heap.
- While there is more than one stone:
    1. Remove the heaviest stone x.
    2. Remove the second heaviest stone y.
    3. If x != y, push the difference (x - y) back.
- If all stones are destroyed, return 0.
- Otherwise, return the remaining stone.

Why Max-Heap?
- We always need the two largest stones.
- A max-heap keeps the largest element at the top.
- Therefore, both required stones can be obtained efficiently
  in O(log n) time.

Example:
stones = [2,7,4,1,8,1]

Max-Heap:
[8,7,4,2,1,1]

8 - 7 = 1
Heap -> [4,2,1,1,1]

4 - 2 = 2
Heap -> [2,1,1,1]

2 - 1 = 1
Heap -> [1,1,1]

1 - 1 = 0
Heap -> [1]

1 remains.

Answer = 1

Time Complexity:
- Building the heap: O(n log n)
- Each stone operation: O(log n)
- Overall: O(n log n)

Space Complexity:
- Max-heap stores all stones.
- O(n)

Key Insight:
- When a problem repeatedly asks for the largest element,
  a max-heap is a natural choice.
- After removing the two largest values, their difference
  becomes the next candidate.

Optimization:
- The solution is already optimal for the Priority Queue
  approach.
- Since the heap initially contains all n stones, the
  complexity is O(n log n).

=========================================================
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq;

        for (int stone : stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {

            int x = pq.top();
            pq.pop();

            int y = pq.top();
            pq.pop();

            if (x > y) {
                pq.push(x - y);
            }
        }

        if (pq.empty()) {
            return 0;
        }

        return pq.top();
    }
};