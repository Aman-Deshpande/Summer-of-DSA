// Pascals Triangle

// Problem Link: https://leetcode.com/problems/pascals-triangle/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        vector<int> vrow;
        
        for(int i = 0; i<numRows; i++){
            for(int j = 0; j<=i; j++){
                vrow.push_back(1);
            }
            
            vrow.resize(i+1);
            v.push_back(vrow);
        }
        
        for (int i = 1; i < numRows ; i++)
        {
            for (int j = 1; j < i; j++)
            {
                v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
            }
        }
        
        // cout<<v[4][2];
        
        return v;        
    }
};