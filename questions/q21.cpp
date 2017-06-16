/*************************************************************************
	> File Name: q21.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  6/16 16:29:44 2017
 ************************************************************************/

#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *top = new ListNode(-1);//使用哨位节点解决链表头问题
        ListNode *current = top;

        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                current->next = l1;
                l1 = l1->next;
            }
            else
            {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        current->next = l2 ? l2 : l1;

        return top->next;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;

        if(l1->val < l2->val) 
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

int main()
{
    ListNode* l1 = new ListNode(1);
    Solution s;
    ListNode* res = s.mergeTwoLists(NULL, l1);
    cout << res->val;
    return 0;
}
