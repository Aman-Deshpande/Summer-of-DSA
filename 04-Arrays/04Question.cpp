// Largest subarray with 0 sum

// Problem Link: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // TC-O(N) SC-O(N)
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int> map;
        int prefixSum = 0, ans=0;
        map[prefixSum]=-1; // sum is 0 til -1 index
        
        for(int i = 0; i<n; i++){
            prefixSum+=A[i];
            if(map.find(prefixSum)!=map.end()){
                int temp = i-map[prefixSum];
                ans=max(ans, temp);
            }else{
                map[prefixSum]=i;
            }
        }
        
        return ans;
    }
};