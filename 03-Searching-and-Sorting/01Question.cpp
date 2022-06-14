// Permute two arrays such that sum of every pair is greater or equal to K

// Problem Link: https://www.geeksforgeeks.org/permute-two-arrays-sum-every-pair-greater-equal-k/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPossible(long long a[], long long b[], long long n, long long k) {
        // Your code goes here
        
        // sort a in ascending order
        sort(a, a+n);
        
        // sort b in descending order
        sort(b, b+n, greater<int>());
        
        bool ans;
        for(int i = 0; i<n; i++){
            ans = false;
            if(a[i]+b[i]>=k){
                ans=true;   
            }
        }
        
        return ans;
    }
};