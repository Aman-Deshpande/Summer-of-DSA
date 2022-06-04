// Jump Game

// Problem Link: https://leetcode.com/problems/jump-game/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int finalDest = nums.size()-1;
        int maxReachable = 0;
        
        for(int i = 0; i<finalDest; i++){
            if(maxReachable>=i){
                maxReachable=max(maxReachable, i+nums[i]);
            }
        }
        
        return (maxReachable>=finalDest);
    }
};