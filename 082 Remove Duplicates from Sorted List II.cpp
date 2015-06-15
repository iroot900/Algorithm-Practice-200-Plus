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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(-1);
        if(head==nullptr||head->next==nullptr) return head;
        dummy.next=head;  
        auto p=&dummy; 
        auto pr=&dummy;
        pr=pr->next->next; // think about which node you'll operate on and what's needed for that operation. 
        
        while(pr!=nullptr)
        {
            if(p->next->val==pr->val)
            {
                while(pr!=nullptr&&p->next->val==pr->val)
                {
                    auto it=pr;
                    pr=pr->next; delete it;
                }
                auto it=p->next;  p->next=pr; delete it; 
                if(pr!=nullptr)
                pr=pr->next; // 1 1  2//   1 1  1 1 1 //  1 1  2 2  [ use small case to do things ]
            }
            else
            {
                p=p->next;pr=pr->next;
            }
        }
        return dummy.next;
    }
};
