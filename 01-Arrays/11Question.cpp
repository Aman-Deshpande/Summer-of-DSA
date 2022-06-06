// Find All Duplicates in an Array

// Problem Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/

#include<bits/stdc++.h>
using namespace std;

// O(N) solution - Cylic Sort is used

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        cyclicSort(nums);
        vector<int> ans;
        
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]!=i+1){
                ans.push_back(nums[i]);
            }
        }
        
        return ans;
    }
    
    void cyclicSort(vector<int> &nums){
        int i = 0;
        while(i<nums.size()){
            int correct = nums[i]-1;
            if(nums[i]!=nums[correct]){
                swap(nums[i], nums[correct]);
            }else{
                i++;
            }
        }
    }
};
