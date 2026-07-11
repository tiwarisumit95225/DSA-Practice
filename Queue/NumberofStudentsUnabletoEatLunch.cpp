/*
=========================================================
Problem: Number of Students Unable to Eat Lunch (LeetCode 1700)
Topic: Queue
Difficulty: Easy

Approach:
1. Store all students in a queue.
2. Store sandwiches in a stack by pushing them in reverse
   order so the top represents the current sandwich.
3. If the front student's preference matches the current
   sandwich, remove both from the queue and stack.
4. Otherwise, move the student to the back of the queue.
5. Keep track of consecutive rotations. If every remaining
   student refuses the current sandwich, stop the process.

Time Complexity:
- O(n²) (Worst Case)

Space Complexity:
- O(n)

Key Insight:
- Simulate the queue exactly as described.
- Reset the rotation counter whenever a student eats.
- If all remaining students refuse the current sandwich,
  no further progress is possible.

=========================================================
*/

#include <iostream>
#include <stack>
#include<queue>
#include <vector>
using namespace std;
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
    
        stack<int>st;
        queue<int>q;
        int rotation=0;
        int count =0;
        for(int i=0;i<students.size();i++){
            q.push(students[i]);
        }
        for(int i=sandwiches.size()-1;i>=0;i--){
            st.push(sandwiches[i]);
        }

        while(!q.empty()&& !st.empty()){
            if(q.front()==st.top()){
                count++;
                rotation = 0;
                q.pop();st.pop();
            }
            else {
                q.push(q.front());
                q.pop();
                rotation++;
                if(rotation==q.size()){
                    break;
                }
            }
        }
        return students.size()-count;
    }
};

/*
=========================================================
Problem: Number of Students Unable to Eat Lunch (LeetCode 1700)
Topic: Queue
Difficulty: Easy

Approach:
1. Count the number of students preferring sandwich type
   0 and type 1.
2. Traverse the sandwiches from top to bottom.
3. If the current sandwich is 0 and no student prefers 0,
   stop the process.
4. If the current sandwich is 1 and no student prefers 1,
   stop the process.
5. Otherwise, decrement the corresponding preference count.
6. Return the number of remaining students.

Time Complexity:
- O(n)

Space Complexity:
- O(1)

Key Insight:
- The order of students is irrelevant.
- Only the count of each preference matters.
- If no student prefers the current sandwich, rotating the
  queue cannot change the outcome.

=========================================================
*/
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int one = 0;
        int zero = 0;
        for (int i = 0; i < students.size(); i++) {
            if (students[i] == 0) {
                zero++;
            } else {
                one++;
            }
        }

        for (int i = 0; i < sandwiches.size(); i++) {
            if (sandwiches[i] == 0) {
                if(zero==0){
                    break;
                }
                zero--;
            } else {
                if(one==0){
                    break;
                }
                one--;
            }
        }
        return one+zero;
    }
};