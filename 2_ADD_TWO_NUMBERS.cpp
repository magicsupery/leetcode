#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			int tmp_num = 0;
			int carry = 0;
			ListNode* res = new ListNode(0);
			ListNode* pre = res;

			while( l1 != NULL || l2 != NULL)
			{
				tmp_num += (l1 == NULL)? 0: l1->val;
				tmp_num += (l2 == NULL)? 0: l2->val;
				tmp_num += carry;

				carry = tmp_num / 10;
				tmp_num %= 10;
				
				pre->next = new ListNode(tmp_num);
				pre = pre->next;
				
				l1 = (l1 == NULL)? l1: l1->next;
				l2 = (l2 == NULL)? l2: l2->next;
				tmp_num = 0;
			}
			
			if(carry == 1)
				pre->next = new ListNode(carry);

			return res->next;

		}
};

int main()
{
	ListNode* l1 = new ListNode(0);
	auto tmp = l1;

	ListNode* l2 = new ListNode(1);
	tmp = l2;
	tmp->next = new ListNode(8);
	
	auto res = Solution().addTwoNumbers(l1, l2);
	cout << "res is " << res->val << endl;
		
}
