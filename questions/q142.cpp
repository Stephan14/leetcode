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
        
        if(head == NULL || head->next == NULL)
            return NULL;
        
        map<ListNode*, int> record;

        ListNode* current = head;

        while(current)
        {
            if(record.find(current) == record.end())
                record[current] = 1;
            else
                return current;

            current = current->next;
        }
           
        return NULL;
    }
};
