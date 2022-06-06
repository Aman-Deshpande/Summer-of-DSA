// Subarray Sums Divisible by K

// Problem link: https://leetcode.com/problems/subarray-sums-divisible-by-k/

#include<bits/stdc++.h>
using namespace std;

// TC: O(N)  SC: O(N)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;
        unordered_map<int, int> map;
        
        map[sum] = 1; // mapping 0 -> 1 because 0 sum has already occured at beggining
        
        for(int i = 0; i<nums.size(); i++){
            sum+=nums[i];
            int rem = sum%k;
            
            // to handle edge case i.e negative remainder
            if(rem<0){
                rem+=k;
            }
            
            if(map.find(rem)!=map.end()){
                count+=map[rem];
            }
            map[rem]++;
        }
        
        return count;
    }
};
