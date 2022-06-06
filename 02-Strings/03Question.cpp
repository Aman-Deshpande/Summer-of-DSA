// Implement strStr()

// Problem LinK: https://leetcode.com/problems/implement-strstr/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int nlength = needle.length();
        if(nlength==0) return 0;
        else if(haystack.length()>=nlength){
            for(int i=0;i<=haystack.length()-nlength;i++){
                if(haystack.substr(i,nlength)==needle) {
                    return i;
                }
            }
        }
        return -1;
    }
};