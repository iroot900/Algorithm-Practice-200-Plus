#include <iostream>
#include <stack>
#include <random>
#include <time.h>
#include <algorithm>
#include <vector>
using namespace std;

//binary with left count to find kth number. 
class TreeNode
{
public:
	TreeNode(int x) :val(x){}
	int val;
	int count=0;
	TreeNode* left=nullptr;
	TreeNode* right=nullptr;
};

void add(TreeNode* &root, int val)
{
	if (!root) {root = new TreeNode(val); return;}
	if (root->val > val) { root->count++; add(root->left, val); }
	else add(root->right, val);
}

void print(TreeNode* root)
{
	if (!root) return;
	print(root->left);
	cout << root->val <<" ";
	print(root->right);
} 
 
void erase(TreeNode* &root, int key)
{
	if (root == nullptr) return;
	if (root->val > key) { root->count--; erase(root->left, key); }
	else if (root->val < key) erase(root->right, key);
	if (root->val == key)
	{
		if (!(root->left))
		{
			auto temp = root;
			root = root->right;
			delete temp;
		}
		else if(!(root->right)) 
		{
			auto temp = root;
			root = root->left;
			delete temp;
		}
		else
		{ 
			TreeNode* next=root->right;//right exist. 
			while (next->left)
			{
				next = next->left;
			} 
			root->val = next->val;
			erase(root->right, next->val);//KEY. Don't change value of next. destroy BST. and can't find it. 
		}
	}
}

int findKth(TreeNode* root, int k)
{
	if (root == nullptr) { cout << "Not found!" << endl; return INT_MAX; }
	if (root->count + 1 == k) return root->val;
	if (root->count >= k) return findKth(root->left, k);
	else return findKth(root->right, k -root->count-1);
}

//same idea as return random one.. 1  keep new one in 1/count prob
void random(TreeNode* root,int& count, TreeNode*& node)
{
	if(!root) return;
	if(rand()%count==0) node=root;
	random(root->left,++count,node);
	random(root->right,++count,node);
}

  /*
          8 
    5
 3    7
1   4
 2
 */
int main()
{
	TreeNode* root = nullptr;
	add(root, 8);
	add(root, 5);
	add(root, 3);
	add(root, 4);
	add(root, 7);
	add(root, 1);
	add(root, 2);

	print(root);
	cout << endl;

	srand(time(0));
	for(int i=0;i<10;++i)
	{
		TreeNode* node=nullptr;
		int count=1;
		random(root,count,node);
		cout<<node->val<<" ";
	}
	cout<<endl;
	return 0;
}
