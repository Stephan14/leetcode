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
        
        ListNode* top = NULL;
        ListNode* rear = NULL;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                if(top == NULL)
                {
                    top = l1;
                    rear = l1;
                }
                else
                {
                    rear->next = l1;
                    rear = l1;
                }
                l1 = l1->next;
            }
            else
            {
                if(top == NULL)
                {
                    top = l2;
                    rear = l2;
                }
                else
                {
                    rear->next = l2;
                    rear = l2;
                }
                l2 = l2->next;
            }
        }

        if(l1 != NULL && rear != NULL) //使用指针之前判断指针是否为空
            rear->next = l1;
        else
            top = l1;
        if(l2 != NULL && rear != NULL)
            rear->next = l2;
        else
            top = l2;

        return top;
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
