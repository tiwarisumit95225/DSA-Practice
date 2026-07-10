/*
=========================================================
Problem: Reveal Cards In Increasing Order (LeetCode 950)
Topic: Queue
Difficulty: Medium

Approach:
1. Sort the deck in increasing order.
2. Create a queue containing indices from 0 to n-1.
3. Place each sorted card at the front index of the queue.
4. Remove the used index from the queue.
5. Move the next front index to the back of the queue to
   simulate the reveal process.
6. Continue until all cards are placed.

Time Complexity:
- O(n log n)

Space Complexity:
- O(n)

Key Insight:
- Simulate the reveal process using indices instead of
  moving cards.
- Sorting determines the reveal order, while the queue
  determines the placement positions.

=========================================================
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        queue<int> q;
        int n = deck.size();
        for (int i = 0; i < n; i++) {
            q.push(i);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[q.front()] = deck[i];
            q.pop();

            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};