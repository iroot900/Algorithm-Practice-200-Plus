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
    int sumNumbers(TreeNode* root) {
        int sum=0;
        travese(root, sum, 0);
        return sum;
    }
    
    void travese(TreeNode* root, int& sum, int total)
    {
        if(root==nullptr) return;
        if(root->left==nullptr&&root->right==nullptr) 
        {
            sum+=total*10+root->val;return;
        }
        travese(root->left, sum,  total*10+root->val);
        travese(root->right, sum, total*10+root->val);
    }
};
