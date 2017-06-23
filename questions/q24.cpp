/*************************************************************************
	> File Name: q24.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  6/23 09:19:03 2017
 ************************************************************************/

#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    
        ListNode* top = new ListNode(-1);
        ListNode* result = top;
        top->next = head;
        ListNode* cur = top;

        while(cur != NULL && cur->next != NULL)
        {
            ListNode* tmp = cur->next->next;

            top->next = cur->next;
            cur->next->next = cur;
            cur->next = tmp;

            top = cur;
            cur = cur->next;
        }

        return result->next;
    }
};
