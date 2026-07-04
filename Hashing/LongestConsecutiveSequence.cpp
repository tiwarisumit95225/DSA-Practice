/*
-------------------------------------------------------
Problem: 128. Longest Consecutive Sequence
Topic: HashSet
Difficulty: Medium
Link: https://leetcode.com/problems/longest-consecutive-sequence/

Approach:
- Insert all elements into an unordered_set to enable O(1) average lookup.
- Traverse every unique element in the set.
- A number is considered the start of a sequence only if its previous number (num - 1) does not exist.
- From every starting number, keep checking for consecutive numbers using the HashSet.
- Count the length of each sequence and update the maximum length.

Time Complexity: O(n)
Space Complexity: O(n)

Key Learning:
- unordered_set provides O(1) average lookup.
- Checking !set.count(num - 1) avoids counting the same sequence multiple times.
- Traversing the set instead of the array prevents duplicate work.
- Although a while loop is used, every element is visited at most once, keeping the total complexity O(n).
-------------------------------------------------------
*/
#include <iostream>
#include<unordered_set>
#include<vector>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> temp;
        for (int n : nums) {
            temp.insert(n);
        }
        int length = 0;
        for (int num:temp) {
            if (!temp.count(num - 1)) {
                int curr = num;
                int count = 1;
                while (temp.count(curr + 1)) {
                    curr++;
                    count++;
                }
                length = max(length, count);
            }
        }
        return length;
    }
};