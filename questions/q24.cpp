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
    
        ListNode** pp = &head, *a , *b;
        //从后往前进行拼接链表
        while((a = *pp) && (b = a->next))
        {
            a->next = b->next;
            b->next = a;

            *pp = b;
            pp = &(a->next); 
        }

        return head;
    }
};
