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
    void reorderList(ListNode* head) {
        if(head==nullptr||head->next==nullptr||head->next->next==nullptr) return ;
        ListNode dummy(-1);
        dummy.next=head;
        
        ListNode* p=&dummy;// find the middle point use a dummy..    1 // 1 2 // 1 2 3..
        ListNode* pp=&dummy;
        while(pp!=nullptr&&pp->next!=nullptr)
        {
            p=p->next; pp=pp->next->next;
        }
        auto right=p->next;
        p->next=nullptr;
        
        //reverse right part.
        ListNode *pu=right, *pd=nullptr;
        while(pu!=nullptr)  // well reveres is realy simple 
        {
            auto temp=pu->next;
            pu->next=pd; pd=pu; pu=temp; //two pointer, three thing!
        }
        
        right=pd;
        auto left=head;
        auto pcur=&dummy;
        while(left!=nullptr||right!=nullptr)
        {
            if(left!=nullptr&&right!=nullptr)
            {
                pcur->next=left; left=left->next; pcur=pcur->next;
                pcur->next=right; right=right->next; pcur=pcur->next;
            }
            else if(left!=nullptr)   {  pcur->next=left; left=left->next;   }
        }
        
        head=dummy.next;
    }
};
