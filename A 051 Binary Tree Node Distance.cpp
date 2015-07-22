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


// go deep do nothing. then return do things!
// can't return directly as LCA.. slightly different
int distance(node* root, int a, int b)
{
	if(root==nullptr) return 0;
	int left=distance(root->left, a,b);
	int right=distance(root->right, a,b);

	//starting from here, it's all go back.  
	//if found one and the other already found.  
	if((root->val==a||root->val==b)&&(right||left)) return right?right:left;
	// only found one. 
	if(root->val==a||root->val==b) return 1;

	//both one side. both no side. one side. 
	if(left&&right) return left+right-1;
	if(left==0&&right==0) return 0;//not found yet.
	return left?left+1:right+1;
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
	
	cout<<distance(root,0,8)<<endl;	
	cout<<distance(root,4,18)<<endl;	
	cout<<distance(root,6,16)<<endl;	
}
