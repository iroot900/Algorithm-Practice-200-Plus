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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        int mmax=0;
        rightView( root, result,1, mmax);
        return result;
    }
    
    void rightView(TreeNode* root, vector<int>& result, int depth,int& mmax)
    {
        if(root==NULL) return ;
        
        if(depth>mmax) {result.push_back(root->val);mmax=depth;}
         rightView( root->right, result,  depth+1, mmax);
         rightView( root->left, result,  depth+1, mmax);
    }

};
