#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
using namespace std;
/*
=========================================================
Problem: 502. IPO
Topic: Heap / Greedy / Sorting
Difficulty: Hard

Approach:
- Create a project list where each project contains:
      {capital required, profit}

- Sort all projects by the capital required.

- Maintain a max-heap containing the profits of all
  currently affordable projects.

- For each of at most `k` projects:
    1. Add every project whose required capital is <= `w`
       into the max-heap.
    2. If no project is currently affordable, stop.
    3. Select the project with the maximum profit.
    4. Add that profit to `w`.
    5. Remove the selected project from the heap.

- A pointer `j` ensures that every project is processed
  only once.

Why Greedy Works:
- At any moment, all projects in the heap are affordable.
- Choosing the project with the maximum profit gives us
  the maximum possible capital for the next selection.

Time Complexity:
- Sorting projects: O(n log n)
- Each project is inserted into the heap once: O(n log n)
- Each selected project is removed from the heap: O(k log n)
- Overall: O(n log n + k log n)

Space Complexity:
- O(n)

Key Insight:
- Sorting handles the capital requirement.
- Max-heap handles the maximum profit among all
  currently affordable projects.
- We should NOT increase `w` when adding a project to
  the heap; `w` increases only after selecting a project.

Important:
- `k` means at most `k` projects.
- If the heap is empty, no project can currently be
  completed, so we stop.

=========================================================
*/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {

        priority_queue<int> pq;

        vector<vector<int>> project;

        for (int i = 0; i < profits.size(); i++) {
            project.push_back({capital[i], profits[i]});
        }

        sort(project.begin(), project.end());

        int j = 0;

        while (k--) {

            // Add all currently affordable projects
            while (j < project.size() && project[j][0] <= w) {
                pq.push(project[j][1]);
                j++;
            }

            // No project can be completed
            if (pq.empty()) {
                break;
            }

            // Choose the project with maximum profit
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};