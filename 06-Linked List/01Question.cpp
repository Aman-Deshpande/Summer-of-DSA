//  Intersection of Two Linked Lists

// Problem Link: https://leetcode.com/problems/intersection-of-two-linked-lists/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    // Most Brute Force: TC-O(length(LL1)*length(LL2))
    ListNode *getIntersectionNodeApproach1(ListNode *headA, ListNode *headB)
    {
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;

        while (ptr2 != NULL)
        {
            ptr1 = headA;
            while (ptr1 != NULL)
            {
                if (ptr2 == ptr1)
                {
                    return ptr2;
                }
                ptr1 = ptr1->next;
            }
            ptr2 = ptr2->next;
        }

        return NULL;
    }

    // Better: TC-O(length(LL1)+length(LL2)) SC:O(N)
    ListNode *getIntersectionNodeApproach2(ListNode *headA, ListNode *headB)
    {
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;
        unordered_set<ListNode *> st;
        while (ptr1 != NULL)
        {
            st.insert(ptr1);
            ptr1 = ptr1->next;
        }

        while (ptr2 != NULL)
        {
            if (st.find(ptr2) != st.end())
            {
                return ptr2;
            }
            ptr2 = ptr2->next;
        }
        return NULL;
    }

    // Optimized1: TC-O(length(l1)+O(Length(l2)+O(diff)) SC-O(1)
    ListNode *getIntersectionNodeApproach3(ListNode *headA, ListNode *headB)
    {
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;

        int length1 = 0;
        int length2 = 0;

        while (ptr1 != NULL)
        {
            ptr1 = ptr1->next;
            length1++;
        }
        while (ptr2 != NULL)
        {
            ptr2 = ptr2->next;
            length2++;
        }

        ptr1 = headA;
        ptr2 = headB;
        if (length1 > length2)
        {
            int diff = length1 - length2;
            while (diff != 0)
            {
                ptr1 = ptr1->next;
                diff--;
            }
        }
        if (length1 < length2)
        {
            int diff = length2 - length1;
            while (diff != 0)
            {
                ptr2 = ptr2->next;
                diff--;
            }
        }

        while (ptr1 != ptr2)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return ptr1;
    }

    // Optimized 2
    ListNode *getIntersectionNodeApproach3(ListNode *headA, ListNode *headB)
    {
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;

        while (ptr1 != ptr2)
        {
            ptr1 = ptr1 == NULL ? headB : ptr1->next;
            ptr2 = ptr2 == NULL ? headA : ptr2->next;
        }

        return ptr1;
    }
};