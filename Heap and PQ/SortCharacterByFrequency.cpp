#include <iostream>
#include<queue>
#include<vector>
#include <unordered_map>
using namespace std;
/*
=========================================================
Problem: 451. Sort Characters By Frequency
Topic: HashMap / Heap / Priority Queue
Difficulty: Medium

Approach:
- Use an unordered_map to count the frequency of every
  character in the string.
- Store each character and its frequency in a max-heap.
- Use pair<int, char> where:
    first  -> frequency
    second -> character
- The default priority_queue creates a max-heap, so the
  character with the highest frequency appears at the top.
- Repeatedly remove the character with the highest
  frequency and append it to the answer according to
  its frequency.

Why Max-Heap?
- We need characters in decreasing order of frequency.
- A max-heap always gives us the character with the
  highest remaining frequency.

Example:
s = "tree"

Frequency:
t -> 1
r -> 1
e -> 2

Max-Heap:
(e, 2)
(t, 1)
(r, 1)

Result:
"eert"

Note:
- "eetr" is also a valid answer because characters with
  the same frequency can appear in any order.

Time Complexity:
- Building frequency map: O(N)
- Building heap: O(K log K)
- Processing heap: O(K log K)
- Constructing answer: O(N)
- Overall: O(N + K log K)

Space Complexity:
- Frequency map: O(K)
- Heap: O(K)
- Answer: O(N)
- Overall: O(N + K)

Key Insight:
- When a problem asks to arrange elements according to
  their frequency, first count frequencies and then use
  a max-heap to repeatedly process the most frequent
  element.

Optimization:
- Since the number of possible characters is limited,
  K is small in practice.
- A bucket-sort approach can achieve O(N), but the
  max-heap approach is appropriate for learning and
  applying Priority Queue patterns.

=========================================================
*/

class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> freq;

        // Count frequency of every character
        for (char c : s) {
            freq[c]++;
        }

        string ans = "";

        // Max-heap: {frequency, character}
        priority_queue<pair<int, char>> pq;

        // Insert all characters into the heap
        for (auto& it : freq) {
            pq.push({it.second, it.first});
        }

        // Process characters by decreasing frequency
        while (!pq.empty()) {

            int frequency = pq.top().first;
            char character = pq.top().second;

            pq.pop();

            // Add character according to its frequency
            for (int i = 0; i < frequency; i++) {
                ans += character;
            }
        }

        return ans;
    }
};