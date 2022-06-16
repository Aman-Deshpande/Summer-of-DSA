// Merge Intervals

// Problem Link: https://leetcode.com/problems/merge-intervals/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        
        sort(intervals.begin(), intervals.end());
        
        ans.push_back(intervals[0]);
        
        int j = 0;
        for(int i = 1; i<intervals.size(); i++){
            if(ans[j][1]>=intervals[i][0]){
                ans[j][1]=max(ans[j][1], intervals[i][1]);
            }else{
                j++;
                ans.push_back(intervals[i]);
            }
        }
        
        return ans;
    }
};