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
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next) return true;
        // reverse the right half. 
        ListNode dummy(-1);
        dummy.next=head;
        
        // find the middle
        auto p=&dummy;
        auto pp=&dummy;
        while(pp&&pp->next)
        {
            p=p->next; pp=pp->next->next;
        }
        
        // reverse right side
        ListNode* pu=p->next;
        ListNode* pd=nullptr;
        while(pu)
        {
            auto next=pu->next;  pu->next=pd; pd=pu; pu=next;
        }
        p->next=pd; 
        
        //compare
        ListNode* left=head;
        ListNode* right=pd;
        while(right)
        {
            if(left->val!=right->val) return false;
            left=left->next;  right=right->next;
        }
        return true; 
    }
};
