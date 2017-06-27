/*************************************************************************
	> File Name: q83.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  6/27 08:30:22 2017
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
    
        ListNode* slow = head;
        ListNode* quick= NULL; 

        while(slow)
        {
            quick = slow->next;
            while(quick && quick->val == slow->val)
                quick = quick->next;
            
            if(slow->next != quick)
                slow->next = quick;
            slow = slow->next;
        }

        return head;
    }
};
