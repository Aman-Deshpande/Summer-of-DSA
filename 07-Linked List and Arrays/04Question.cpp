// Trapping Rainwater

// Problem Link: https://leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trapApproach1(vector<int> &height)
    {
        int n = height.size();
        int waterTrapped = 0;

        for (int i = 0; i < n; i++)
        {
            int j = i;
            int leftMax = 0;
            int rightMax = 0;
            while (j >= 0)
            {
                leftMax = max(leftMax, height[j]);
                j--;
            }
            j = i;
            while (j < n)
            {
                rightMax = max(rightMax, height[j]);
                j++;
            }
            waterTrapped += min(leftMax, rightMax) - height[i];
        }

        return waterTrapped;
    }

    int trapApproach2(vector<int> &arr)
    {
        int n = arr.size();
        int prefix[n], suffix[n];
        prefix[0] = arr[0];

        for (int i = 1; i < n; i++)
        {
            prefix[i] = max(prefix[i - 1], arr[i]);
        }

        suffix[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = max(suffix[i + 1], arr[i]);
        }

        int waterTrapped = 0;
        for (int i = 0; i < n; i++)
        {
            waterTrapped += min(prefix[i], suffix[i]) - arr[i];
        }
        return waterTrapped;
    }

    int trapApproach3(vector<int> &arr)
    {
        int n = arr.size();
        int prefix[n], suffix[n];
        prefix[0] = arr[0];

        for (int i = 1; i < n; i++)
        {
            prefix[i] = max(prefix[i - 1], arr[i]);
        }

        suffix[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = max(suffix[i + 1], arr[i]);
        }

        int waterTrapped = 0;
        for (int i = 0; i < n; i++)
        {
            waterTrapped += min(prefix[i], suffix[i]) - arr[i];
        }
        return waterTrapped;
    }
};