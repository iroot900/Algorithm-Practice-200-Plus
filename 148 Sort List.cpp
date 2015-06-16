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
    ListNode* sortList(ListNode* head) {
        // merge sort must be how to do. iteratively 
        if(head==nullptr||head->next==nullptr) return head;
        auto p=head, pp=head;
        while(pp!=nullptr&&pp->next!=nullptr&&pp->next->next!=nullptr)
        {
            p=p->next;pp=pp->next->next;
        }
        auto right=p->next;  p->next=nullptr;
        auto leftList=sortList(head);
        auto rightList=sortList(right);
        return merge(leftList, rightList);
    }
    
    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode dummy(-1);
        auto pcur=&dummy;
        while(left!=nullptr||right!=nullptr)
        {
            if(left!=nullptr&&right!=nullptr)
            {
                if(left->val<right->val)
                {
                    pcur->next=left;left=left->next;
                }
                else
                {   
                    pcur->next=right;right=right->next;
                }
            }
            else if(left!=nullptr)
            {
                pcur->next=left;left=left->next;
            }
            else
                {pcur->next=right;right=right->next;}
            pcur=pcur->next;
        }
        return dummy.next;
    }
};
