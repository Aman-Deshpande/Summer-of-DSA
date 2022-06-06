//  Majority Element

// Question link: https://leetcode.com/problems/majority-element/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // return nums[nums.size()/2];
        
        // BOORE VOTING ALGORITHM
        int majority = 0;
        int occurence = 0;
        
        for(int i = 0; i<nums.size(); i++){
            if(occurence==0){
                majority=nums[i];
                occurence++;
            }else if(nums[i]==majority){
                occurence++;
            }else{
                occurence--;
            }
        }
        
        return majority;
    }
};