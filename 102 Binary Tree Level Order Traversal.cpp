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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelOrder(root, 0, result);
        return result;
    }
    
    void levelOrder(TreeNode* root, int level, vector<vector<int>>& result) {
        if(root==nullptr) return ;
        
        if(result.size()<level+1) result.push_back(vector<int>());
        result[level].push_back(root->val);
        
        levelOrder(root->left,  level+1, result);
        levelOrder(root->right, level+1, result);
    }
};
