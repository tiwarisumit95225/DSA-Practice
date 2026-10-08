#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
/*
=========================================================
Problem: 630. Course Schedule III
Topic: Heap / Greedy / Sorting
Difficulty: Hard

Approach:
- Each course is represented as:
      [duration, deadline]

- Sort all courses by their deadline in ascending order.

- Maintain:
      currtime = total duration of selected courses
      max-heap = durations of selected courses

- For every course:
    1. If the course can be completed before its deadline,
       select it and add its duration to the heap.

    2. Otherwise, check whether the current course is shorter
       than the longest course we have already selected.

    3. If it is shorter:
         - Remove the longest selected course.
         - Add the current course.
         - Update currtime.

- The replacement is useful because removing the longest
  course gives us the maximum amount of time back while
  keeping the same number of selected courses.

Why Greedy Works:
- Courses are processed in deadline order.
- If the current schedule exceeds a deadline, keeping a
  shorter course is always better than keeping a longer one.
- Therefore, we use a max-heap to efficiently find and
  remove the longest selected course.

Time Complexity:
- Sorting: O(n log n)
- Heap operations: O(log n)
- Overall: O(n log n)

Space Complexity:
- O(n)

Key Insight:
- Sort by deadline.
- Use a max-heap to keep track of selected course durations.
- When a course doesn't fit, replace the longest selected
  course if the current course is shorter.

Example:
    courses = [[100,200], [200,1300], [1000,1250],
               [2000,3200]]

After sorting by deadline:
    [[100,200], [1000,1250], [200,1300], [2000,3200]]

The max-heap allows us to remove the longest course whenever
the current schedule becomes invalid.

=========================================================
*/

class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {

        // Max-heap storing durations of selected courses
        priority_queue<int> pq;

        // Sort courses by deadline
        sort(courses.begin(), courses.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 return a[1] < b[1];
             });

        int currtime = 0;

        for (int i = 0; i < courses.size(); i++)
        {

            // If the course can be completed before its deadline
            if (currtime + courses[i][0] <= courses[i][1])
            {

                currtime += courses[i][0];
                pq.push(courses[i][0]);
            }
            else
            {

                // Replace the longest selected course
                // if the current course is shorter
                if (!pq.empty() && courses[i][0] < pq.top())
                {

                    currtime =
                        currtime - pq.top() + courses[i][0];

                    pq.pop();
                    pq.push(courses[i][0]);
                }
            }
        }

        return pq.size();
    }
};