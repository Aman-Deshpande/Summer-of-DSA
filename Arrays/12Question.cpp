// Container With Most Water

// Problem Link: https://leetcode.com/problems/container-with-most-water/

#include<bits/stdc++.h>
using namespace std;

// O(N) solution

class Solution {
public:
    int maxArea(vector<int>& heights) {        
        int start = 0;
        int end = heights.size()-1;            
        int maxWater = INT_MIN;
        int waterTrapped = 0;
        
        while(start<=end){
            int width = end-start;
            int height = min(heights[start],heights[end]); 
            
            waterTrapped = width*height;
            
            if(waterTrapped>maxWater){
                maxWater=waterTrapped;
            }
            
            if(heights[start]<heights[end]){
                start++;
            }else if(heights[start]>heights[end]){
                end--;
            }else{
                start++;
                end--;
            }
        }
        
        return maxWater;
    }
};