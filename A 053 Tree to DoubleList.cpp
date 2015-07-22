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
//to list single double. it's all about traverse . all the way name it
//record a last node. all done!.. nothing complicated!..same as ancestor
//actually same for all tree problem!!!
void ToDoubleList(node* root, node* & last, node*& head)
{
	if(!root) return;
	ToDoubleList(root->left,last, head);
	if(last==nullptr) head=root;
	else {root->left=last; last->right=root;}
	last=root;
	cout<<root->val<<" x"<<endl;
	ToDoubleList(root->right,last, head);
}

node* ToDoubleList(node* root)
{
	node* last=nullptr;
	node* head=nullptr;
	ToDoubleList(root,last,head);
	return head;
}

void print(node* root)
{
	while(root) {cout<<root->val<<" "; root=root->right;}
	cout<<endl;
}

int main()
{
	node* root=nullptr;
	add(root,5);
	add(root,2);
	add(root,4);
	add(root,1);
	add(root,6);
	add(root,3);

	travel(root);
	cout<<endl;
	
	auto head=ToDoubleList(root);
	print(head);
	cout<<endl;
}
