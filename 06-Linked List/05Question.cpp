// Linked List Cyle 2 - Find Starting point

// Problem Link: https://leetcode.com/problems/linked-list-cycle-ii/

#include<bits/stdc++.h>
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
    // TC: O(N) SC:O(N)
    ListNode *detectCycleApproach1(ListNode *head)
    {
        unordered_set<ListNode *> hashTable;
        ListNode *ptr = head;

        while (ptr != NULL)
        {
            if (hashTable.find(ptr) != hashTable.end())
            {
                return ptr;
            }
            hashTable.insert(ptr);
            ptr = ptr->next;
        }

        return NULL;
    }

    // TC: O(N) SC:O(1)
    ListNode *detectCycleApproach2(ListNode *head)
    {
        if(head == NULL||head->next == NULL) return NULL;
        
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* entry = head;

        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                while(slow != entry) {
                    slow = slow->next;
                    entry = entry->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};