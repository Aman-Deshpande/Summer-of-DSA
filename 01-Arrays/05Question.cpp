// Sort 0, 1, 2 : DUTCH NATIONAL FLAG Algo

// Problem Link: https://leetcode.com/problems/sort-colors/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColorsApproach1(vector<int>& arr) {
        int n = arr.size();
        int i = 0, cnt0 = 0, cnt1= 0, cnt2 = 0;
        for (i = 0; i < n; i++)
        {
            if (arr[i]==0){
                cnt0++;
            }
            else if (arr[i]==1){
                cnt1++;
            }
            else if(arr[i]==2){
                cnt2++;
            }
        }

        i=0;
        while (cnt0>0){
            arr[i++]=0;
            cnt0--;
        }
        while (cnt1>0){
            arr[i++]=1;
            cnt1--;
        }
        while (cnt2>0){
            arr[i++]=2;
            cnt2--;
        }
    }
    
    // DUTCH NATIONAL FLAG ALGORITHM
    void sortColorsApproach2(vector<int>& arr){
        int low = 0;
        int mid = 0;
        int high = arr.size()-1;
        
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }else if(arr[mid]==1){
                mid++;
            }else{
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};
