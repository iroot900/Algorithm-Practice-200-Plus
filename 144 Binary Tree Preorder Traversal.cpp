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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> sta;
        auto node=root;
        vector<int> result;
        while(!sta.empty()||node)
        {
            while(node)
            {
                result.push_back(node->val);
                sta.push(node);
                node=node->left;
            }
            node=sta.top();
            sta.pop();
            node=node->right;
        }
        return result;
    }
};
