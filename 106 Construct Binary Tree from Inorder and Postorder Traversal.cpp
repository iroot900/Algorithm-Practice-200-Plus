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
//        4
//     2     5
//   7   1  3      
//      in-order    7 2 1 [4] 3 5 .  
//      post-order  7 1 2 / 3 5 [4]  --> last one the root. ..
// info.   
// main logic
// boundary case

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    
    TreeNode* buildTree(vector<int>& inorder,int ileft,int iright, vector<int>& postorder ,int pleft, int pright) {
        if(ileft>iright) return nullptr;
        int i;
        for(i=ileft;i<=iright;++i)
        {
            if(postorder[pright]==inorder[i]) break;
        }
        auto leftTree=buildTree(inorder, ileft, i-1, postorder, pleft, pleft+i-1-ileft);
        auto rightTree=buildTree(inorder, i+1, iright, postorder, pleft+i-ileft, pright-1);
        auto tree=new TreeNode(postorder[pright]);
        tree->left=leftTree;
        tree->right=rightTree;
        return tree;
    }
};
