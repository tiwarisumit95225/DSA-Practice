#include <iostream>
#include<queue>
#include<vector>
#include <unordered_map>
using namespace std;

/*
=========================================================
Problem: 621. Task Scheduler
Topic: Heap / Priority Queue + Queue
Difficulty: Medium

Approach:
- Count the frequency of every task using an unordered_map.
- Use a max-heap to always select the currently available
  task with the highest remaining frequency.
- After executing a task, if it still has remaining
  occurrences, put it into a cooldown queue.
- Store the cooldown task as:
      {remaining_frequency, available_time}
- At every time interval:
    1. Move all tasks whose cooldown has expired back
       into the max-heap.
    2. Execute the most frequent available task.
    3. If the task still has remaining occurrences, put it
       into the cooldown queue.
    4. Increment the CPU time.
- If no task is available while some task is cooling down,
  the CPU remains idle and time still increases.

Why Max-Heap?
- At every moment, we want to execute the available task
  with the highest remaining frequency.
- A max-heap gives us that task in O(log M) time.

Why Cooldown Queue?
- After executing a task, it cannot immediately be used
  again.
- We need to remember:
      1. How many executions remain.
      2. When the task becomes available again.
- Therefore, each queue element stores:
      {remaining_frequency, available_time}

Example:
tasks = [A,A,A,B,B,B]
n = 2

Initial frequencies:
A -> 3
B -> 3

Schedule:
A B idle A B idle A B

Total intervals = 8

For example, after executing A at time 0:
A has 2 executions remaining.

It becomes available again at:
0 + n + 1 = 3

So the cooldown queue stores:
{2, 3}

Key Insight:
- Available tasks → Max-Heap
- Cooling tasks → Queue
- Current position in the schedule → Time

State transition:

Available
   ↓
Max-Heap
   ↓
Execute task
   ↓
Cooldown Queue
   ↓
Cooldown expires
   ↓
Max-Heap

Time Complexity:
- Frequency counting: O(N)
- Each task execution involves heap operations.
- With M distinct task types:
      O(N log M)
- Since the problem contains only 26 uppercase letters:
      M <= 26
- Therefore, this is effectively O(N).

Space Complexity:
- Frequency map: O(M)
- Max-heap: O(M)
- Cooldown queue: O(M)
- Overall: O(M)
- Since M <= 26, auxiliary space is effectively O(1).

Optimization:
- There is a mathematical greedy/counting solution that
  can achieve O(N) time and O(1) extra space for the fixed
  26-letter alphabet.
- However, the Heap + Queue solution is a more general
  scheduling simulation and clearly demonstrates the
  Priority Queue pattern.

=========================================================
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> freq;

        // Count frequency of every task
        for (char x : tasks) {
            freq[x]++;
        }

        // Max-heap: highest frequency task at the top
        priority_queue<int> pq;

        for (auto& it : freq) {
            pq.push(it.second);
        }

        // {remaining_frequency, available_time}
        queue<pair<int, int>> q;

        int time = 0;

        while (!pq.empty() || !q.empty()) {

            // Move all tasks whose cooldown has expired
            // back into the available-task heap
            while (!q.empty() && q.front().second <= time) {
                pq.push(q.front().first);
                q.pop();
            }

            // Execute the most frequent available task
            if (!pq.empty()) {

                int fre = pq.top();
                pq.pop();

                fre--;

                // Task still has remaining executions,
                // so put it into cooldown
                if (fre > 0) {
                    q.push({fre, time + n + 1});
                }
            }

            // One CPU interval has passed
            time++;
        }

        return time;
    }
};