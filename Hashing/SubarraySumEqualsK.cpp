/*
=========================================================
Problem: Subarray Sum Equals K (LeetCode 560)
Topic: HashMap + Prefix Sum
Difficulty: Medium

Approach:
1. Use an unordered_map to store the frequency of prefix sums.
2. Initialize the map with {0 : 1} to handle subarrays starting from index 0.
3. Traverse the array while maintaining a running prefix sum.
4. For each element:
   - Update the current prefix sum.
   - Check if (prefixSum - k) exists in the map.
   - If it exists, add its frequency to the answer.
   - Store the current prefix sum in the map.
5. Return the total count of valid subarrays.

Time Complexity: O(n)
Space Complexity: O(n)

Key Concept:
Current Prefix Sum - Previous Prefix Sum = k
=> Previous Prefix Sum = Current Prefix Sum - k

=========================================================
*/
#include<iostream>
#include <vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.count(sum-k)){
                count+=mp[sum-k];
              
            }
              mp[sum]++;
        }
        return count;
    }
};