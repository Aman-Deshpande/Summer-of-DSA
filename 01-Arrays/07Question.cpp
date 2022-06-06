// Chocolate Distribution Problem

// Problem link: https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1/#

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int findMinDiff(int arr[], int m, int n){

        // if no of students(m) and no chocolate packets(n) are both 0
        if(m==0 || n==0){
            return 0;
        }

        // sort the array
        sort(arr, arr+n);

        // no of students can't be greater than no of packets
        if(m>n){
            return -1;
        }

        // Largest number of chocolates
        int min_diff = INT_MAX;
    
        // Find the subarray of size m such that
        // difference between last (maximum in case
        // of sorted) and first (minimum in case of
        // sorted) elements of subarray is minimum.
    
        for (int i = 0; i + m - 1 < n; i++) {
            int diff = arr[i + m - 1] - arr[i];
            if (diff < min_diff){
                min_diff = diff;
            }
        }
        return min_diff;
    }
};
