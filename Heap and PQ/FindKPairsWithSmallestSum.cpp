#include <iostream>
#include<queue>
#include<vector>
#include <unordered_map>
using namespace std;

/*
=========================================================
Problem: 373. Find K Pairs with Smallest Sums
Topic: Heap / Priority Queue / K-Way Merge
Difficulty: Medium

Approach:
- Both nums1 and nums2 are sorted in ascending order.
- Treat every element of nums1 as the starting point
  of a sorted stream of pair sums.
- For each nums1[i], the stream is:

    nums1[i] + nums2[0]
    nums1[i] + nums2[1]
    nums1[i] + nums2[2]
    ...

- Use a min-heap to store the smallest currently available
  pair from each stream.
- Each heap element stores:
    {sum, i, j}

  where:
    sum -> nums1[i] + nums2[j]
    i   -> index in nums1
    j   -> index in nums2

- Initially, insert the pair using nums2[0] with every
  element of nums1.
- Repeatedly:
    1. Remove the pair with the smallest sum.
    2. Add it to the answer.
    3. Move to the next element of nums2 for the same
       nums1[i].
    4. Insert that next pair into the heap.
- Stop after finding K pairs.

Why Min-Heap?
- We need the smallest currently available pair sum.
- The min-heap gives us that pair efficiently.

Key Insight:
- This is the same K-way merge pattern as LC 378.
- Each nums1[i] creates one sorted stream of pair sums.
- The heap maintains one candidate from each stream.

Example:
nums1 = [1, 7, 11]
nums2 = [2, 4, 6]
k = 3

Initial heap:
(3, 0, 0)  -> 1 + 2
(9, 1, 0)  -> 7 + 2
(13, 2, 0) -> 11 + 2

Process:
(3,0,0) -> [1,2]
push (5,0,1)

(5,0,1) -> [1,4]
push (7,0,2)

(7,0,2) -> [1,6]

Result:
[[1,2], [1,4], [1,6]]

Time Complexity:
- Heap initialization: O(N log N)
- Processing K pairs: O(K log N)
- Overall: O(N log N + K log N)

Space Complexity:
- O(N) for the heap.
- O(K) for the output.

Optimization:
- Only min(K, N) initial elements are necessary because
  we only need K pairs.
- Therefore, initialization can be reduced when K < N.

=========================================================
*/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1,
                                       vector<int>& nums2,
                                       int k) {

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        // Initialize one candidate from each stream
        for (int i = 0; i < nums1.size() && i < k; i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        vector<vector<int>> ans;

        while (!pq.empty() && ans.size() < k) {

            tuple<int, int, int> t = pq.top();
            pq.pop();

            int i = get<1>(t);
            int j = get<2>(t);

            ans.push_back({nums1[i], nums2[j]});

            // Move to the next pair in the same stream
            if (j + 1 < nums2.size()) {
                pq.push({
                    nums1[i] + nums2[j + 1],
                    i,
                    j + 1
                });
            }
        }

        return ans;
    }
};