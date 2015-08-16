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
    int countUnivalSubtrees(TreeNode* root) {
        int count=0;
        countUnivalSubtrees(root, count);
        return count;
    }
    
    bool countUnivalSubtrees(TreeNode* root, int & count)
    {
        if(!root) return true;
        auto left=countUnivalSubtrees(root->left,count);
        auto right=countUnivalSubtrees(root->right,count);
        
        if(left&&right)
        {
            if(root->left) {if(root->left->val!=root->val) return false;}
            if(root->right) {if(root->right->val!=root->val) return false;}
            ++count; return true; 
        }
        return false;
    } 
};
