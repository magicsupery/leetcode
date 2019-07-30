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

        ListNode* cur = head;
        ListNode* nxt = cur->next;
        while(nxt != nullptr)
        {
            if(cur->val == nxt->val)
            {
                cur->next = nxt->next;
                delete nxt;
            }
            else
            {
                cur = cur->next;
            }
            nxt = cur->next;
        }
        
        return head;
    }
};

int main()
{
    ListNode* h = new ListNode(1);
    ListNode* c= h;
    c->next = new ListNode(2);
    c = c->next;

        c->next = new ListNode(3);
    c = c->next;

        c->next = new ListNode(3);
    c = c->next;

        c->next = new ListNode(4);
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