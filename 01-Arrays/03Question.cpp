// Next Permutation

// Problem Link: https://leetcode.com/problems/next-permutation/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = -1,j;
        for(i = nums.size() - 2; i >= 0; i--) {
            if(nums[i] < nums[i+1])
                break;
        }
        if(i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for(j = nums.size() - 1; j > i; j--) {
            if(nums[j] > nums[i])
                break;
        }
        
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};