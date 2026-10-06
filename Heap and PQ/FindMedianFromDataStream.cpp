#include <iostream>
#include<queue>
using namespace std;
/*
=========================================================
Problem: 295. Find Median from Data Stream
Topic: Heap / Two Heaps
Difficulty: Hard

Approach:
- Maintain two heaps:
    1. left  -> max heap containing the smaller half
    2. right -> min heap containing the larger half

- The top of `left` gives the largest element of the
  smaller half.

- The top of `right` gives the smallest element of the
  larger half.

- When adding a number:
    - If it belongs to the smaller half, push it into left.
    - Otherwise, push it into right.
    - Rebalance the heaps if their sizes differ by more
      than 1.

- To find the median:
    - If left has more elements, left.top() is the median.
    - If right has more elements, right.top() is the median.
    - If both have the same size, the median is the average
      of both heap tops.

Time Complexity:
- addNum(): O(log n)
- findMedian(): O(1)

Overall:
- O(log n) per insertion
- O(1) per median query

Space Complexity:
- O(n)

Key Insight:
- Instead of sorting the entire data stream every time,
  divide the numbers into two balanced halves.
- Two heaps allow us to access the two middle elements
  in O(1) time.

Important C++ Detail:
- `priority_queue::size()` returns an unsigned type.
- Avoid expressions such as:
      left.size() - right.size() > 1
  because unsigned subtraction can underflow.
- Instead use:
      left.size() > right.size() + 1

=========================================================
*/

class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder() {}

    void addNum(int num) {
        if (left.empty() && right.empty()) {
            left.push(num);
            return;
        }

        if (num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }

        if (right.size() > left.size() + 1) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() > right.size()) {
            return left.top();
        }

        if (right.size() > left.size()) {
            return right.top();
        }

        return ((double)left.top() + right.top()) / 2.0;
    }
};