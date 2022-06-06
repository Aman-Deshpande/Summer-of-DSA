// Move Zeroes

// Problem Link: https://leetcode.com/problems/move-zeroes/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int i = 0;
        int j = 1;
        int n = arr.size();

        while (i<n-1 && j<n)
        {
            if(arr[i]==0 && arr[j]!=0){
                swap(arr[i], arr[j]);
                i++;
                j++;
            }
            else if(arr[i]==0 && arr[j]==0){
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        
        // APPROACH 2
        // int i=0;
        // for(int k=0;k<arr.size();k++){
        //     if(arr[k]!=0){
        //         swap(arr[k],arr[i]);
        //         i++;
        //     }
        // }
    }
};