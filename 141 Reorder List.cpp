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
    bool hasCycle(ListNode *head) {
        ListNode* pr=head, *pl=head;
        while(pr!=nullptr&&pr->next!=nullptr)
        {
            pr=pr->next->next;pl=pl->next;
            if(pr==pl) return true;
        }
        return false;
    }
};
