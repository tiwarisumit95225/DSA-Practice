/*
-------------------------------------------------------
Problem: 49. Group Anagrams
Topic: HashMap, String, Sorting
Difficulty: Medium
Link: https://leetcode.com/problems/group-anagrams/

Approach:
- Traverse each string in the input array.
- Create a copy of the current string.
- Sort the copied string alphabetically.
- Use the sorted string as the key in an unordered_map.
- Store the original string in the vector corresponding to the sorted key.
- After processing all strings, collect all grouped vectors from the map.

Time Complexity: O(n × k log k)
Space Complexity: O(n × k)

Where:
- n = number of strings
- k = average length of each string

Key Learning:
- Strings with the same sorted form are anagrams.
- unordered_map can efficiently group strings using a common key.
- group[key] automatically creates an empty vector if the key does not exist.
- Sorting is the most common interview approach for this problem.
-------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> group;
        vector<vector<string>> ans;
        for (string word : strs)
        {
            string sorted = word;
            sort(sorted.begin(), sorted.end());

            group[sorted].push_back(word);
        }
        for (auto &it : group)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};

/*
-------------------------------------------------------
Problem: 49. Group Anagrams
Topic: HashMap, Character Frequency
Difficulty: Medium
Link: https://leetcode.com/problems/group-anagrams/

Approach:
- Traverse each string in the input array.
- Create a frequency array of size 26 to count character occurrences.
- Count the frequency of each lowercase letter.
- Convert the frequency array into a unique string key using to_string().
- Use this frequency key in an unordered_map.
- Store the original string in the corresponding vector.
- Finally, collect all grouped vectors from the map.

Time Complexity: O(n × k)
Space Complexity: O(n × k)

Where:
- n = number of strings
- k = average length of each string

Key Learning:
- Character frequency uniquely identifies an anagram group.
- Counting characters is faster than sorting.
- to_string() helps convert integer frequencies into a string key.
- Using separators (e.g. '#') avoids ambiguity while building the key.
- This is the optimized solution for grouping anagrams.
-------------------------------------------------------
*/
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> group;

        for (string word : strs)
        {

            vector<int> freq(26, 0);

            for (char c : word)
            {
                freq[c - 'a']++;
            }

            string key = "";
            for (int count : freq)
            {
                key += to_string(count);
                key += "#";
            }

            group[key].push_back(word);
        }

        vector<vector<string>> ans;

        for (auto &it : group)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};