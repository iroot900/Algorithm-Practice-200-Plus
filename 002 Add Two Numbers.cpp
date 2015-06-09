class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode*  pu=l1;
        ListNode*  pd=l2;
        ListNode*  pcur=&dummy;
        int carry=0;
        int digit=0;
        int sum=0;
        while(pu!=nullptr||pd!=nullptr)
        {
            if(pu!=nullptr&&pd!=nullptr)
            {
                sum=pu->val+pd->val+carry;
                pu=pu->next;pd=pd->next;
            }
            else if(pu!=nullptr)
            {
                sum=pu->val+carry; pu=pu->next;
            }
            else
            {   
                sum=pd->val+carry;pd=pd->next;
            }
            digit=sum%10;carry=sum/10;
            pcur->next=new ListNode(digit);
            pcur=pcur->next;
        }
        if(carry!=0)
        pcur->next=new ListNode(carry);
        return dummy.next;
    }
};
