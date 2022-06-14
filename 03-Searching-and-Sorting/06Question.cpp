// Product of Array Except Self

// Problem Link: https://leetcode.com/problems/product-of-array-except-self/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(sizeof(nums),1); // answer array of size=nums, all elements=1
        int prodFromEnd = 1;
        int prodFromStart = 1;
        int n = sizeof(nums);
        
        for(int i = 0; i < n; i++) {
            ans[i] = ans[i]*prodFromStart;           
            prodFromStart = prodFromStart*nums[i];			
            ans[n-1-i] = ans[n-1-i]*prodFromEnd;         
            prodFromEnd = prodFromEnd*nums[n-1-i];
        }
        return ans;
    }
};
