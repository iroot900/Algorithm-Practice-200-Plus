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
    bool hasPathSum(TreeNode* root, int sum) {
        return PathSum(root, sum,  0);
    }
    
    bool PathSum(TreeNode* root, int sum, int total) {
        if(root==nullptr) return false;
        if(root->left==nullptr&&root->right==nullptr) 
        {
            return sum==total+root->val;
        }
        return PathSum(root->left, sum,  total+root->val) ||PathSum(root->right, sum,  total+root->val) ;
    }
};
