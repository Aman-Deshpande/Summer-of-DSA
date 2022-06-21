// Remove Duplicates from Sorted Array

// Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    // TC:O(N) SC:O(N)
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        for(int i = 0; i<nums.size(); i++){
            if(nums[k-1]!=nums[i]){
                swap(nums[i], nums[k]);
                k++;
            }
        }
        return k;
    }
};