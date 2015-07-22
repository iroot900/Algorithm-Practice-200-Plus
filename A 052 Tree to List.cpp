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

//pre-order list. when there is oder. can't be simpler
//traverse the tree of course. 
void tolist(node* root, node* &last)// post order style
{
	if(!root) return ;
	tolist(root->right,last);
	tolist(root->left,last);
	root->right=last;
	root->left=nullptr;
	last=root;
}
void Tolist(node * root)
{
	node* last=nullptr;
	tolist(root, last);
}

// inorder style.. 
// all these doesn't matter.
int main()
{
	node* root=nullptr;
	add(root,1);
	add(root,2);
	add(root,5);
	add(root,3);
	add(root,4);
	add(root,6);

	travel(root);
	cout<<endl;
	
	Tolist(root);
	travel(root);
	cout<<endl;
}
