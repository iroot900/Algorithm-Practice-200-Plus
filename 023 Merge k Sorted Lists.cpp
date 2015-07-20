/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //Method A: merge sort
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

// Method B: minHeap
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class comp
{
    public:
    bool operator () (pair<int,ListNode*> left, pair<int,ListNode*> right)  const 
    {
        return left.first>right.first;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //use a minHeap;
        ListNode dummy(-1);
        ListNode* p=&dummy;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>, comp> heap;
        
        for(auto list:lists)
        {
            if(list) heap.push({list->val, list});
        }
        
        while(!heap.empty())
        {
            pair<int, ListNode*> next=heap.top(); heap.pop();
            p->next=next.second;
            p=p->next;
            if(next.second->next) heap.push({next.second->next->val,next.second->next});
        }
        
        return dummy.next;
    }
};
