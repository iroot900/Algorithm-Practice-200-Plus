
class TreeNode
{
	int val;
	TreeNode* left=nullptr;
	TreeNode* right=nullptr;
};

TreeNode *closest(TreeNode* root, int val)
{
	if(!root) return root;
	if(root->val==val) return root;

	if(root->val<val)
	{
		if(!root->right) return root;
		TreeNode* node=closet(root->right,val);
		if(abs(node->val-val)<abs(root->val-val)) return node;
		else return root;
	}
	else 
	{
		if(!root->left) return root;
		TreeNode* node=closet(root->left,val);
		if(abs(node->val-val)<abs(root->val-val)) return node;
		else return root;
	}
}

