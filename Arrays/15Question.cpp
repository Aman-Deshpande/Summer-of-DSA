// Maximum Points You Can Obtain from Cards

// Problem Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

#include <bits/stdc++.h>
using namespace std;

// O(N)

class Solution
{
public:
    int maxScore(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0, j = n - k, sum = 0, totSum = 0;
        while (j < n)
        {
            sum += nums[j];
            j++;
        }

        totSum = sum;
        j = n - k;
        while (j < n)
        {
            sum -= nums[j++];
            sum += nums[i++];
            totSum = max(totSum, sum);
        }
        return totSum;
    }
};