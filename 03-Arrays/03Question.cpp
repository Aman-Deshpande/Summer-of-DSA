// Majority Element (> N/2 times)

// Problem Link: https://leetcode.com/problems/majority-element/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int majorityElementApproach1(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }

    int majorityElementApproach2(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        
        for(auto i: mp){
            if(i.second > nums.size()/2){
                return i.first;
            }
        }
        
        return -1;
    }

    // MOORE VOTING ALGORITHM
    int majorityElementApproach3(vector<int> &nums)
    {
        int occurence = 0;
        int majority = 0;
        
        for(int i = 0; i<nums.size(); i++){
            if(occurence==0){
                majority=nums[i];
                occurence++;
            }else if(nums[i]!=majority){
                occurence--;
            }else if(nums[i]==majority){
                occurence++;
            }
        }
        
        return majority;
    }
};