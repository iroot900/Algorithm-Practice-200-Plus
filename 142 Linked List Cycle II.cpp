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
    ListNode *detectCycle(ListNode *head) {
        //  2*(a+b)=a+b+c+b  --->a=c
        ListNode dummy(-1);
        dummy.next=head;
        ListNode* pp=&dummy, *p=&dummy;
        while(pp!=nullptr&&pp->next!=nullptr)
        {
            p=p->next;pp=pp->next->next;
            if(p==pp) break;
        }
        if(pp==nullptr||pp->next==nullptr) return nullptr;
        auto pleft=&dummy;
        while(pleft!=p)
        {
            p=p->next;pleft=pleft->next;
        }
        return p;
    }
};
