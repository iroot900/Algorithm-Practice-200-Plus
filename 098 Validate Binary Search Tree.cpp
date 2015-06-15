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
    bool isValidBST(TreeNode* root) {
        // in-order traverse to check the order. 
        // no need to store the array just need previous one and compare---> brilliant idea.  time n, space 1..
        long last=LONG_MIN;
        return BST(root, last);
    }
    
    
    bool BST(TreeNode* root,long& last)
    {   
        if(root==nullptr) return true;
        if(!BST(root->left, last)) return false;
        if(root->val<=last) return false;
        else last=root->val;
       // if(!BST(root->right, last)) return false;
       // else return true;
        return BST(root->right, last);
    }
};
