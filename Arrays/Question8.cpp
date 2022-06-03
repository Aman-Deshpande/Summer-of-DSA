// Two Sum

// Problem Link: https://leetcode.com/problems/two-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // TC = O(N^2) and
    // SC = O(1) {just using ans vector to store index of two elements, if we ignore that}
    vector<int> approach1(vector<int>& nums, int target) {
        vector<int> ans;
        
        for(int i = 0; i<nums.size()-1; i++){
            for(int j = i+1; j<nums.size(); j++){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        
        return ans;
    }

    // 2nd solution: using Hashmap
    // Tc = O(N) {for looping over elements}
    // Sc = O(N) {for storing index of every element in the map}
    
    vector<int> approach2(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        vector<int> ans;
        int n = nums.size();
        
        //store (element, index) in map
        for(int i=0; i<n; i++){
            mpp[nums[i]] = i;
        }
        
        //find k = (target - nums[i]) in map.
        for(int i=0; i<n; i++){
            int k = target- nums[i];  //9-2 = 7 = k
            
            if(mpp.find(k) != mpp.end()){
                if(i==mpp[k]) {
                    continue; //skip if taking same index twice
                }
                ans.push_back(i);    //index of 1st element i
                ans.push_back(mpp[k]);  //index of 2nd element k
                break;
            }
        }
        
        return ans;
    }

};