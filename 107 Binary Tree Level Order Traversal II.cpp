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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        levelTraverse(root, 0, result);
        reverse(begin(result),end(result));
        return result;
    }
    
    void levelTraverse(TreeNode* root, int level, vector<vector<int>>& result)
    {
        if(root==nullptr) return ;
        if(level+1>result.size()) result.push_back(vector<int> ());
        result[level].push_back(root->val);
        levelTraverse(root->left, level+1, result);
        levelTraverse(root->right,level+1, result);
    }
};
