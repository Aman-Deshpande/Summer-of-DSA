// Next Greater Element

// PRoblem Link: https://leetcode.com/problems/next-greater-element-i/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp;
        stack<int> st;
        int n2 = nums2.size();
        vector<int> ans;

        for (int i = n2 - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() < nums2[i])
                st.pop();

            if (st.empty())
            {
                mp[nums2[i]] = -1;
            }
            else
            {
                mp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        for (auto i : nums1)
        {
            ans.push_back(mp[i]);
        }

        return ans;
    }
};