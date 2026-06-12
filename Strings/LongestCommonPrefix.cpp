// Problem: Longest Common Prefix
// Topic: Strings
// Difficulty: Easy
// Pattern: Prefix Comparison
// Time Complexity: O(n * m)
// Space Complexity: O(m)
// Key Learning: Start with the first string as the prefix and keep reducing it by comparing with each string.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];

        for (int j = 1; j < strs.size(); j++) {
            string temp = "";
            int i = 0;

            while (i < prefix.size() &&
                   i < strs[j].size() &&
                   prefix[i] == strs[j][i]) {
                temp += prefix[i];
                i++;
            }

            prefix = temp;
        }

        return prefix;
    }
};