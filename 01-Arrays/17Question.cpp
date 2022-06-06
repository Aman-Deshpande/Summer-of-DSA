// Spiral Matrix

// Problem Link: https://leetcode.com/problems/spiral-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int rowStart = 0;
        int rowEnd = matrix.size();

        int colStart = 0;
        int colEnd = matrix[0].size();

        vector<int> ans;

        while (rowStart < rowEnd && colStart < colEnd)
        {

            // First Row
            for (int i = colStart; i < colEnd; i++)
            {
                ans.push_back(matrix[rowStart][i]);
            }

            rowStart++;

            // Last Column
            for (int i = rowStart; i < rowEnd; i++)
            {
                ans.push_back(matrix[i][colEnd - 1]);
            }

            colEnd--;

            // Last Row Reverse
            if (rowStart < rowEnd)
            {
                for (int i = colEnd - 1; i >= colStart; i--)
                {
                    ans.push_back(matrix[rowEnd - 1][i]);
                }
            }

            rowEnd--;
            if (colStart < colEnd)
            {
                for (int i = rowEnd - 1; i >= rowStart; i--)
                {
                    ans.push_back(matrix[i][colStart]);
                }
            }
            colStart++;
        }

        return ans;
    }
};
