/*
=========================================================
Problem: Number of Recent Calls (LeetCode 933)
Topic: Queue
Difficulty: Easy

Approach:
1. Use a queue to store the timestamps of all recent requests.
2. For every new request, push its timestamp into the queue.
3. Remove all timestamps from the front that are older than
   (currentTime - 3000).
4. The remaining elements in the queue represent all requests
   within the last 3000 milliseconds.
5. Return the current size of the queue.

Time Complexity:
- ping(): O(1) (Amortized)

Space Complexity:
- O(n)

Key Insight:
- Each timestamp is inserted into the queue exactly once and
  removed at most once, making the total operations linear
  over all calls and O(1) amortized per operation.

=========================================================
*/
#include <iostream>
#include <queue>
using namespace std;
class RecentCounter
{
private:
    queue<int> q;

public:
    RecentCounter() {}

    int ping(int t)
    {

        while (!q.empty() && q.front() < t - 3000)
        {
            q.pop();
        }
        q.push(t);
        return q.size();
    }
};