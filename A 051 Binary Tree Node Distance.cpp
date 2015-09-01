#include <iostream>
using namespace std;

class TreeNode
{
	public:
		TreeNode(int x):val(x){}
		int val;
		TreeNode* left=nullptr;
		TreeNode* right=nullptr;
};

//add this is fun use &
void add(TreeNode*& root, int x)
{
	if(!root) {root=new TreeNode(x); return ;}
	if(root->val>x)  add(root->left, x);
	else add(root->right,x);
}

void print(TreeNode* root)
{
	if(!root) return;
	print(root->left);
	cout<<root->val<<" ";
	print(root->right);
}

void erase(TreeNode*& root, int x)
{
	//when the node found and only one child.  child up 
	//if both child. 
	//swap value with next inorder. 
	// delete inroder node. 
	if(!root) return;
	if(root->val>x) erase(root->left,x);
	else if(root->val<x) erase(root->right,x);
	else if(root->val==x) 
	{
		if(!root->left) 
		{
			auto node=root;
			root=root->right; delete node;
		}
		else if(!root->right)
		{
			auto node=root;
			root=root->left; delete node;
		}
		else  // find the inorder successor
		{
			auto next=root->right;
			while(next->left) next=next->left;
			//swap(next->val,root->val);
			root->val=next->val;
			erase(root->right,next->val);
		}
	}
}

TreeNode* find(TreeNode* root, int x)
{
	auto cur=root;
	while(cur)
	{
		if(cur->val==x) return cur;
		if(cur->val>x) cur=cur->left;
		else cur=cur->right;
	}
	return nullptr;
}

int dist(TreeNode* root, int a, int b, int& len)
{
	if(!root) return 0;
	int left=dist(root->left, a, b,len);
	int right=dist(root->right,a, b, len);
	
	if(left>0&&right>0) return len=left+right;
	if(root->val==a||root->val==b)
	{
		if(left||right) return len=left+right;
		return 1;
	}
	if(left) return left+1;
	if(right) return right+1;
	return 0;
}

int main()
{
	//      6 
	//  3        8
	//1  4   7    9
	// 2   5
	//
	TreeNode* root=nullptr;
	add(root,6);
	add(root,3);
	add(root,8);
	add(root,1);
	add(root,4);
	add(root,7);
	add(root,9);
	add(root,2);
	add(root,5);
	
	print(root);
	cout<<endl;
	cout<<"__"<<endl;
	cout<<find(root,10)<<endl;
	cout<<find(root,1)<<endl;
	cout<<find(root,2)<<endl;
	cout<<"__"<<endl;
	cout<<endl;

	cout<<"-----"<<endl;
	for(int i=2;i<=9;i+=2)
	{
		for(int j=1;j<9;j+=2)
		{
			int len=0;
			dist(root,i,j,len);
			cout<<i<<" "<<j<<" "<<len<<endl;
		}
	}
	cout<<"-----"<<endl;
	for(int i=1;i<=9;++i)
	{
		erase(root,i);
		print(root);
		cout<<endl;
	}
}
