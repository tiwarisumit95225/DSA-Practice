#include <iostream>
#include<queue>
#include<vector>
#include <algorithm>
using namespace std;
/*
=========================================================
Problem: 1834. Single-Threaded CPU
Topic: Heap / Priority Queue + Sorting + Simulation
Difficulty: Medium

Approach:
- Add the original index to every task.
- Sort all tasks according to their enqueue time.
- Maintain a pointer `j` to track the next task that has
  not yet been added to the priority queue.
- Use a min-heap containing:
      {processingTime, originalIndex}
- The priority queue automatically selects:
      1. Smallest processing time
      2. Smallest original index if processing times are equal
- Maintain `time` as the current CPU time.
- If the priority queue is empty and there are still tasks
  remaining, jump `time` to the next task's enqueue time.
- Add every task whose enqueue time is less than or equal to
  the current `time` into the heap.
- Process the task at the top of the heap:
      - Add its original index to the answer.
      - Increase `time` by its processing time.
      - Remove it from the heap.
- Continue until every task has been processed.

Why Sorting?
- Sorting by enqueue time allows us to add tasks to the heap
  in chronological order using a single pointer `j`.

Why Min-Heap?
- The CPU must choose the available task with the smallest
  processing time.
- If processing times are equal, it must choose the smallest
  original index.
- `pair<int, int>` with `greater<pair<int,int>>` handles both
  conditions automatically.

Important:
- `time` must be `long long`.
- Processing times can be as large as 10^9, and the total
  processing time can exceed the range of a normal `int`.

Time Complexity:
- O(n log n)
- Sorting takes O(n log n).
- Each task is inserted into and removed from the heap once,
  giving O(n log n).

Space Complexity:
- O(n)
- O(n) for the modified task array, answer, and priority queue.

Key Insight:
- Separate the problem into two parts:
      1. Sorting handles when tasks become available.
      2. Min-heap handles which available task should execute.
- `j` tracks tasks entering the heap, while `time` tracks
  CPU progress.

Example:
tasks = [[1,2],[2,4],[3,2],[4,1]]

Processing order:
0 → 2 → 3 → 1

Output:
[0,2,3,1]

=========================================================
*/

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for (int i = 0; i < tasks.size(); i++) {
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end());

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        long long time = 0;
        vector<int> ans;
        int j = 0;

        for (int i = 0; i < tasks.size(); i++) {

            // If CPU is idle, jump to the next task's enqueue time
            if (pq.empty() && j < tasks.size() &&
                time < tasks[j][0]) {
                time = tasks[j][0];
            }

            // Add all currently available tasks
            while (j < tasks.size() && tasks[j][0] <= time) {
                pq.push({tasks[j][1], tasks[j][2]});
                j++;
            }

            // Process the task with minimum processing time
            ans.push_back(pq.top().second);
            time += pq.top().first;
            pq.pop();
        }

        return ans;
    }
};