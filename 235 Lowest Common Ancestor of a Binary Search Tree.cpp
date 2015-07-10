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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* parent=nullptr;
        low( root,  p,  q, parent);
        return parent;
    }
    
    TreeNode* low(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& parent)
    {
        if(root==nullptr) return root;
        auto left=low( root->left,  p,  q, parent);
        auto right=low( root->right,  p,  q, parent);
        if((left==p&&right==q)||(left==q&&right==p)) {parent=root; return nullptr;}
        else if((root==p||root==q)&&(left==p||left==q||right==p||right==q)) {parent=root; return nullptr;}
        else if(left==p||left==q) return left;
        else if(right==p||right==q) return right;
        else return root;
    }
};
