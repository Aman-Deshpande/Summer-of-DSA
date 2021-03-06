// 4 Sum

// Problem Link: https://leetcode.com/problems/4sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(n^3)*O(log(n)) SC: O(n)
    vector<vector<int>> fourSumApproach1(vector<int>& nums, int target) {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
      
        set<vector<int>> sv;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){ 
                   int x = (long long)target - (long long)nums[i]-(long long)nums[j]-(long long)nums[k];
                        
                    // binary search function in c++
                        if(binary_search(nums.begin()+k+1,nums.end(),x)){
                            vector<int> v;
                            v.push_back(nums[i]);
                            v.push_back(nums[j]);
                            v.push_back(nums[k]);
                            v.push_back(x);
                            sort(v.begin(),v.end());
                            sv.insert(v);
                        }
                }
            }
        }
        vector<vector<int>> res(sv.begin(),sv.end());
        
        return res;
    }

    // TC: O(n^2)*O(Logn) + O(nlog(n)) // SC: O(1)
    vector<vector<int>> fourSumApproach2(vector<int>& num, int target) {
        vector<vector<int> > res;
        
        if (num.empty())
            return res;
        int n = num.size(); 
        sort(num.begin(),num.end());
    
        for (int i = 0; i < n; i++) {
        
            int target_3 = target - num[i];
        
            for (int j = i + 1; j < n; j++) {
            
                int target_2 = target_3 - num[j];
            
                int front = j + 1;
                int back = n - 1;
            
                while(front < back) {
                
                    int two_sum = num[front] + num[back];
                
                    if (two_sum < target_2) front++;
                
                    else if (two_sum > target_2) back--;
                
                    else {
                    
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = num[i];
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[front];
                        quadruplet[3] = num[back];
                        res.push_back(quadruplet);
                    
                        // Processing the duplicates of number 3
                        while (front < back && num[front] == quadruplet[2]) ++front;
                    
                        // Processing the duplicates of number 4
                        while (front < back && num[back] == quadruplet[3]) --back;
                
                    }
                }
                
                // Processing the duplicates of number 2
                while(j + 1 < n && num[j + 1] == num[j]) ++j;
            }
        
            // Processing the duplicates of number 1
            while (i + 1 < n && num[i + 1] == num[i]) ++i;
        
        }
    
        return res;
    }
};