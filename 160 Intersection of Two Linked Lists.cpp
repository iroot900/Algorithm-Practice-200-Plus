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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pleft=headA, *pright=headB;
        int lenA=0,lenB=0;
        while(pleft!=nullptr)  {pleft=pleft->next; ++lenA;}
        while(pright!=nullptr) {pright=pright->next;++lenB;}
        
        pleft=headA;pright=headB;
        
        if(lenA>lenB)
        {
            int count=lenA-lenB;
            while(count--) pleft=pleft->next;
        }
        else
        {
            int count=lenB-lenA;
            while(count--) pright=pright->next;
        }
        
        while(pleft!=nullptr)
        {
            if(pleft==pright) return pleft;
            pleft=pleft->next; pright=pright->next;
        }
        return nullptr;
    }
};
