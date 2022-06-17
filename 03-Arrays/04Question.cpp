// Majority Element II

// https://leetcode.com/problems/majority-element-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElementAppraoch1(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        for (auto i : mp)
        {
            if (i.second > nums.size() / 3)
            {
                ans.push_back(i.first);
            }
        }

        return ans;
    }

    // MODIFIED MOORE VOTING ALGORITHM
    vector<int> majorityElementAppraoch2(vector<int> &nums)
    {
        int sz = nums.size();
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;

        for (i = 0; i < sz; i++)
        {
            if (nums[i] == num1)
                count1++;
            else if (nums[i] == num2)
                count2++;
            else if (count1 == 0)
            {
                num1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0)
            {
                num2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        vector<int> ans;
        count1 = count2 = 0;
        for (i = 0; i < sz; i++)
        {
            if (nums[i] == num1)
                count1++;
            else if (nums[i] == num2)
                count2++;
        }
        if (count1 > sz / 3)
            ans.push_back(num1);
        if (count2 > sz / 3)
            ans.push_back(num2);

        return ans;
    }
};