/*
Problem: Asteroid Collision (LeetCode 735)
Topic: Stack
Difficulty: Medium

Approach:
- Use a stack to store surviving asteroids.
- Push all positive asteroids directly into the stack.
- For a negative asteroid, repeatedly check collisions with the top positive asteroid.
- If the top asteroid is larger, the current asteroid is destroyed.
- If the current asteroid is larger, pop the top asteroid and continue checking.
- If both are equal, destroy both asteroids.
- If the current asteroid survives all possible collisions, push it onto the stack.
- Convert the stack to a vector and reverse it to obtain the final answer.

Time Complexity: O(n)
Space Complexity: O(n)

Key Learning:
- Use a single stack to simulate collisions.
- A while loop is required because one asteroid can collide with multiple asteroids.
- Even with a nested while loop, the complexity is O(n) because each asteroid is pushed and popped at most once (amortized analysis).
*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            int asteroid = asteroids[i];
            bool alive = true;
            if (asteroid > 0) {
                st.push(asteroid);
            } else {
                while (!st.empty() && st.top() > 0 && asteroid < 0) {
                    if (st.top() > abs(asteroid)) {
                        alive = false;
                        break;
                    } else if (st.top() < abs(asteroid)) {
                        st.pop();

                    } else {

                        st.pop();
                        alive = false;
                        break;
                    }
                }
                if (alive) {
                    st.push(asteroid);
                }
            }
        }
        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        int i = 0;
        int j = result.size() - 1;
        while (i < j) {
            swap(result[i], result[j]);
            i++;
            j--;
        }
        return result;
    }
};
