/*
=========================================================
Problem: Time Needed to Buy Tickets (LeetCode 2073)
Topic: Queue
Difficulty: Easy

Approach 1: Circular Simulation
1. Traverse the array in a circular manner using modulo.
2. If the current person has remaining tickets, reduce one
   ticket and increment the time.
3. Skip people whose tickets become zero.
4. Stop when the target person (index k) finishes buying
   all tickets.

Time Complexity:
- O(total tickets)

Space Complexity:
- O(1)

Key Insight:
- Simulate the queue using circular traversal instead of an
  actual queue.
- Modulo (%) helps repeat the traversal until the target
  person finishes.

=========================================================
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int sec = 0;
        int n = tickets.size();
        int index = 0;
        while (tickets[k] != 0) {
            if (tickets[index] > 0) {
                tickets[index] = tickets[index] - 1;
                sec++;
            }
            index = (index + 1) % n;
        }
        return sec;
    }
};

/*
=========================================================
Problem: Time Needed to Buy Tickets (LeetCode 2073)
Topic: Queue
Difficulty: Easy

Approach 2: Queue Simulation
1. Store each person as {remaining tickets, original index}
   in a queue.
2. Pop the front person and let them buy one ticket.
3. Increment the elapsed time.
4. If tickets remain, push the person back into the queue.
5. If the target person finishes buying all tickets,
   return the elapsed time.

Time Complexity:
- O(total tickets)

Space Complexity:
- O(n)

Key Insight:
- Simulate the real queue process.
- Store both the remaining ticket count and original index
  to identify when the target person finishes.

=========================================================
*/
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int, int>> q;
        int time = 0;
        for (int i = 0; i < tickets.size(); i++) {
            q.push({tickets[i], i});
        }
        while (!q.empty()) {
            auto person = q.front();
            q.pop();
            person.first--;
            time++;

            if (person.first > 0) {
                q.push(person);
            } else {
                if (person.second == k && person.first == 0) {
                    return time;
                }
            }
        }
        return time;
    }
};