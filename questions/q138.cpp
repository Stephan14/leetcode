/*************************************************************************
	> File Name: q138.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  4/24 20:37:13 2017
 ************************************************************************/

#include<iostream>
#include<map>

using namespace std;
/**
Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        if(!head) return NULL;

        RandomListNode *headToReturn = NULL;
        RandomListNode *node = head;
        RandomListNode *preNode = NULL, *curNode = NULL;
        map<RandomListNode*, RandomListNode*> nodeMap;
        
        while(node != NULL)
        {
            curNode = new RandomListNode(node->label); 
            if(preNode != NULL)
                preNode->next = curNode;
            else
                headToReturn = curNode;
            nodeMap[node] = curNode;
            preNode = curNode;
            node = node->next; 
        }

        node = head;
        curNode = headToReturn;

        while(node != NULL)
        {
            curNode->random = nodeMap[node->random];  
            curNode = curNode->next;
            node = node->next;
        }

        return headToReturn;
    }
};
