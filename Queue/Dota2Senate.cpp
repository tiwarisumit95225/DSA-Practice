// <!-- 
// =========================================================
// Problem: Dota2 Senate (LeetCode 649)
// Topic: Queue
// Difficulty: Medium

// Approach:
// 1. Use two queues to store the indices of Radiant (R) and Dire (D) senators.
// 2. Traverse the string and push the index of each senator into its respective queue.
// 3. Compare the front indices of both queues.
// 4. The senator with the smaller index gets the current turn and bans the opposing senator.
// 5. Reinsert the winning senator with index + n (where n is the length of the senate string)
//    to simulate participation in the next round.
// 6. Repeat until one queue becomes empty.
// 7. The remaining non-empty queue determines the winning party.

// Time Complexity:
// - O(n)

// Space Complexity:
// - O(n)

// Key Insight:
// - Instead of removing senators from the string, store their indices.
// - The smaller index always acts first.
// - Adding n to the winner's index preserves the cyclic order of rounds.
// - Two queues efficiently simulate the banning process.

// =========================================================
//  -->

#include <iostream>
#include <queue>
#include<string>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r;
        queue<int> d;
        int n=senate.size();
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                r.push(i);
            } else {
                d.push(i);
            }
        }
        while (!r.empty() && !d.empty()) {
            int a = r.front();
            int b = d.front();
            d.pop();
            r.pop();
            if (a < b) {
                r.push(a + n);
            } else {
                d.push(b +n);
            }
        }
        if (r.empty()) {
            return "Dire";
        } else {
            return "Radiant";
        }
    }
};