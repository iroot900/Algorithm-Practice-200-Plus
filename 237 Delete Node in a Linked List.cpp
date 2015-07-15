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
    void deleteNode(ListNode* node) { // node 3. 
    // logic:
    // move value next to current. 
    // set last one as nullptr;
    auto pcur=node;
    while(1)
    {
        pcur->val=pcur->next->val;
        if(!pcur->next->next) {auto next=pcur->next; pcur->next=nullptr; delete next; return;}
        else pcur=pcur->next;
    }
    }
};
