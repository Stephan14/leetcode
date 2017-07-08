/*************************************************************************
	> File Name: q141.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  7/ 8 22:22:33 2017
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
    bool hasCycle(ListNode *head) {
    
        ListNode* quick = head;
        ListNode* slow = head;

        while(quick && quick->next != NULL && quick->next->next != NULL)
        {
            quick = quick->next->next;
            slow = slow->next;
            if(quick == slow)
                return true;
        }

        return false;
    }
};
