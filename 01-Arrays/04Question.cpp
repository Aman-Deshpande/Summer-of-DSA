// Maximum Subarray Sum : KADANE's Algorithm

// Problem Link: https://leetcode.com/problems/maximum-subarray/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int sum = 0;
        int maxi = arr[0];
        
        for(int i = 0; i<arr.size(); i++){
            sum+=arr[i];
            maxi = max(sum, maxi);
            if(sum<0){
                sum = 0;
            }            
        }
        
        return maxi;
    }
};