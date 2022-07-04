// Implement stack using Queue

// Problem Link: https://leetcode.com/problems/implement-stack-using-queues/

#include <bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int q[100];
    int qtop = -1;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q[++qtop] = x;
    }

    int pop()
    {
        int a = q[qtop--];
        return a;
    }

    int top()
    {
        return q[qtop];
    }

    bool empty()
    {
        return qtop == -1 ? true : false;
    }
};