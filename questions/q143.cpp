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
        
        ListNode* fast = head;
        ListNode* slow = head;

        if(head == NULL || head->next == NULL || head->next->next == NULL) 
            return head;

        while(fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        //举例测试该方法是否行得通
        ListNode* last = slow->next;
        slow->next = NULL;

        ListNode* bank = reserveList(last);
    


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
