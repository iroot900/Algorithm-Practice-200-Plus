/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *z     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
// if node keep the number of left and right , then could do binary. 
// running cost is low, when do insert/delete update when pop stack.
    int kthSmallest(TreeNode* root, int k) {
        int val=0;
        kthSmall(root, k, val);
        return val;
    }
    
    void kthSmall(TreeNode* root, int &k, int &val) {
        if(root==nullptr) return ;
        kthSmall(root->left, k, val);
        --k;
        if(k==0) val=root->val;
        kthSmall(root->right, k, val);
    }
};
