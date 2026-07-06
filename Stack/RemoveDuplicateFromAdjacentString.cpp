/*
=========================================================
Problem: Remove All Adjacent Duplicates In String (LeetCode 1047)
Topic: Stack
Difficulty: Easy

Approach:
1. Traverse the string character by character.
2. Use a stack to keep track of characters.
3. If the current character matches the top of the stack,
   remove the top element (adjacent duplicate found).
4. Otherwise, push the current character onto the stack.
5. Build the final string by popping all elements from the
   stack and reverse it before returning.

Time Complexity: O(n)
Space Complexity: O(n)

=========================================================
*/
#include<iostream>
#include<stack>
#include <algorithm>
#include<string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            char curr = s[i];
            if (!st.empty() && st.top() == curr) {
                st.pop();
            } else {
                st.push(curr);
            }
        }

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};

/*
=========================================================
Problem: Remove All Adjacent Duplicates In String (LeetCode 1047)
Topic: Stack (String as Stack)
Difficulty: Easy

Approach:
1. Use a string as a stack.
2. Traverse each character in the input string.
3. If the current character matches the last character of
   the result string, remove the last character.
4. Otherwise, append the current character.
5. Return the resulting string directly.

Time Complexity: O(n)
Space Complexity: O(n)

=========================================================
*/

class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";

        for (char ch : s) {
            if (!ans.empty() && ans.back() == ch) {
                ans.pop_back();
            } else {
                ans.push_back(ch);
            }
        }

        return ans;
    }
};


