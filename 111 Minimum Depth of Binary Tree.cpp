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
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        if(root->left==nullptr&&root->right==nullptr) return 1;// you can reach all null as usual.
        //also you can stop at any leaf. not often, but it's quite natural
        int left,right;
        if(root->left)
        left=minDepth(root->left);
        else left=INT_MAX;
        if(root->right)
        right=minDepth(root->right);
        else right=INT_MAX;
        
        return min(left,right)+1;
    }
};
