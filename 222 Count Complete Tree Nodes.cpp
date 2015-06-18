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
    // This one is very unique, as not in a usualy traverse way.
     int countNodes(TreeNode* root) {
     int left=0, right=0;//it's binary , left right, half will not be used. 
     auto ltree=root, rtree=root;
     
     while(ltree) {++left;ltree=ltree->left;}
     while(rtree) {++right;rtree=rtree->right;}
     if(left==right) return pow(2,left)-1;
     
     // using recursion.
     return countNodes(root->left)+countNodes(root->right)+1;
    }
};
