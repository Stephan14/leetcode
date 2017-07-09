/*************************************************************************
	> File Name: q142.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  7/ 9 22:07:52 2017
 ************************************************************************/

#include<iostream>
#include<map>

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
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) 
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        
        if(!fast || !fast->next) return NULL;
        slow = head;
        while(slow != fast) 
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
