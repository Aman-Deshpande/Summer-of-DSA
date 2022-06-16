//  Missing Number

// Problem Link: https://leetcode.com/problems/missing-number/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumberApproach1(vector<int> &nums)
    {
        int n = nums.size();

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }

        return (n * (n + 1)) / 2 - sum;
    }

    int missingNumberApproach2(vector<int> &nums)
    {
        int n = nums.size();
        int xor1 = 0;
        int xor2 = 0;

        int i = 0;
        while (i <= n)
        {
            xor1 ^= i;
            i++;
        }

        for (int i = 0; i < n; i++)
        {
            xor2 ^= nums[i];
        }

        return xor1 ^ xor2;
    }
};