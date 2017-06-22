/*************************************************************************
	> File Name: q23.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  6/21 19:03:44 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<priority_queue> 

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
    //利用堆排序
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        ListNode* first = NULL;
        ListNode* current = NULL;

        for(int i = 0; i < lists.size(); i++)
            if(lists[i])//判断节点是否为空
                q.push(lists[i]);

        while(!q.empty())
        {
            ListNode * tmp = q.top();
            q.pop();
            if(tmp->next)
                q.push(tmp->next);
            if(first == NULL)
                current = first = tmp;
            else
            {
                current->next = tmp;
                current = current->next;
            }
        }

        return first;
    }

    struct cmp{
        bool operator()(ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        }
    };
};
