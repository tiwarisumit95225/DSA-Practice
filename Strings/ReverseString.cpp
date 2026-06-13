// Problem: Reverse String
// Topic: Strings, Two Pointers
// Difficulty: Easy
// Pattern: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)
// Key Learning: Swap characters from both ends and move inward until the pointers meet.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};