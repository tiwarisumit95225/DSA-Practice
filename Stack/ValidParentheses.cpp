// Problem: Valid Parentheses
// Topic: Stack
// Difficulty: Easy
// Pattern: Stack Matching
// Time Complexity: O(n)
// Space Complexity: O(n)
// Key Learning: Use a stack to track opening brackets. When a closing bracket appears,
// check if it matches the most recent opening bracket. This follows the LIFO principle.

#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }

                if ((st.top() == '(' && s[i] == ')') ||
                    (st.top() == '{' && s[i] == '}') ||
                    (st.top() == '[' && s[i] == ']'))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return st.empty();
    }
};