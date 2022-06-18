// Longest Consecutive Sequence

// Problem Link: https://leetcode.com/problems/longest-consecutive-sequence/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlog(n))+O(n) SC: O(1)
    int longestConsecutiveApproach1(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int ansLength = 1;
        int prev = nums[0];
        int curLength = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == prev + 1)
            {
                curLength++;
            }
            // duplicate handled
            else if (nums[i] != prev)
            {
                curLength = 1;
            }
            prev = nums[i];
            ansLength = max(ansLength, curLength);
        }
        return ansLength;
    }

    int longestConsecutiveApproach2(vector<int> &nums)
    {
        set<int> hashSet;
        for (int num : nums)
        {
            hashSet.insert(num);
        }

        int longestStreak = 0;

        for (int num : nums)
        {
            if (!hashSet.count(num - 1))
            {
                int currentNum = num;
                int currentStreak = 1;

                while (hashSet.count(currentNum + 1))
                {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};