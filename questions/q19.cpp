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
    
        ListNode* pre = head;
        ListNode* cur = head;

        for(int i = 0; i < n; i++)
           pre = pre->next;

        if(!pre) return head->next;//移除头结点

        while(pre->next)//使用pre->next而不是pre,方便获取删除节点的前一个节点
        {
            pre = pre->next;
            cur = cur->next;
        }

        cur->next = cur->next->next;

        return head;
    }
};

