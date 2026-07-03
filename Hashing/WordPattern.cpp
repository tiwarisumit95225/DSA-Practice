#include <iostream>
#include <string>
#include <vector>
#include <vector>
#include <sstream>
#include<unordered_map>
using namespace std;

/*
-------------------------------------------------------
Problem: 290. Word Pattern
Topic: HashMap, String
Difficulty: Easy
Link: https://leetcode.com/problems/word-pattern/

Approach:
- Traverse the input string character by character.
- Build each word manually until a space is encountered.
- Store all words in a vector.
- If the number of words differs from the pattern length, return false.
- Use two HashMaps:
    1. Pattern character -> Word
    2. Word -> Pattern character
- Verify mappings in both directions to maintain a one-to-one relationship.

Time Complexity: O(n)
Space Complexity: O(n)

Key Learning:
- Learned manual string parsing without using STL utilities.
- Bidirectional HashMaps ensure a valid one-to-one mapping.
- Always push the last word after finishing the traversal.
-------------------------------------------------------
*/
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string temp = "";
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                temp += s[i];
            } else {
                words.push_back(temp);
                temp.clear();
            }
        }
        if (!temp.empty()) {
            words.push_back(temp);
        }

        if (words.size() != pattern.size()) {
            return false;
        }

        for (int i = 0; i < pattern.size(); i++) {
            if (mp1.count(pattern[i])) {
                if (mp1[pattern[i]] != words[i]) {
                    return false;
                }
            }
            if (mp2.count(words[i])) {
                if (mp2[words[i]] != pattern[i]) {
                    return false;
                }
            }
            mp1[pattern[i]] = words[i];
            mp2[words[i]] = pattern[i];
        }
        return true;
    }
};

/*
-------------------------------------------------------
Problem: 290. Word Pattern
Topic: HashMap, StringStream
Difficulty: Easy
Link: https://leetcode.com/problems/word-pattern/

Approach:
- Use stringstream to extract one word at a time from the input string.
- Process each word immediately without storing all words.
- Maintain two HashMaps:
    1. Pattern character -> Word
    2. Word -> Pattern character
- Validate mappings in both directions.
- Ensure the number of words matches the pattern length.

Time Complexity: O(n)
Space Complexity: O(m)

Key Learning:
- stringstream simplifies splitting a sentence into words.
- Processing words on the fly avoids storing an extra vector.
- Bidirectional HashMaps provide an efficient one-to-one mapping.
-------------------------------------------------------
*/class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word = "";
        int i = 0;
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        while (ss >> word) {
            if (i > pattern.size()) {
                return false;
            }
            if (mp1.count(pattern[i])) {
                if (mp1[pattern[i]] != word) {
                    return false;
                }
            }
            if (mp2.count(word)) {
                if (mp2[word] != pattern[i]) {
                    return false;
                }
            }
            mp1[pattern[i]] = word;
            mp2[word] = pattern[i];
            i++;
        }
        return i == pattern.size();
    }
};