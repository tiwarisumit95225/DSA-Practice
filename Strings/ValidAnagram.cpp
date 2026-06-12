// Problem: Valid Anagram
// Topic: Strings
// Difficulty: Easy
// Pattern: Frequency Count
// Time Complexity: O(n)
// Space Complexity: O(1)
// Key Learning: Use a frequency array to count character occurrences and verify that both strings contain the same characters with the same frequencies.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length()) {
            return false;
        }

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        for (char c : t) {
            freq[c - 'a']--;
        }

        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};