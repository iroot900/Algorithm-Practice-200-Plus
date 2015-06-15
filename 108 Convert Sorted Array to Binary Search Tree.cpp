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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        sortedArrayToBST(nums, 0, nums.size()-1);
    }
    //1
    //1 2 
    //1 2 3
    //   recursive structure, so 
    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
        if(left>right) return nullptr;
        int mid=(left+right)>>1;//   0-1     0 0  1
        auto Pleft=sortedArrayToBST(nums, left, mid-1);//null
        auto Pright=sortedArrayToBST(nums, mid+1, right);//new null
        auto tree=new TreeNode(nums[mid]);
        tree->left=Pleft;
        tree->right=Pright;
        return tree;
    }
};
