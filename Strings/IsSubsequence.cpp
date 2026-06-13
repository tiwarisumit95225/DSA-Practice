// Problem: Is Subsequence
// Topic: Strings, Two Pointers
// Difficulty: Easy
// Pattern: Two Pointers
// Time Complexity: O(n + m)
// Space Complexity: O(1)
// Key Learning: Use two pointers to check whether all characters of one string appear in another string in the same order.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        if (s.empty()) {
            return true;
        }

        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }

        if (i == s.size()) {
            return true;
        }

        return false;
    }
};