// Rotate Matrix

// Problem Link: https://leetcode.com/problems/rotate-image/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Transpose - O(n^2)
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Reversing - O(n^2)
        for(int i = 0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};