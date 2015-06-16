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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(-1);
        //info
        //main logic
        //boundary
        ListNode* pleft=&dummy, *pright=head;
        while(pright!=nullptr)
        {
            auto p=pleft;
            auto pr=pright;
            pright=pright->next;;
            while(p->next!=nullptr)
            {
                if(pr->val<p->next->val)
                {
                    auto next=p->next;
                    p->next=pr;pr->next=next;
                    break;
                }
                p=p->next;
            }
            if(p->next==nullptr)
            {p->next=pr;pr->next=nullptr;}
        }
        return dummy.next;
    }
};
