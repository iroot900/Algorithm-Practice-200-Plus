/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        auto temp=head;
        int len=0;
        while(temp!=nullptr)
        {
            temp=temp->next; ++len;
        }
        //Main logic, balanced, left half and right half.-->  it's gurrantted height differ 0 or 1.
        //Recursive structure.  buttom up. // in-order traverse ----> sorted.  could use it
        listToBST(head, 0, len-1);
    }
    //1
    //1 2
    //1 2 3 
    TreeNode* listToBST(ListNode* &head, int left, int right)
    {   //0 1
        if(left>right) return nullptr;
        int mid=(left+right)>>1;
        auto pleft=listToBST(head, left, mid-1);
        // in order needed. 
        auto tree=new TreeNode(head->val);
        tree->left=pleft;
        head=head->next;
        auto pright=listToBST(head, mid+1, right);
        tree->right=pright;
        return tree;
    }
};
