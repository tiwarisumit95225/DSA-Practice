#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

/*
-------------------------------------------------------
Problem: 205. Isomorphic Strings
Topic: HashMap, HashSet
Difficulty: Easy
Link: https://leetcode.com/problems/isomorphic-strings/

Approach:
- Use an unordered_map to store mappings from characters in string s to characters in string t.
- Use an unordered_set to keep track of characters in t that have already been assigned.
- If a character in s is already mapped, verify that it maps to the current character in t.
- Otherwise, ensure the target character has not already been mapped.
- If all mappings remain consistent, return true.

Time Complexity: O(n)
Space Complexity: O(1)

Key Learning:
- A single HashMap cannot enforce one-to-one mappings.
- An additional HashSet ensures that no two characters map to the same target character.
-------------------------------------------------------
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, char> map;
        unordered_set<char> set;
        for (int i = 0; i < s.size(); i++) {
            if (map.count(s[i])) {
                if (map[s[i]] != t[i]) {
                    return false;
                }

            } else {
                if (set.count(t[i])) {
                    return false;
                }
                map[s[i]] = t[i];
                set.insert(t[i]);
            }
        }
        return true;
    }
};

/*
-------------------------------------------------------
Problem: 205. Isomorphic Strings
Topic: HashMap
Difficulty: Easy
Link: https://leetcode.com/problems/isomorphic-strings/

Approach:
- Maintain two HashMaps:
    1. s → t
    2. t → s
- For each character pair:
    - Verify existing mappings in both directions.
    - If inconsistent, return false.
    - Otherwise, create/update both mappings.
- If every mapping remains consistent, return true.

Time Complexity: O(n)
Space Complexity: O(1)

Key Learning:
- Bidirectional mapping guarantees a one-to-one correspondence.
- This approach is clean, scalable, and commonly preferred in interviews.
-------------------------------------------------------
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;
        for (int i = 0; i < s.size(); i++) {
            if (mp1.count(s[i])) {
                if (mp1[s[i]] != t[i]) {
                    return false;
                }
            }
            if (mp2.count(t[i])) {
                if (mp2[t[i]] != s[i]) {
                    return false;
                }
            }
            mp1[s[i]] = t[i];
            mp2[t[i]]=s[i];
        }

        return true;
    }
};

/*
-------------------------------------------------------
Problem: 205. Isomorphic Strings
Topic: Arrays
Difficulty: Easy
Link: https://leetcode.com/problems/isomorphic-strings/

Approach:
- Replace HashMaps with two arrays of size 256 to represent ASCII character mappings.
- Use one array for s → t and another for t → s.
- Verify existing mappings before creating new ones.
- Array indexing provides constant-time lookups without hashing overhead.

Time Complexity: O(n)
Space Complexity: O(1)

Key Learning:
- Arrays can replace HashMaps when the character set is fixed.
- This approach is faster due to direct indexing.
- Using unsigned char as the array index avoids negative indexing issues.
-------------------------------------------------------
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        char mp1[256] = {};
        char mp2[256] = {};

        for (int i = 0; i < s.size(); i++) {
            if (mp1[(unsigned char)s[i]] != 0) {
                if (mp1[(unsigned char)s[i]] != t[i]) {
                    return false;
                }
            }
            if (mp2[(unsigned char)t[i]] != 0) {
                if (mp2[(unsigned char)t[i]] != s[i]) {
                    return false;
                }
            }
            mp1[(unsigned char)s[i]] = t[i];
            mp2[(unsigned char)t[i]] = s[i];
        }

        return true;
    }
};