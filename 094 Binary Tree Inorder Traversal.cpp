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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> sta;
        auto node=root;
        vector <int> result;
        if(root==nullptr) return result;
        while(!sta.empty()||node)
        {
            // as recursive, push left into stack.
            while(node)
            {
                sta.push(node);
                node=node->left;
            }
            node=sta.top();
            sta.pop();
            result.push_back(node->val);// visit left first.  then try right; just as recursive
            node=node->right;// right will be visited. if no right. then will stack pop, which mean visit the father node.
        }
        return result;
    }
};
