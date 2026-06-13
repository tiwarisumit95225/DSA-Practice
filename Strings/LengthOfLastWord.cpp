// Problem: Length of Last Word
// Topic: Strings
// Difficulty: Easy
// Pattern: Reverse Traversal
// Time Complexity: O(n)
// Space Complexity: O(1)
// Key Learning: Traverse from the end, skip trailing spaces, and count characters until the next space is found.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (count != 0) {
                    break;
                }
            } else {
                count++;
            }
        }

        return count;
    }
};