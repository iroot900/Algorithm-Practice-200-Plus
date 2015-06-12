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
ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||k==0) return head;
        ListNode dummy(-1);
        dummy.next=head;
        ListNode* pl=&dummy, *pr=&dummy;  
        
        auto temp=head;
        int len=0;
        while(temp!=nullptr)
        {
            temp=temp->next;++len;
        }
        
        k=k%len;
        if(k==0) return dummy.next;
        
        int count=k;
        while(count--)
        {
            pr=pr->next;
        }
        while(pr->next!=nullptr)
        {
            pr=pr->next;pl=pl->next;
        }
        
        temp=dummy.next;
        dummy.next=pl->next;
        pr->next=temp;
        pl->next=nullptr;
        return dummy.next;
    }
};
