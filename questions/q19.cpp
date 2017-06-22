/*************************************************************************
	> File Name: q19.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  6/22 09:15:47 2017
 ************************************************************************/

#include<iostream>
#include<stack>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        stack<ListNode*> s;
        ListNode* top = head;
        ListNode* cur = NULL;

        while(top != NULL)
        {
            s.push(top);
            top = top->next;
        }

        while(!s.empty())
        {
            cur = s.top();
            s.pop();
            n--;
            if(n == 0)
                if(s.empty())
                    return cur->next;
                else
                    s.top()->next = cur->next;
        }

        return head;
    }
};

