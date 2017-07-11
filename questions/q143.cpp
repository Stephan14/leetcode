/*************************************************************************
	> File Name: q143.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  7/10 21:09:15 2017
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
    void reorderList(ListNode* head) {

        if (!head || !head->next || !head->next->next) return;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = NULL;
        ListNode *last = mid;
        ListNode *pre = NULL;
        while (last) {
            ListNode *next = last->next;
            last->next = pre;
            pre = last;
            last = next;
        }
        while (head && pre) {
            ListNode *next = head->next;
            head->next = pre;
            pre = pre->next;
            head->next->next = next;
            head = next;
        }

    }

    ListNode* reserveList(ListNode* head)
    {
        ListNode* pre = NULL;

        while(head)    
        {
            ListNode* tmp = head;
            head = head->next;
            tmp->next = pre;
            pre = tmp;
        }
        
        return pre;
    }
};
