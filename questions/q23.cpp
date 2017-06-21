/*************************************************************************
	> File Name: q23.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  6/21 19:03:44 2017
 ************************************************************************/

#include<iostream>
#include<vector>

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
    //归并排序、分而治之的思想
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int count = lists.size();
        if(count == 0)
            return NULL;
        while(count > 1)
        {
            int k = (count + 1) / 2;//count无论为奇数还是偶数，其k的值都可以不变
            for(int i = 0; i < count / 2; i++)
                lists[i] = mergeTwoLists(lists[i], lists[k + i]);
            count = k;
        }

        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode*l2){
        ListNode* first = new ListNode(-1);
        ListNode* current = first;

        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
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
        current->next = l1 ? l1 : l2;

        return first->next;
    }
};
