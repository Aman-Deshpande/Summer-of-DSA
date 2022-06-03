// Subarray Sum Equals K - Similar to question 10

// Problem Link: https://leetcode.com/problems/subarray-sum-equals-k/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        
        unordered_map<int, int> map;
        
        map[sum]=1;
        
        for(int i = 0; i<nums.size(); i++){
            sum+=nums[i];
            
            if(map.find(sum-k)!=map.end()){
                count+=map[sum-k];
            }
            map[sum]++;
        }
        
        return count;
    }
};