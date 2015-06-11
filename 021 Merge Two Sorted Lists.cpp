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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* pcur=&dummy;
        ListNode* pl=l1;
        ListNode* pr=l2;
        
        while(pl!=nullptr||pr!=nullptr)
        {
            if(pl!=nullptr&&pr!=nullptr)
            {
                if(pl->val<pr->val) {pcur->next=pl;pl=pl->next;}
                else {pcur->next=pr;pr=pr->next;}
            }
            else if(pl!=nullptr)
            {
                pcur->next=pl;pl=pl->next;
            }
            else
            {
                pcur->next=pr;pr=pr->next;
            }
            pcur=pcur->next;
        }
        return dummy.next;
    }
};
