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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //1 2 3  ] 4  5   6  ] 7  8
        //3->2->1->6->5->4->7->8
    
        ListNode dummy(-1);
        dummy.next=head;
        ListNode* pl=&dummy;
        ListNode* pr=&dummy;
        int count;
        while(1)
        {
            count=k;
            while(count--&&pr!=NULL)
            {
                pr=pr->next;
            }
            if(pr==NULL)
            {
                return dummy.next;
            }
            //reverse
            ListNode* pu=pl->next;
            ListNode* pd=pr->next;
            pr=pl->next;// pr will chnage to pl->next who's the last after change.
            count=k;
            while(count--)
            {
                auto pcur=pu; pu=pu->next;
                pcur->next=pd;pd=pcur;
            }
            pl->next=pd;
            pl=pr;
        }
    }
};
