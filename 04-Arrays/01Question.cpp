//  Two Sum

// Problem Link: https://leetcode.com/problems/two-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2)
    vector<int> twoSumApproach1(vector<int> &nums, int target)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }

        return ans;
    }

    // TC: O(N) SC: O(N)
    vector<int> twoSumApproach2(vector<int> &nums, int target)
    {
        vector<int> ans;
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++)
        {
            int ele = nums[i];
            int diff = target - ele;

            if (map.find(diff) != map.end())
            {
                ans.push_back(i);
                ans.push_back(map[diff]);
                return ans;
            }

            map[nums[i]] = i;
        }

        return ans;
    }
};