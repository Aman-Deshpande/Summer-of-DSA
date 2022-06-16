// Find the duplicate in an array of N+1 integers.

// Problem Link: https://leetcode.com/problems/find-the-duplicate-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC: O(N)  SC:O(1)
    int findDuplicateAppraoch1(vector<int>& nums) {
        int i = 0;
        while(i<nums.size()){
            if(nums[i]==i+1){
                i++;
            }else if(nums[i]==nums[nums[i]-1]){
                return nums[i];
            }else{
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        
        return -1;
    }

    // TC: O(N)  SC:O(1) -> LINKED LIST CYCLE METHOD
    int findDuplicateAppraoch2(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};