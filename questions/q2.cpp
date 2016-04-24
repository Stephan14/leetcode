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

       //ListNode *reserverl1 = reserverList( l1 );
       //ListNode *reserverl2 = reserverList( l2 );
       ListNode *top = NULL, *p = NULL;
       int lastval = 0;

       while( l1 != NULL && l2 != NULL )
       {
         int tempval = ( l2->val + l1->val + lastval ) % 10;
         lastval = ( l2->val + l1->val + lastval ) / 10;
         if( top == NULL )
         {
           top = new ListNode( 0 );
           top->val = tempval;
           p = top;
         }
         else
         {
           ListNode *temp = new ListNode( 0 );
           temp->val = tempval;
           p->next = temp;
           p = p->next;
         }
         l2 = l2 -> next;
         l1 = l1 -> next;
       }

       while( l1 != NULL )
       {
         int tempval = ( l1->val + lastval ) % 10;
         lastval = ( l1->val + lastval ) / 10;
         ListNode *temp = new ListNode( 0 );
         temp->val = tempval;
         p->next = temp;
         p = p->next;
         l1 = l1 -> next;
       }

       while( l2 != NULL )
       {
         int tempval = ( l2->val + lastval ) % 10;
         lastval = ( l2->val + lastval ) / 10;
         ListNode *temp = new ListNode( 0 );
         temp->val = tempval;
         p->next = temp;
         p = p->next;
         l2 = l2 -> next;
       }

       if( lastval != 0 )
       {
         ListNode *temp = new ListNode( 0 );
         temp->val = lastval;
         p->next = temp;
         p = p->next;
       }
       return  top ;
     }

     ListNode  *reserverList(ListNode *l1)
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
