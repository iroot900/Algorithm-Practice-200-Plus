#include <iostream>
using namespace std;
struct node
{
	node(int x):val(x){}
	int val;
	node* left=nullptr;
	node* right=nullptr;
};

void travel(node* root)
{
	if(!root) return; 
	travel(root->left);
	cout<<root->val<<" ";
	travel(root->right);
}

void add(node* &root, int x)
{
	if(root==nullptr) {root=new node(x); return ;}
	if(root->val>x) add(root->left,x);
	else add(root->right,x);
}

bool find(node* root,int val)
{
	auto cur=root;
	while(cur)
	{
		if(cur->val==val) return true;
		else if(cur->val>val) cur=cur->left;
		else cur=cur->right;
	}
	return false;
}

node* LCA(node * root, node* p, node* q)
{
	if(root==nullptr) return nullptr;//not found in this branch. 
	if(root==p||root==q) return root; //found in one branch(could be ance)
	auto left=LCA(root->left, p, q);
	auto right=LCA(root->right, p, q);
	//well kind of brilliant way!
	if(left&&right) return root;
	return left?left:right;
}

node* LCA2(node * root, int a, int b)
{
	if(root==nullptr) return nullptr;//not found in this branch. 
	if(root->val==a||root->val==b) return root; //found in one branch(could be ance)
	auto left=LCA2(root->left, a, b);
	auto right=LCA2(root->right, a, b);
	//well kind of brilliant way!
	if(left&&right) return root;
	return left?left:right;
}

int main()
{
	node* root=nullptr;
	add(root,8);
	add(root,2);
	add(root,20);
	add(root,14);
	add(root,16);
	add(root,6);
	add(root,4);
	add(root,0);
	add(root,18);
	travel(root);
	cout<<endl;
	
	cout<<LCA2(root,0,8)->val<<endl;	
	cout<<LCA2(root,4,10)->val<<endl;	
	cout<<LCA2(root,6,16)->val<<endl;	
}
