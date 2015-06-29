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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(-1);
        dummy.next=head;
        ListNode* pcur=&dummy;
        while(pcur->next!=nullptr)
        {
            if(pcur->next->val==val)
            {
                auto temp=pcur->next;
                pcur->next=pcur->next->next;
                delete temp;
            }
            else
            pcur=pcur->next;
        }
        return dummy.next;
    }
};
