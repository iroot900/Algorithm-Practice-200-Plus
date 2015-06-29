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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
         TreeNode* head=nullptr;
         upsideDown(root, nullptr, head); 
         return head;
    }
    
    void upsideDown(TreeNode* child, TreeNode* parent, TreeNode* &head) {
        if(child==nullptr) {head=parent;return;}
        upsideDown(child->left, child, head);
        child->right=parent;
        if(parent)
        child->left=parent->right;
        else 
        child->left=nullptr;
    }
};
