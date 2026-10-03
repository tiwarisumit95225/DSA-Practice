#include <iostream>
#include<queue>
#include<vector>
#include <unordered_map>
using namespace std;
/*
=========================================================
Problem: 692. Top K Frequent Words
Topic: HashMap / Heap / Priority Queue / Custom Comparator
Difficulty: Medium

Approach:
- Use an unordered_map to count the frequency of every word.
- Store each word and its frequency in a priority queue.
- Use a custom comparator because the problem has two
  ordering conditions:
    1. Higher frequency comes first.
    2. If frequencies are equal, lexicographically smaller
       word comes first.
- Store elements as:
    {frequency, word}
- Repeatedly remove the highest-priority word from the heap
  and add it to the answer.
- Stop after collecting K words.

Custom Comparator:
- If frequencies are different:
    Higher frequency gets higher priority.
- If frequencies are equal:
    Lexicographically smaller word gets higher priority.

Example:
words = ["i","love","leetcode","i","love","coding"]
k = 2

Frequency:
i        -> 2
love     -> 2
leetcode -> 1
coding   -> 1

Priority:
i
love
coding / leetcode

Result:
["i", "love"]

Time Complexity:
- Frequency counting: O(N)
- Heap construction: O(K log K)
- Extracting K elements: O(K log K)
- Overall: O(N + K log K)

Space Complexity:
- Frequency map: O(K)
- Heap: O(K)
- Answer: O(K)
- Overall: O(K)

Key Insight:
- When a priority queue needs multiple ordering rules,
  use a custom comparator.
- Here the primary key is frequency in descending order,
  while the secondary key is word in lexicographical
  ascending order.

Optimization:
- The current solution stores all distinct words in the
  heap.
- A size-K min-heap can reduce the heap-related complexity
  to O(K log K) in the construction/selection pattern
  and is useful when K is much smaller than the number
  of distinct words.
- For learning custom comparators, the current solution
  is straightforward and efficient.

=========================================================
*/

class Solution {
public:

    struct compare {
        bool operator()(const pair<int, string>& a,
                        const pair<int, string>& b) {

            // Higher frequency gets higher priority
            if (a.first != b.first) {
                return a.first < b.first;
            }

            // Lexicographically smaller word gets higher priority
            return a.second > b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> freq;

        // Count frequency of every word
        for (string word : words) {
            freq[word]++;
        }

        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            compare
        > pq;

        // Insert all words into the heap
        for (auto& it : freq) {
            pq.push({it.second, it.first});
        }

        vector<string> ans;

        // Extract only the top K words
        while (!pq.empty() && ans.size() < k) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};