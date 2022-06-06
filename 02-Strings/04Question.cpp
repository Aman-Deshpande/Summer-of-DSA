// Longest Common Prefix

// Problem Link: https://leetcode.com/problems/longest-common-prefix/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        sort(arr.begin(), arr.end());
        
        string start = arr[0], end = arr[arr.size()-1], pre = "";
        
        int i=0,j=0;
        
        while(i<start.size() && j<end.size() && start[i] == end[j]){
            ++i; 
            ++j;
        }
        
        return start.substr(0,i);
    }
};