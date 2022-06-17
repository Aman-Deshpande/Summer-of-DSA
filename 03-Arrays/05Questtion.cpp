// Unique Paths

// Problem Link: https://leetcode.com/problems/unique-paths/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Recursive Solution: TLE
    private:
    int totalPathsApproach1(int m, int n, int currRow, int currCol){
        if(currRow==m-1 && currCol==n-1){
            return 1;
        }
        if(currRow>=m || currCol>=n){
            return 0;
        }
        
        int right = totalPathsApproach1(m, n, currRow, currCol+1);
        int down = totalPathsApproach1(m, n, currRow+1, currCol);
        
        return right+down;
    }

    // Memoized DP Solution: TC-O(n*m) SC-O(n*m)
    int totalPathsApproach2(int m, int n, int currRow, int currCol, vector<vector<int>> &dp){
        if(currRow==m-1 && currCol==n-1){
            return 1;
        }
        if(currRow>=m || currCol>=n){
            return 0;
        }
        
        if(dp[currRow][currCol]!=-1){
            return dp[currRow][currCol];
        }
        
        int right = totalPathsApproach2(m, n, currRow, currCol+1, dp);
        int down = totalPathsApproach2(m, n, currRow+1, currCol, dp);
        
        return dp[currRow][currCol] = right+down;
    }
public:
    int uniquePathsApproach1(int m, int n) {
        return totalPathsApproach1(m, n, 0, 0);
    }

    // Most Optimal Combinatrics Solution - TC: O(N-1) or O(M-1) SC:O(1)
    int uniquePathsApproach3(int m, int n) {
        int N = n + m - 2;
        int r = m - 1; 
        double res = 1;
            
        for (int i = 1; i <= r; i++)
            res = res * (N - r + i) / i;
        
        return (int)res;
    }
};