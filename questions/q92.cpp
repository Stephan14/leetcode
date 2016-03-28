
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {

        if (head == NULL)
            return NULL;

        ListNode *q = NULL;
        ListNode *p = head;
        for(int i = 0; i < m - 1; i++)
        {
            q = p;
            p = p->next;
        }

        ListNode *end = p;
        ListNode *pPre = p;
        p = p->next;
        for(int i = m + 1; i <= n; i++)
        {
            ListNode *pNext = p->next;

            p->next = pPre;
            pPre = p;
            p = pNext;
        }

        end->next = p;
        if (q)
            q->next = pPre;
        else
            head = pPre;

        return head;
    }

};

int main(int argc, char const *argv[])
{
  ListNode *temp1 = new ListNode(1);
  ListNode *temp2 = new ListNode(2);
  temp1->next = temp2;
  Solution s;
  ListNode *node = s.reverseBetween( temp1, 1, 2);
  cout<< node->val;
  cout<< node->next->val;
  return 0;
}
