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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(-1);
        dummy.next=head;
        ListNode* pl=&dummy, *pr=&dummy;
        
        while(n--)
        {
            pr=pr->next;
        }
        
        while(pr->next!=nullptr)//think about your data. not code. Coding is clear and beautiful if your thinking is clear
        {
            pr=pr->next;pl=pl->next;
        }
        
        auto temp=pl->next;
        pl->next=pl->next->next;
        delete temp;
        return dummy.next;
    }
};
