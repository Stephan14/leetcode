/*************************************************************************
	> File Name: q86.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  6/27 08:58:43 2017
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
    ListNode* partition(ListNode* head, int x) {
    
        ListNode* first = new ListNode(-1);
        first->next = head;

        ListNode* pre = first;
        ListNode* cur = head;
        ListNode* low = first;

        while(cur)
        {
            if(cur->val < x)
            {
                pre->next = cur->next;
                //从后往前连接链表
                cur->next = low->next;
                low->next = cur;
                low = low->next;
            }
            pre = cur;
            cur = cur->next;
        }

        return first->next;
    }
};
