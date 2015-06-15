/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // in-order traverse. 
 
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* a, *b, *plast;
        long last=LONG_MIN;
        bool first=true;
        recoverTree(root, first ,a, b, last,plast);
        swap(a->val,b->val);
    }
    
    void recoverTree(TreeNode* root, bool& first,TreeNode*& a, TreeNode*& b, long &last, TreeNode*& plast) {
        if(root==nullptr) return;
        recoverTree(root->left,first,  a,  b, last, plast);
        if(root->val<last) 
        {
            if(first)   {a=plast;b=root;first=false;}
            else b=root;
        }
        last=root->val;
        plast=root;
        recoverTree(root->right, first, a,  b, last, plast);
    }
};
