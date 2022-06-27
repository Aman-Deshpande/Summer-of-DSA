// Median of 2 sorted arrays

// Problem Link: https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArraysApproach1(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        int finalArray[n + m];
        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                finalArray[k++] = nums1[i++];
            }
            else
            {
                finalArray[k++] = nums2[j++];
            }
        }
        if (i < m)
        {
            while (i < m)
                finalArray[k++] = nums1[i++];
        }
        if (j < n)
        {
            while (j < n)
                finalArray[k++] = nums2[j++];
        }
        n = n + m;
        if (n % 2 == 1)
            return finalArray[((n + 1) / 2) - 1];
        else
        {
            return ((float)finalArray[(n / 2) - 1] + (float)finalArray[(n / 2)]) / 2;
        }
    }

    double findMedianSortedArraysApproach2(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        if (m > n)
            return findMedianSortedArraysApproach2(nums2, nums1); // ensuring that binary search happens on minimum size array

        int low = 0, high = m, medianPos = ((m + n) + 1) / 2;
        while (low <= high)
        {
            int cut1 = (low + high) >> 1;
            int cut2 = medianPos - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1)
            {
                if ((m + n) % 2 != 0)
                    return max(l1, l2);
                else
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2)
                high = cut1 - 1;
            else
                low = cut1 + 1;
        }
        return 0.0;
    }
};