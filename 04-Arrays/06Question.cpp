//  Longest Substring Without Repeating Characters

// Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstringAppraoch1(string str)
    {
        int maxans = INT_MIN;
        for (int i = 0; i < str.length(); i++) // outer loop for traversing the string
        {
            unordered_set<int> set;
            for (int j = i; j < str.length(); j++) // nested loop for getting different string starting with str[i]
            {
                if (set.find(str[j]) != set.end()) // if element if found so mark it as ans and break from the loop
                {
                    maxans = max(maxans, j - i);
                    break;
                }
                set.insert(str[j]);
            }
        }
        return maxans;
    }

    int lengthOfLongestSubstringAppraoch2(string s)
    {
        int ans = 0;
        int left = 0;

        unordered_map<char, int> map;

        for (int i = 0; i < s.length(); i++)
        {
            char curr = s[i];

            if (map.find(curr) != map.end() && map[curr] >= left)
            {
                left = map[curr] + 1;
            }

            int len = i - left + 1;
            map[curr] = i;
            ans = max(ans, len);
        }
        return ans;
    }
};