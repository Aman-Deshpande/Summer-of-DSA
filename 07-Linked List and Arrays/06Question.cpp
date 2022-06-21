// Max Consecutive Ones

// Problem Link: https://leetcode.com/problems/max-consecutive-ones/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC: O(N)  SC: O(1)
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones = 0;
        int finalCount = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==1) ones++;
            if(nums[i]!=1){
                ones=0;
            }
            finalCount = max(ones, finalCount);
        }
        
        return finalCount;
    }
};