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
        if(head==nullptr) return head;
        auto pcur=head;// dummy needed? you can still use it, but no needed actually. think about the main logic. then down to data structure// use little cast to do boundary. it's all good then. 
        while(pcur->next!=nullptr)
        {
            if(pcur->val==pcur->next->val)
            {
                auto it=pcur->next;
                pcur->next=pcur->next->next;
                delete it;
            }
            else
            {
                pcur=pcur->next;
            }
        }
        return head;
    }
};
