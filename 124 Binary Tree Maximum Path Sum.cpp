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
    int maxPathSum(TreeNode* root) {
        int result=INT_MIN;
        maxContribution(root, result);
        return result;
    }
    
    int maxContribution(TreeNode* root, int& result)
    {
        if(root==nullptr) return 0;
        int left=maxContribution(root->left, result);
        int right=maxContribution(root->right, result);
        // all the work done till bottom level. then scale up
        //bottom up.. 
        
        //contribution first. left or right or node. 
        int maxlr=max( max(left+root->val,right+root->val),root->val );
        // update current max. from left, right and left plus right.. 
        result=max(max(result,maxlr),left+right+root->val);
        return maxlr;
    }
};
