/*
=========================================================
Problem: Happy Number (LeetCode 202)
Topic: HashSet (Cycle Detection)
Difficulty: Easy

Approach:
1. Create a helper function to calculate the sum of the squares
   of the digits of a number.
2. Use an unordered_set to store every number generated.
3. Repeatedly replace the number with the sum of the squares
   of its digits.
4. If the number becomes 1, return true.
5. If the number is seen again, a cycle exists, so return false.

Time Complexity: O(log n)
Space Complexity: O(log n) (O(1) in practice due to bounded states)

Key Learning:
- Use HashSet to detect cycles.
- Store previously visited states to avoid infinite loops.
- Extract digits using '%' and remove digits using '/'.
=========================================================
*/
#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int getnext(int n) {
       
        int sum = 0;
        while (n > 0) {
           int num = n % 10;
            sum += num * num;
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {

        unordered_set<int> seen;
        while (n != 1) {
            if (seen.count(n)) {
                return false;
            }
            seen.insert(n);
            n = getnext(n);
        }
        return true;
    }
};