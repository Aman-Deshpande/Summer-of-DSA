// Combination Sum

// Problem Link: https://leetcode.com/problems/combination-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void sum(vector<int> &nums, int target, int idx, vector<int> &v, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(v);
            return;
        }
        else if (target < 0)
        {
            return;
        }
        else if (idx >= nums.size())
        {
            return;
        }

        v.push_back(nums[idx]);
        sum(nums, target - nums[idx], idx, v, ans);

        v.pop_back();
        sum(nums, target, idx + 1, v, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> v;
        vector<vector<int>> ans;

        sum(candidates, target, 0, v, ans);

        return ans;
    }
};