//  Set Matrix Zeroes

// Problem Link: https://leetcode.com/problems/set-matrix-zeroes/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        // finding the index of zero
        vector<pair<int, int>> storeZeroIndex;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    storeZeroIndex.push_back({i, j});
                }
            }
        }

        // marking row and col as zero
        for (int i = 0; i < storeZeroIndex.size(); i++)
        {
            int row = storeZeroIndex[i].first;
            int col = storeZeroIndex[i].second;

            int j = 0;
            // set col 0
            while (j < m)
            {
                matrix[j][col] = 0;
                j++;
            }
            j = 0;
            // set row 0
            while (j < n)
            {
                matrix[row][j] = 0;
                j++;
            }
        }
    }
};