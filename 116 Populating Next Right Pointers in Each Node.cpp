/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        populate(root,  nullptr);
    }
    
    // sibling. give it a sibling. but still most basic deep first search. sibling provide node. not  go through it.
    
    //
    //     0
    //   1   2
    //  3 4 5 6
    //
    // current -> sibling.   current' left ->current' right.    current' right--> sibling's left. // idea of silbing helper. 
    void populate(TreeLinkNode* root, TreeLinkNode* sibling)
    {
        // sibling. --> connect current. sibling provide sibling's for left and right. 
        // II root provide connect to child
        if(root==nullptr) return;
        else
        {
            root->next=sibling;
        }
        populate(root->left,  root->right);
        if(sibling)
        populate(root->right, sibling->left);
        else
        populate(root->right, nullptr);
    }
};
