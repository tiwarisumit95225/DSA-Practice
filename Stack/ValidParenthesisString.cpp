/*
=========================================================
Problem: Valid Parenthesis String (LeetCode 678)
Topic: Stack
Difficulty: Medium

Approach:
1. Use two stacks to store the indices of '(' and '*'.
2. Traverse the string:
   - Push the index of '(' into the open stack.
   - Push the index of '*' into the star stack.
   - For ')':
     a. Match it with the nearest unmatched '(' if available.
     b. Otherwise, use '*' as '(' if available.
     c. If neither exists, return false.
3. After traversal, match any remaining '(' with '*' that
   appear after them.
4. If any unmatched '(' remain, return false; otherwise true.

Time Complexity: O(n)
Space Complexity: O(n)

=========================================================
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open;
        stack<int> star;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open.push(i);
            } else if (s[i] == '*') {
                star.push(i);
            }
            if (s[i] == ')' && !open.empty()) {
                open.pop();
            } else if (s[i] == ')' && open.empty()) {
                if (!star.empty()) {
                    star.pop();
                } else {
                    return false;
                }
            }
        }
        while (!open.empty() && !star.empty()) {
            if (star.top() > open.top()) {
                star.pop();
                open.pop();
            } else {
                return false;
            }
        }

        return open.empty();
    }
};



/*
=========================================================
Problem: Valid Parenthesis String (LeetCode 678)
Topic: Greedy
Difficulty: Medium

Approach:
1. Maintain two counters:
   - low  : Minimum possible unmatched '('.
   - high : Maximum possible unmatched '('.
2. Traverse the string:
   - '('  -> low++, high++
   - ')'  -> low--, high--
   - '*'  -> low--, high++ (can act as ')', '(' or empty)
3. If high becomes negative at any point, the string cannot
   be valid.
4. Clamp low to 0 since unmatched '(' cannot be negative.
5. At the end, the string is valid only if low == 0.

Time Complexity: O(n)
Space Complexity: O(1)

=========================================================
*/

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                low++;
                high++;
            } else if (s[i] == ')') {
                low--;
                high--;
            } else {
                low--;
                high++;
            }
            if (high < 0) {
                return false;
            }
            low = max(low, 0);
        }
        return (low==0);
    }
};