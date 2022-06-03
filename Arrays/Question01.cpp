//  Find the Duplicate Number

// Problem Link: https://leetcode.com/problems/find-the-duplicate-number/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int i = 0;
        while (i < nums.size())
        {
            if (i + 1 == nums[i])
            {
                i++;
            }
            else if (nums[i] == nums[nums[i] - 1])
            {
                return nums[i];
            }
            else
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        return 0;
    }
};

// USING FAST AND SLOW POINTER
//         int slow = 0;
//         int fast = 0;
//         do{
//             slow = nums[slow];
//             fast = nums[nums[fast]];
//         }while(fast!=slow);

//         slow = 0;
//         while (slow != fast) {
//             slow = nums[slow];
//             fast = nums[fast];
//         }

//         return slow;