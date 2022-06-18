// Count Subarrays with Given XOR

// Problem Link: https://www.codingninjas.com/codestudio/problems/1115652?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &A, int B)
{
    //    Write your code here.
    unordered_map<int, int> visited;
    int cpx = 0;
    long long count = 0;
    for (int i = 0; i < A.size(); i++)
    {
        cpx ^= A[i];
        if (cpx == B)
        {
            count++;
        }

        int h = cpx ^ B;
        if (visited.find(h) != visited.end())
        {
            count = count + visited[h];
        }

        visited[cpx]++;
    }
    return count;
}