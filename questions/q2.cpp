#include<iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
      if( l1 == NULL || l2 == NULL )
        return NULL;

      ListNode *reserverl1 = reserverList( l1 );
      ListNode *reserverl2 = reserverList( l2 );
      ListNode *top = NULL, *p = NULL;
      int lastvalue = 0;

      while( reserverl1 != NULL && reserverl2 != NULL )
      {
        int tempvalue = ( reserverl2->value + reserverl1->value + lastvalue ) % 10;
        lastvalue = ( reserverl2->value + reserverl1->value + lastvalue ) / 10;
        if( top == NULL )
        {
          top = new ListNode( 0 );
          top->value = tempvalue;
          p = top;
        }
        else
        {
          ListNode *temp = new ListNode( 0 );
          temp->next = tempvalue;
          p->next = temp;
          p = p->next;
        }
        reserverl2 = reserverl2 -> next;
        reserverl1 = reserverl1 -> next;
      }

      while( reserverl1 != NULL )
      {
        int tempvalue = ( reserverl1->value + lastvalue ) % 10;
        lastvalue = ( reserverl1->value + lastvalue ) / 10;
        ListNode *temp = new ListNode( 0 );
        temp->next = tempvalue;
        p->next = temp;
        p = p->next;
        reserverl1 = reserverl1 -> next;
      }

      while( reserverl2 != NULL )
      {
        int tempvalue = ( reserverl2->value + lastvalue ) % 10;
        lastvalue = ( reserverl2->value + lastvalue ) / 10;
        ListNode *temp = new ListNode( 0 );
        temp->next = tempvalue;
        p->next = temp;
        p = p->next;
        reserverl2 = reserverl2 -> next;
      }
      return reserverList( top );
    }

    ListNode　*reserverList(ListNode* l1)
    {
      ListNode* cur = NULL;
      ListNode* last = NULL;

      while( l1 != NULL )
      {
        cur = l1;
        l1 = l1->next;
        cur->next = last;
        last = cur;
      }

      return cur;
    }
};
