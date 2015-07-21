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

int main()
{
	node* root=nullptr;
	for(int i=0;i<10;++i)
		add(root,i*2);
	travel(root);
	cout<<endl;
	for(int i=0;i<9;++i)
	{
		int nxt=INT_MAX;
		next(root,i*2, nxt);
		cout<<i*2<<"-next->"<<(nxt==INT_MAX?INT_MIN:nxt)<<endl;
	}

	for(int i=0;i<5;++i)
		cout<<"find->" <<i*2<<" : "<<find(root,i*2)<<endl;
	for(int i=0;i<5;++i)
		cout<<"find->" <<i*2+1<<" : "<<find(root,i*2+1)<<endl;
}
