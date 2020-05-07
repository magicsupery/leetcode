struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
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
    ListNode* sortList(ListNode* head) {
        // last pivot current
        ListNode* middle = findMiddle(head, nullptr, head->val);
        return nullptr;
    }

    ListNode* findMiddle(ListNode* start, ListNode* end, int pivot)
    {
       return nullptr;
    }

};