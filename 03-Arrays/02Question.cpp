//  Pow(x, n)

// Problem Link: https://leetcode.com/problems/powx-n/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        
        if(n<0){
            x=1/x;
            n=abs(n);
        }
        
        // odd
        if(n%2!=0){
            return x*myPow(x,n-1);
        }
        // even
        else{
            return myPow(x*x,n/2);
        }
    }
};