
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
        ListNode *pre = p;
        p = p->next;
        for(int i = m + 1; i <= n; i++)
        {
            ListNode *pnext = p->next;//保存临时变量
            p->next = pre;
            pre = p;//****
            p = pnext;//为下一次设置初值
        }

        end->next = p;
        if (q)
            q->next = pre;
        else
            head = pre;

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
