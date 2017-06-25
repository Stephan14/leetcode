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
    
        ListNode* first = head;
        for(int i = 0; i < k; i++)
            first = first->next;

        if(first == NULL)
            return head;

        ListNode* second = head;
        while(!first->next)
        {
            second = second->next;
            first = first->next;
        }

        second = second->next;
        first->next = head;

        return second;
    }
};
