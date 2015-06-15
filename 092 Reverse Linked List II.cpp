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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n) return head;
        ListNode dummy(-1);
        ListNode* pl=&dummy;
        dummy.next=head;
        int mm=m;
        while(--mm)
        {
            pl=pl->next;
        }
        // 1 2 3 4 5 
        ListNode* pu=pl->next;
        ListNode* pd=NULL;
        ListNode* last=pl->next; // keep the last to link it back
        int num=n-m+1;
        while(num--)// regular reverse 
        {
            ListNode* pcur=pu;pu=pu->next;
            pcur->next=pd; pd=pcur;
        }
        //link it bak..
        pl->next=pd;
        last->next=pu;
        return dummy.next;
    }
};
