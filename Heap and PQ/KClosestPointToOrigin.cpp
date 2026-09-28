#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
=========================================================
Problem: 973. K Closest Points to Origin
Topic: Heap / Priority Queue
Difficulty: Medium

Approach:
- Use a max-heap to maintain the k closest points seen so far.
- For every point, calculate its squared Euclidean distance:
      distance = x² + y²
- Store {distance, point} in the max-heap.
- The max-heap keeps the point with the largest distance
  at the top.
- If the heap size becomes greater than k, remove the
  farthest point.
- After processing all points, the heap contains exactly
  the k closest points.

Why Max-Heap?
- We need to keep the k smallest distances.
- Whenever we have more than k points, we need to remove
  the largest distance.
- Therefore, the farthest point must be available at the
  top of the heap.

Why Squared Distance?
- Actual distance is:
      sqrt(x² + y²)
- Square root is unnecessary because sqrt() is monotonic.
- Comparing x² + y² gives the same ordering as comparing
  sqrt(x² + y²).

Example:
points = [[1,3],[-2,2],[5,8]]
k = 2

Squared distances:
[1,3]   -> 1² + 3² = 10
[-2,2]  -> (-2)² + 2² = 8
[5,8]   -> 5² + 8² = 89

Heap processing:
(10, [1,3])
(8,  [-2,2])
(89, [5,8]) -> size becomes 3
Remove (89, [5,8])

Remaining:
(10, [1,3])
(8,  [-2,2])

Answer:
[[1,3],[-2,2]]

Time Complexity:
- Calculating distance for every point: O(n)
- Each heap insertion/removal: O(log k)
- Overall: O(n log k)

Space Complexity:
- Heap stores at most k points.
- O(k)

Optimization:
- Quickselect can achieve O(n) average time and O(1)
  auxiliary space when performed in-place.
- However, the max-heap approach is simpler and provides
  predictable O(n log k) performance.

Key Insight:
- To find K smallest elements:
      Use a Max-Heap of size K.
- The largest element among the current K elements is
  removed whenever a new candidate is added.

=========================================================
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<
            pair<int, vector<int>>,
            vector<pair<int, vector<int>>>
        > pq;

        for (int i = 0; i < points.size(); i++) {

            int sqr = 0;

            for (int j = 0; j < 2; j++) {
                sqr += points[i][j] * points[i][j];
            }

            pq.push({sqr, points[i]});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};