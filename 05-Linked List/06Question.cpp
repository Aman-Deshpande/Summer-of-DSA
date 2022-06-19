// Delete Node in a Linked List

// Problem Link: https://leetcode.com/problems/delete-node-in-a-linked-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        swap(node->val,node->next->val); // just the values are swapped
        ListNode* temp = node->next;
        node->next=node->next->next; // point node->next to node->next->next
        delete(temp);
    }
};