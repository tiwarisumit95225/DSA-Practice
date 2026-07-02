/*
=========================================================
Problem: Valid Anagram (LeetCode 242)
Topic: HashMap
Difficulty: Easy

Approach:
1. If the lengths of both strings are different, return false.
2. Store the frequency of each character from the first string
   using an unordered_map.
3. Traverse the second string and decrement the frequency.
4. If any frequency becomes negative, return false.
5. If all frequencies are balanced, return true.

Time Complexity: O(n)
Space Complexity: O(k)
(k = number of distinct characters, O(1) for lowercase English letters)

Key Learning:
- Use HashMap for frequency counting.
- unordered_map[key] inserts a missing key with value 0.
- The trick (--freq[ch] < 0) efficiently detects missing or extra characters.
=========================================================
*/
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        for (char ch : t) {
            if (--freq[ch] < 0) {
                return false;
            }
        }

        return true;
    }
};