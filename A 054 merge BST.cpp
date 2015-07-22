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

// double linked, same idea. but no use only one!!!
void toList(node* root, node*& last, node*& head)
{
	if(!root) return ;
	toList(root->left,last, head);
	if(!last) {root->left=nullptr; head=root;}
	else {root->left=nullptr; last->right=root;}
	last=root;
	toList(root->right,last, head);
}

void print(node* head)
{
	while(head) {cout<<head->val<<" "; head=head->right;}
	cout<<endl;
}

node* mergeList(node* listB, node* listA)
{
	node dummy(-1);
	auto pcur=&dummy;
	while(listA&&listB)
	{
		if(listA->val<listB->val)
		{
			pcur->right=listA; listA=listA->right;
		}
		else { pcur->right=listB; listB=listB->right;}
		pcur=pcur->right;
	}
	while(listA) {pcur->right=listA; listA=listA->right; pcur=pcur->right;}
	while(listB) {pcur->right=listB; listB=listB->right; pcur=pcur->right;}
	
	return dummy.right;
}

// 1->2->3->4->5->6->7
// list to binary search tree. don't use the middle find method. 
// that takes to long. n(logn)
// building a tree from sorted source should always be n. 
node* listToTree(node*& head, int left, int right)
{
	if(left>right) return nullptr;
	int mid=(left+right)>>1;
	auto leftTree=listToTree(head, left, mid-1);
	node* nod= new node(head->val);
	head=head->right;
	auto rightTree=listToTree(head, mid+1, right);
	nod->left=leftTree;
	nod->right=rightTree;
	return nod;
}

node* listToTree(node*& head)
{
	if(!head) return head;
	auto p=head; int count=0;
	while(p) {p=p->right; ++count;}
	return listToTree(head, 0, count-1);
}

node* mergeBST(node* root1, node* root2)
{
	node* last1=nullptr;
	node* head1=nullptr;
	toList(root1,last1,head1);

	print(head1);
	
	node* last2=nullptr;
	node* head2=nullptr;
	toList(root2,last2,head2);
	print(head2);
	auto treelist=mergeList(head1,head2);

	print(treelist);
	return listToTree(treelist);
}


int main()
{
	node* root=nullptr;
	add(root,5);
	add(root,7);
	add(root,4);
	add(root,3);
	add(root,2);
	add(root,6);

	travel(root); 
	cout<<endl;
	node* root2=nullptr;
	add(root2,13);
	add(root2,9);
	add(root2,1);
	add(root2,10);
	add(root2,11);
	add(root2,12);

	travel(root2);
	cout<<endl;

	auto tree=mergeBST(root,root2);
	travel(tree);
	cout<<endl;
}
