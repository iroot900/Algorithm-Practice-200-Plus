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
    ListNode* swapPairs(ListNode* head) {
        // 1 2 3 4 
        ListNode dummy(-1);
        dummy.next=head;
        ListNode* pl=&dummy;
        ListNode* pr=&dummy;
        
        while(1)
        {
            int count=2;
            while(count--&&pr!=nullptr) {pr=pr->next;}
            if(pr==nullptr) return dummy.next;
            
            pl->next->next=pr->next;
            pr->next=pl->next;
            pl->next=pr;
            pr=pl->next->next;
            pl=pr;
        }
    }
};
