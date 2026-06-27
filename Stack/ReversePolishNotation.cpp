#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
Problem: Evaluate Reverse Polish Notation (LeetCode 150)

Topic:
- Stack

Difficulty:
- Medium

Approach:
- Traverse the tokens.
- Push numbers onto the stack.
- When an operator is encountered, pop the top two operands,
  perform the operation in the correct order, and push the result back.
- The remaining element in the stack is the final answer.

Time Complexity: O(n)

Space Complexity: O(n)

Key Learning:
- Learned how Reverse Polish Notation (Postfix Expression) works.
- Practiced using stack for expression evaluation.
- Understood why operand order matters for subtraction and division.
- Learned to convert strings to integers using stoi().
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
             string token=tokens[i];
            int result;
            if (token == "+" || token == "-" || token == "*" ||
                token == "/") {
                int b = st.top();
                st.pop();
                int c = st.top();
                st.pop();
                if (token == "+") {
                    result = c + b;
                    st.push(result);
                } else if (token == "-") {
                    result = c - b;
                    st.push(result);
                } else if (token == "*") {
                    result = c * b;
                    st.push(result);
                } else{
                    result = c / b;
                    st.push(result);
                }

            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
