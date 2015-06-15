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
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return sysm(root->left, root->right);
    }
    
    bool sysm(TreeNode* left, TreeNode* right)
    {
        if(left==nullptr||right==nullptr) return left==right;
        return (left->val==right->val)&&sysm(left->left,right->right)&&sysm(left->right,right->left);
    }
};
