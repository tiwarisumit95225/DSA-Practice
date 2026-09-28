#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
/*
=========================================================
Problem: 347. Top K Frequent Elements
Topic: Heap / Priority Queue + HashMap
Difficulty: Medium

Approach:
- Use an unordered_map to store the frequency of each element.
- Store each element as {frequency, number} in a min-heap.
- Keep the heap size at most k.
- When the heap size exceeds k, remove the element with
  the smallest frequency.
- After processing all elements, the heap contains the
  k most frequent elements.
- Extract the numbers from the heap into the answer vector.

Why Min-Heap?
- We want to keep the k elements with the highest frequency.
- The element with the smallest frequency should be removed
  whenever the heap size becomes greater than k.
- Therefore, the smallest frequency stays at the top.

Time Complexity:
- Frequency counting: O(n)
- Processing distinct elements: O(m log k)
- Overall: O(n + m log k)
  where m = number of distinct elements.
- Since m <= n, this is commonly written as O(n log k).

Space Complexity:
- HashMap: O(m)
- Heap: O(k)
- Overall: O(m + k), which is O(n) in the worst case.

Key Insight:
- HashMap gives us the frequency of every element.
- A min-heap of size k allows us to efficiently maintain
  the k elements having the highest frequencies.

Example:
nums = [1,1,1,2,2,3], k = 2

Frequency:
1 -> 3
2 -> 2
3 -> 1

Heap processing:
{3,1}
{2,2}
{1,3} -> size becomes 3 -> remove {1,3}

Remaining:
{2,2}
{3,1}

Answer:
[2,1]

Optimization:
- A Bucket Sort approach can solve this problem in O(n)
  average time.
- However, the min-heap solution is more useful for learning
  the Top-K / Priority Queue pattern and works efficiently
  when k is small.

=========================================================
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        // Count frequency of every element
        for (int n : nums) {
            freq[n]++;
        }

        // Min-heap: {frequency, number}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        // Keep only k elements with highest frequency
        for (auto& it : freq) {

            pq.push({it.second, it.first});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;

        // Extract the k most frequent elements
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};