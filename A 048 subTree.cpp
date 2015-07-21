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

bool sameTree(node* leftTree, node* rightTree)
	 {
		 if(leftTree==nullptr) return rightTree==nullptr;
	     if(rightTree==nullptr) return true;
		 if(leftTree->val!=rightTree->val) return false;
		 return sameTree(leftTree->left,rightTree->left)&&sameTree(leftTree->right, rightTree->right);
	 }
 
bool subTree(node* T, node* S)
	 {
       if(T==nullptr) return S==nullptr;
       if(sameTree(T, S)) return true;
	   return subTree(T->left,S)||subTree(T->right,S);
	 }

int main()
{
	node* root=nullptr;
	for(int i=0;i<10;++i)
		add(root,i*2);
	travel(root);
	cout<<endl;
	
	node* root1=nullptr;
	for(int i=0;i<20;++i)
		add(root1,i*2);
	travel(root1);
	cout<<endl;

	cout<<"S1 is sub of S: "<<subTree(root,root1)<<endl;
	cout<<"S is sub of S1: "<<subTree(root1,root)<<endl;
}
