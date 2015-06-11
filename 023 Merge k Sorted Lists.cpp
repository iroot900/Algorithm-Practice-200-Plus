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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         int n=lists.size();
         if(n==0) return nullptr;
         merge(lists, 0, n-1 );
         return lists[0];
    }
    
    void merge(vector<ListNode*>& lists, int left,int right )
    {
        if(left==right) return ;
        int mid=(left+right)>>1;
        merge(lists,left,mid);
        merge(lists,mid+1,right);
        mergeTwoLists(lists[left],lists[mid+1]);
    }
    
    void mergeTwoLists(ListNode*& l1, ListNode*& l2) {
        ListNode dummy(-1);
        ListNode* pcur=&dummy;
        ListNode* pl=l1;
        ListNode* pr=l2;
        
        while(pl!=nullptr||pr!=nullptr)
        {
            if(pl!=nullptr&&pr!=nullptr)
            {
                if(pl->val<pr->val) {pcur->next=pl;pl=pl->next;}
                else {pcur->next=pr;pr=pr->next;}
            }
            else if(pl!=nullptr)
            {
                pcur->next=pl;pl=pl->next;
            }
            else
            {
                pcur->next=pr;pr=pr->next;
            }
            pcur=pcur->next;
        }
        l1=dummy.next;
    }
};
