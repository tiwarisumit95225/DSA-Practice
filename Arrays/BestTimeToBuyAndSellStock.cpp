// Problem: Best Time to Buy and Sell Stock
// Topic: Arrays
// Difficulty: Easy
// Pattern: Running Minimum
// Time Complexity: O(n)
// Space Complexity: O(1)
// Key Learning: Keep track of the smallest value seen so far.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = prices[0];
        int maxprice = 0;
        for (int i = 1; i < prices.size(); i++) {
            minprice = min(minprice, prices[i]);
            maxprice = max(maxprice, prices[i] - minprice);
        }

        return maxprice;
    }
};
