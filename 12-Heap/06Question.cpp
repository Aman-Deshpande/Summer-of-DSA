// Top K Frequent Elements

// Problem Link: https://leetcode.com/problems/top-k-frequent-elements/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m; // ele, freq

        for(int i=0; i<n; ++i) {
            m[nums[i]]++;
        }

        priority_queue<pair<int, int>> q; // freq, ele
        for(auto &it : m) {
            q.push({it.second, it.first});
        }

        vector<int> ans;
        while(k--) {
            ans.push_back(q.top().second);
            q.pop();
        }

        return ans;
    }
};