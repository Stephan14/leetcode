/*************************************************************************
	> File Name: q82.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  6/26 13:44:32 2017
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* top = new ListNode(-1);
        top->next = head;
     
        ListNode* quick = NULL;
        ListNode* slow = NULL;
        ListNode* pre = top;

        while(pre != NULL)
        {
            slow = pre->next;

            if(slow)
                quick = slow->next;
            else
                return top->next;

            while(quick && quick->val == slow->val)
                if(quick)
                    quick = quick->next;
            if(slow->next == quick)
                pre = slow;
            else
                pre->next = quick; 
        }

        return top->next;
    }
};
