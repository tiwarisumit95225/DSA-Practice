#include <iostream>
#include<queue>
#include<vector>
using namespace std;
/*
=========================================================
Problem: 1642. Furthest Building You Can Reach
Topic: Heap / Priority Queue + Greedy
Difficulty: Medium

Approach:
- Traverse the buildings from left to right.
- For every upward climb, initially assume that we use a ladder.
- Store every upward climb in a min-heap.
- If the number of climbs assigned to ladders becomes greater
  than the number of available ladders, we must convert one
  ladder assignment into a brick usage.
- To make the best choice, remove the SMALLEST climb from the
  min-heap and pay for it using bricks.
- This ensures that ladders are ultimately reserved for the
  largest climbs.
- If bricks become negative, we cannot reach the current
  building, so return the previous building index.
- If we successfully process all buildings, return the last
  building index.

Why Min-Heap?
- We want ladders to be used for the largest climbs.
- Whenever we have too many ladder assignments, we should
  replace the smallest climb with bricks.
- Therefore, we need the smallest climb quickly -> Min-Heap.

Time Complexity:
- O(n log n)
- Each upward climb is inserted into the heap once and can
  be removed once.

Space Complexity:
- O(n)
- In the worst case, the heap can contain O(n) climbs.

Key Insight:
- Initially give ladders to every upward climb.
- Whenever we exceed the available number of ladders, remove
  the smallest climb and pay for it using bricks.
- This greedy strategy ensures that ladders are used on the
  largest climbs.

Example:
heights = [4,2,7,6,9,14,12]
bricks = 5
ladders = 1

Climbs:
2 -> 7 = 5
6 -> 9 = 3
9 -> 14 = 5

The ladder is ultimately used for a climb of 5.
The climb of 3 is paid using bricks.

Furthest reachable building = 4

Optimization:
- The O(n log n) min-heap approach is the standard and
  preferred interview solution.
- A more complicated selection-based approach can improve
  theoretical average time, but is not preferable here
  because the heap solution is simpler, robust, and easy
  to prove.

=========================================================
*/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 1; i < heights.size(); i++) {
            int climb = heights[i] - heights[i - 1];

            if (climb <= 0) {
                continue;
            }

            pq.push(climb);

            if (pq.size() > ladders) {
                bricks -= pq.top();
                pq.pop();

                if (bricks < 0) {
                    return i - 1;
                }
            }
        }

        return heights.size() - 1;
    }
};