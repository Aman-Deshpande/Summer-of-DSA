// Search in Rotated Sorted Array

// Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &a, int k)
    {
        int l = 0, r = a.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (a[mid] == k)
            {
                return mid;
            }

            if (a[l] <= a[mid])
            {
                if (k >= a[l] && k < a[mid])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                if (k > a[mid] && k <= a[r])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};