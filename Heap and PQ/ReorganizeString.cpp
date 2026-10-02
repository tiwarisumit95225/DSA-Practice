#include <iostream>
#include<queue>
#include<vector>
#include <unordered_map>
using namespace std;
/*
=========================================================
Problem: 767. Reorganize String
Topic: Heap / Priority Queue / Greedy
Difficulty: Medium

Approach:
- Count the frequency of every character using a hashmap.
- Store each character and its frequency in a max-heap.
- The character with the highest remaining frequency is
  selected first.
- Maintain two pairs:
    1. curr -> character currently being processed.
    2. prev -> previously used character that is temporarily
       kept out of the heap.
- After selecting curr:
    1. Remove it from the heap.
    2. Add its character to the answer.
    3. Decrease its frequency.
    4. Put prev back into the heap if it still has frequency.
    5. Make curr the new prev.
- This prevents the same character from being selected
  consecutively.
- If the heap becomes empty while prev still has remaining
  frequency, rearrangement is impossible, so return "".

Why Max-Heap?
- We want to select the character with the highest
  remaining frequency.
- This helps distribute the most frequent characters
  as early as possible and prevents them from becoming
  impossible to place later.

Key Insight:
- Never immediately put the current character back into
  the heap.
- Keep it temporarily aside and use another character first.
- After using another character, the previous character
  becomes available again.

Example:
s = "aaabbc"

Frequencies:
a -> 3
b -> 2
c -> 1

Possible result:
"ababac"

No two adjacent characters are equal.

Impossible Example:
s = "aaab"

After placing:
a -> b -> a -> b

One 'a' is still left, but no character is available
to separate it.

Therefore return "".

Time Complexity:
- Building frequency map: O(N)
- Building heap: O(K log K)
- Processing characters: O(N log K)
- Overall: O(N log K)
  where K is the number of distinct characters.

Space Complexity:
- Frequency map: O(K)
- Heap: O(K)
- Answer: O(N)
- Overall: O(N)

Optimization:
- Since the input contains lowercase English letters,
  K <= 26, making the heap effectively bounded by a
  constant.
- Therefore, for lowercase English letters, the practical
  complexity is close to O(N).

=========================================================
*/

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto& it : freq) {
            pq.push({it.second, it.first});
        }

        string ans = "";

        pair<int, char> prev{0, '#'};
        pair<int, char> curr;

        while (!pq.empty()) {
            curr = pq.top();
            pq.pop();

            ans += curr.second;
            curr.first--;

            if (prev.first > 0) {
                pq.push(prev);
            }

            prev = curr;
        }

        if (prev.first > 0) {
            return "";
        }

        return ans;
    }
};