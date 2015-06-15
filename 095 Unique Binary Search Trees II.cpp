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
    vector<TreeNode*> generateTrees(int n) {
        return genTrees(1,n);
    }
    
    vector<TreeNode*> genTrees(int left,int right) {
        
        vector<TreeNode*> trees;
        if(left>right) {trees.push_back(nullptr); return trees;}
        for(int i=left;i<=right;++i)
        {
            auto leftTrees=genTrees( left, i-1);
            auto rightTrees=genTrees( i+1, right);
            
            for(auto leftTree:leftTrees)
            {
                for(auto rightTree:rightTrees)
                {
                    auto node=new TreeNode(i);
                    node->left=leftTree;
                    node->right=rightTree;
                    trees.push_back(node);
                }
            }
        }
        return trees;
    }
};
