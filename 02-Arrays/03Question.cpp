// Merge Sorted Arrays

// Problem Link: https://leetcode.com/problems/merge-sorted-array/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = n+m-1;
        int i=m-1,j=n-1;
        
        while(j>=0)
        {
            if(i>=0 && nums1[i]>=nums2[j])
                nums1[k--]=nums1[i--];
            else
                nums1[k--]=nums2[j--];
        }
    }
};