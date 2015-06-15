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
    ListNode* partition(ListNode* head, int x) {
        ListNode Left(-1);
        ListNode Rright(-1);
        ListNode* pleft=&Left, *pright=&Rright, *pcur=head;
        while(pcur!=nullptr)
        {
            if(pcur->val<x)
            {
                pleft->next=pcur;
                pleft=pleft->next;
            }
            else
            {
                pright->next=pcur;
                pright=pright->next;
            }
            pcur=pcur->next;
        }
        pleft->next=Rright.next;
        pright->next=nullptr;
        return Left.next;
    }
};
