// Subsets II

// Problem Link: https://leetcode.com/problems/subsets-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void fun(vector<int> &nums, int index, vector<int> ds, set<vector<int>> &res)
    {
        if (index == nums.size())
        {
            sort(ds.begin(), ds.end());
            res.insert(ds);
            return;
        }

        ds.push_back(nums[index]);
        fun(nums, index + 1, ds, res);

        ds.pop_back();
        fun(nums, index + 1, ds, res);
    }

    vector<vector<int>> helperApproach1(vector<int> &nums)
    {
        vector<vector<int>> ans;
        set<vector<int>> res;
        vector<int> ds;
        fun(nums, 0, ds, res); // to find all subsets
        for (auto it = res.begin(); it != res.end(); it++)
        {
            ans.push_back(*it);
        }
        return ans;
    }

    void findSubsetApproach2(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
    {
        ans.push_back(ds);
        for (int i = ind; i < nums.size(); i++)
        {
            if (i != ind && nums[i] == nums[i - 1])
            {
                continue;
            }
            ds.push_back(nums[i]);

            findSubsetApproach2(i + 1, nums, ds, ans);

            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans = helperApproach1(nums);
        return ans;
    }
};