// Problem: Find the Index of the First Occurrence in a String
// Topic: Strings
// Difficulty: Easy
// Pattern: Brute Force String Matching
// Time Complexity: O((n - m + 1) * m) ≈ O(n * m)
// Space Complexity: O(1)
// Key Learning: Check every possible starting position in the haystack
// and compare characters one by one with the needle until a match is found.

#include <string>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.size() > haystack.size())
        {
            return -1;
        }

        for (int i = 0; i <= haystack.size() - needle.size(); i++)
        {
            bool match = true;

            for (int j = 0; j < needle.size(); j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                return i;
            }
        }

        return -1;
    }
};