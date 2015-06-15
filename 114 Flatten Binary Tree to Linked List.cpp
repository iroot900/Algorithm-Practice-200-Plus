/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        if(root==NULL) return ;
        flatten(root->left);
        flatten(root->right);
        // still what we found here ?
        // the most basic traverse. 
        
        
        if(root->left==NULL) return; 
        
        TreeNode* end=root->left;
        while(end->right)
        {
            end=end->right;
        }
        
        end->right=root->right;
        root->right=root->left;
        
        root->left=NULL;
    }
};
