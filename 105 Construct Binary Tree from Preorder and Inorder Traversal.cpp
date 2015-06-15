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
    // things keep in mind. you're reading info and process it.  
    //info->main logic->boundary(little) don't be scared by 3 or 2 
    // take your time on 1 before goto 2 and, work out 2 first before go to 3... 
    // That's your mind works. believe it . don't jump into something, it doesn't help 
    //    sorted. then   1 2 3 4 5 6 7 8  ---> in-order
    //              3                           pre-order
    //            4   2
    //          1   8
    //        5
    //     in-order 5 1 4 8   [3]  2-- then go to the left half ? 
    //    pre-order [3] 4 1 5 8/ 2 
    //    pre-order --> first is the node..  then in in-order could find the first half and the left half ..
    //    keep finding the root...recursively, find root, left part, right part, fint left part's root. 
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return conTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    
    TreeNode* conTree(vector<int>& preorder, int pleft, int pright, vector<int>& inorder, int ileft, int iright) {
        
        if(pleft>pright) return nullptr;
        int i;
        for(i=ileft;i<=iright;++i)
        {
            if(inorder[i]==preorder[pleft]) break;
        }
        auto leftTree=conTree(preorder, pleft+1, pleft+i-ileft, inorder, ileft, i-1);
        auto rightTree=conTree(preorder, pleft+i-ileft +1, pright, inorder, i+1, iright);
        auto node=new TreeNode(preorder[pleft]);
        node->left=leftTree;
        node->right=rightTree;
        return node;
    }
};
