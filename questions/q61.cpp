/*************************************************************************
	> File Name: q61.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  6/25 16:22:41 2017
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
    ListNode* rotateRight(ListNode* head, int k) {
    
        if(head == NULL || k == 0)
            return head;

        ListNode* current = head;
        int num = 0;
        while(current != NULL)
        {
            num++;
            current = current->next;
        }
        k = k % num;

        ListNode* first = head;
        for(int i = 0; i < k; i++)
            if(first)
                first = first->next;

        if(first == NULL)
            return head;

        ListNode* second = head;
        while(first->next)
        {
            second = second->next;
            first = first->next;
        }

        //从后往前设置链表
        first->next = head;
        first = second->next;
        second->next = NULL;

        return first;
    }
};
