/*
-------------------------------------------------------
Problem: 350. Intersection of Two Arrays II
Topic: HashMap
Difficulty: Easy
Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/

Approach:
- Store the frequency of elements from the smaller array using an unordered_map.
- Traverse the second array.
- If an element exists with a positive frequency, add it to the answer.
- Decrement its frequency after adding to avoid extra occurrences.
- Swapping arrays ensures the HashMap is built using the smaller array, reducing space usage.

Time Complexity: O(n + m)
Space Complexity: O(min(n, m))

Key Learning:
- Use unordered_map when duplicate occurrences need to be tracked.
- Frequency counting is a common HashMap technique.
- Optimizing by choosing the smaller array can reduce memory usage.
-------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
         if(nums1.size()>nums2.size()){
            swap(nums1,nums2);
         }

         unordered_map<int,int>common;
         vector<int>ans;
         for(int a :nums1){
            common[a]++;
         }

         for(int b :nums2){
            if(common[b]>0){
                ans.push_back(b);
                --common[b];
                
            }
            

         }
         return ans;

    }
};


/*
-------------------------------------------------------
Problem: 350. Intersection of Two Arrays II
Topic: Sorting, Two Pointers
Difficulty: Easy
Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/

Approach:
- Sort both input arrays.
- Use two pointers to traverse the arrays simultaneously.
- If both elements are equal, add the element to the answer and move both pointers.
- If one element is smaller, move its corresponding pointer.
- Continue until one of the arrays is fully traversed.

Time Complexity: O(n log n + m log m)
Space Complexity: O(1) (excluding the output array)

Key Learning:
- Two pointers are an efficient technique for sorted arrays.
- Sorting can eliminate the need for extra data structures like HashMaps.
- This approach is useful when memory usage is a concern or when arrays are already sorted.
-------------------------------------------------------
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
         if(nums1.size()>nums2.size()){
            swap(nums1,nums2);
         }
         sort(nums1.begin(),nums1.end());
         sort(nums2.begin(),nums2.end());
           vector<int>ans;
           int i=0,j=0;
           while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]<nums2[j]){
                i++;
            }else if(nums1[i]>nums2[j]){
                j++;
            }else{
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
           }
        
return ans;
    }
};