#include <iostream>

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr or head->next == nullptr)
        {
            return head;
        }    
        ListNode guard(0);
        guard.next = head;

        ListNode* pre = &guard;
        ListNode* cur = head;
        ListNode* nxt = cur->next;

        bool del_cur = false;
        while(nxt != nullptr)
        {
            if(cur->val == nxt->val)
            {
                cur->next = nxt->next;
                delete nxt;
                del_cur = true;
            }
            else
            {
                if(del_cur)
                {
                    pre->next = cur->next;
                    delete cur;
                    cur = pre->next;
                    del_cur = false;
                }
                else
                {
                    pre = pre->next;
                    cur = cur->next;
                }
            }

            nxt = cur->next;
        }

         if(del_cur)
        {
            pre->next = cur->next;
            delete cur;
        }

        return guard.next;
    }
};
int main()
{
    ListNode* h = new ListNode(1);
    ListNode* c= h;
    c->next = new ListNode(1);
    c = c->next;

    c->next = new ListNode(1);
    c = c->next;

    c->next = new ListNode(2);
    c = c->next;

    c->next = new ListNode(3);
    c = c->next;
    c->next = new ListNode(4);
    c = c->next;
    c->next = new ListNode(5);
    c = c->next;
    ListNode* r = Solution().deleteDuplicates(h);

    while(r)
    {
        std::cout << r->val << " -> ";
        r = r->next;
    }
    

    system("pause");

    
}