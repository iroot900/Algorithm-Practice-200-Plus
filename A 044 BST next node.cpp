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

void next(node* root, int val, int& nxt)
{
	if(!root) return ;
	if(root->val<=val) next(root->right,val,nxt);
	else 
	{
		nxt=min(nxt,root->val);
		next(root->left,val,nxt);
	}
}

int main()
{
	node* root=nullptr;
	for(int i=0;i<10;++i)
		add(root,i);
	travel(root);
	cout<<endl;
	for(int i=0;i<9;++i)
	{
		int nxt=INT_MAX;
		next(root,i, nxt);
		cout<<i<<"-->"<<nxt<<endl;
	}
}
