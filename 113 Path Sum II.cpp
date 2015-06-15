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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int>  solution;
        path(root, sum, 0, result, solution);
        return result;
    }
    
    void path(TreeNode* root, int sum,int total, vector<vector<int>>& result, vector<int> & solution) {
        if(root==nullptr) return; 
        if(root->left==nullptr&&root->right==nullptr)
        {
            if(total+root->val==sum)
            {
                solution.push_back(root->val);
                result.push_back(solution);
                solution.pop_back();
            }
            return;
        }
        solution.push_back(root->val);
        path(root->left, sum, total+root->val, result, solution);
        path(root->right, sum, total+root->val, result, solution);
        solution.pop_back();
    }
};
