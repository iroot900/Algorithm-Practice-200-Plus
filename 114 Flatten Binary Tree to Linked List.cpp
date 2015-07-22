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
    void flatten(TreeNode* root) {
        // first order travers.  keep right to next.  
        TreeNode* last=nullptr;
        toList(root, last);
    }
    //main logic. visit right first. return node
    // current 
    void toList(TreeNode* root, TreeNode* &last)
    {
        if(root==nullptr) return ;
        toList(root->right, last);
        toList(root->left, last); // there is no left right. when the node is done about go up, it should point to last 
        root->right=last;
        root->left=nullptr;
        last=root;
    }
};
