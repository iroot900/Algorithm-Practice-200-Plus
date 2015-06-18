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
    ListNode* reverseList(ListNode* head) {
        ListNode* pu=head;
        ListNode* pd=nullptr;
        
        while(pu!=nullptr)
        {
            auto pcur=pu;pu=pu->next;
            pcur->next=pd;
            pd=pcur;
        }
        return pd;
    }
};
