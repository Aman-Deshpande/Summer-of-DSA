// Integer to Rome

// Problem link: https://leetcode.com/problems/integer-to-roman/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int integer[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string roman[13]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string ans = "";
        for(int i = 0; num!=0; i++){
            while(num>=integer[i]){
                ans+=roman[i];
                num-=integer[i];
            }
        }

        return ans;
    }
};
