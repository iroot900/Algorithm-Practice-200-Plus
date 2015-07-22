#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

struct TreeNode
{
	TreeNode(int val_) :val(val_) {}
	int val;
	TreeNode* left=nullptr;
	TreeNode* right = nullptr;
};

string serielize(TreeNode* root)
{
	string ret;
	queue<TreeNode*> que;
	que.push(root);
	while (!que.empty())
	{
		auto node = que.front(); que.pop();
		if (node == nullptr) { ret += "#"; }
		else {
			ret += node->val+'0'; que.push(node->left); que.push(node->right);
		}
	}
	return ret;
}

TreeNode* deserielize(string str)
{
	string ret;
	queue<TreeNode*> que;
	TreeNode* root = nullptr;
	if (str[0] == '#') return root;
	root = new TreeNode(str[0] - '0');
	que.push(root);
	int index = 1;
	while (!que.empty())
	{
		auto node = que.front(); que.pop();
		if (str[index] != '#') 	 { node->left = new TreeNode(str[index] - '0'); que.push(node->left); }
		++index;
		if (str[index] != '#') { node->right = new TreeNode(str[index] - '0'); que.push(node->right); }
		++index;
	}
	return root;
}
 
void print(TreeNode* root)
{
	if (!root) return;
	print(root->left);
	cout << root->val<<" ";
	print(root->right);
}

int main()
{
	string str = "639##8#7###";
	cout << str << endl;
	auto root = deserielize(str);
	print(root);
	cout << endl;
	cout << serielize(root)<<endl;
	return 0;
}
