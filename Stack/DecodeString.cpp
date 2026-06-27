/*
Problem: Decode String (LeetCode 394)
Topic: Stack
Difficulty: Medium

Approach:
- Use one stack to store repeat counts.
- Use another stack to store the previously built string.
- Build multi-digit numbers using num = num * 10 + digit.
- On '[', save the current state and reset.
- On ']', pop the previous string and count, repeat the current string,
  append it to the previous string, and continue.

Time Complexity: O(n)
Space Complexity: O(n)

Key Learning:
- Using two stacks to preserve state when processing nested structures.
- Building multi-digit numbers while traversing a string.
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        stack<int> count;
        string curr = "";
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
           
            if (isdigit(s[i])) {
                 num = num * 10 + (s[i] - '0');
             
            } else if (isalpha(s[i])) {
                curr += s[i];
            } else if (s[i] == '[') {
                count.push(num);
                st.push(curr);
                num = 0;
                curr = "";
            } else if (s[i] == ']') {
                int a = count.top();
                count.pop();
                string prev = st.top();
                st.pop();
                for (int i = 0; i < a; i++) {
                    prev += curr;
                }
                curr = prev;
            }
        }
        return curr;
    }
};