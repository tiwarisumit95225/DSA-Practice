#include <iostream>
#include<queue>
#include<vector>
#include <tuple>
using namespace std;
/*
=========================================================
Problem: 378. Kth Smallest Element in a Sorted Matrix
Topic: Heap / Priority Queue / K-Way Merge
Difficulty: Medium

Approach:
- Each row of the matrix is sorted in ascending order.
- Treat every row as a separate sorted stream.
- Use a min-heap to store the smallest currently available
  element from each row.
- Each heap element stores:
    {value, row, column}
- Initially, insert the first element of every row.
- Repeatedly:
    1. Remove the smallest element from the heap.
    2. Increment the count.
    3. If count == k, return the value.
    4. Move to the next element in the same row.
    5. Insert that next element into the heap if it exists.
- This is essentially a K-way merge of sorted rows.

Why Min-Heap?
- We need the smallest currently available element
  across all rows.
- A min-heap gives us that element in O(log N) time.

Why Store Row and Column?
- After removing an element, we need to know which row
  it came from.
- We then move one position forward in that same row.

Example:
matrix =
[
    [ 1,  5,  9],
    [10, 11, 13],
    [12, 13, 15]
]

k = 8

Initial heap:
(1,0,0)
(10,1,0)
(12,2,0)

The heap repeatedly takes the smallest value and
adds the next value from the same row.

The 8th smallest element is 13.

Time Complexity:
- Initial heap construction: O(N log N)
- Extracting up to K elements: O(K log N)
- Overall: O((N + K) log N)
  where N is the number of rows.

Space Complexity:
- O(N)
- At most one candidate from each row is stored
  in the heap.

Key Insight:
- When dealing with multiple sorted sequences, keep one
  candidate from each sequence in a min-heap.
- After removing a candidate, advance only the sequence
  from which it came.

Optimization:
- The heap contains at most N elements instead of all
  N² matrix elements.
- A binary-search-on-value solution can achieve better
  asymptotic complexity, but the min-heap solution is the
  appropriate K-way merge approach.

=========================================================
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        // Insert the first element of every row
        for (int i = 0; i < matrix.size(); i++) {
            pq.push({matrix[i][0], i, 0});
        }

        int count = 0;

        while (!pq.empty()) {

            tuple<int, int, int> t = pq.top();
            pq.pop();

            count++;

            // Kth smallest element found
            if (count == k) {
                return get<0>(t);
            }

            int row = get<1>(t);
            int col = get<2>(t);

            // Insert the next element from the same row
            if (col + 1 < matrix[row].size()) {
                pq.push({
                    matrix[row][col + 1],
                    row,
                    col + 1
                });
            }
        }

        return -1;
    }
};