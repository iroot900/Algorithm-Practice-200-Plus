/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        auto pcur=head;
        //add in, then copy the ptr;
        while(pcur!=nullptr)
        {
            auto next=pcur->next;
            pcur->next=new RandomListNode(pcur->label);
            pcur->next->next=next;
            pcur=next;
        }
        pcur=head;
        while(pcur!=nullptr)
        {
            if(pcur->random!=nullptr)
            {
                pcur->next->random=pcur->random->next;
            }
            pcur=pcur->next->next;
        }
        pcur=head;
        RandomListNode dummy(-1);
        auto p=&dummy;
        while(pcur!=nullptr)
        {
            p->next=pcur->next;p=p->next;
            pcur->next=pcur->next->next;
            pcur=pcur->next;
        }
        return dummy.next;
    }
};
