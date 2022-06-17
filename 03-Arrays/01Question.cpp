// Search in a 2D Matrix

// Problem Link: https://leetcode.com/problems/search-a-2d-matrix/
// Similar Question: https://leetcode.com/problems/search-a-2d-matrix-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // TC: O(n^2)
    bool searchMatrixAppraoch1(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                if(matrix[i][j]==target){
                    return true;
                }
            }
        }
        
        return false;
    }

    bool searchMatrixAppraoch2(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i = 0; i<n; i++){
            int start = 0;
            int end = m-1;
           
            while(start<=end){
                int mid = start+(end-start)/2;
                if(matrix[i][mid]==target){
                    return true;
                }else if(matrix[i][mid]<target){
                    start=mid+1;
                }else{
                    end=mid-1;
               }
            }
        }
        
        return false;
    }
};