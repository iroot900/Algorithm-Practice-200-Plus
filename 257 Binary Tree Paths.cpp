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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        binaryTreePaths(root,result,"");
        return result;
    }
    
    void binaryTreePaths(TreeNode* root, vector<string>& result, string solu) {
        if(!root) return;
        if(!root->left&&!root->right)
        {
            result.push_back(solu+to_string(root->val)); return;
        }
        solu=solu+to_string(root->val)+"->";
        binaryTreePaths(root->left,result,solu);
        binaryTreePaths(root->right,result,solu);
    }
};
