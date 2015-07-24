#include <iostream>
#include <stack>
using namespace std;

class TreeNode
{
public:
	TreeNode(int x) :val(x){}
	int val;
	TreeNode* left=nullptr;
	TreeNode* right=nullptr;
};

void add(TreeNode* &root, int val)
{
	if (!root) {root = new TreeNode(val); return;}
	if (root->val > val) add(root->left, val);
	else add(root->right, val);
}

void print(TreeNode* root)
{
	if (!root) return;
	print(root->left);
	cout << root->val << " ";
	print(root->right);
}

void print2(TreeNode* root)
{
	stack<TreeNode* > sta;
	
	TreeNode* cur = nullptr;
	cur = root;// a cur root. go all cur left. then right. 
	while (cur || !sta.empty())
	{
		while (cur)
		{
			sta.push(cur); cur = cur->left;
		}
		auto node = sta.top(); sta.pop();
		cout << node->val << " ";
		cur = node->right;
	}
}

void print3(TreeNode* root)
{
	stack<TreeNode* > sta;

	TreeNode* cur = nullptr;
	cur = root;// a cur root. go all cur left. then right. 
	while (cur || !sta.empty())
	{
		while (cur)
		{
			sta.push(cur); cur = cur->right;
		}
		auto node = sta.top(); sta.pop();
		cout << node->val << " ";
		cur = node->left;
	}
}

pair<int,int>  twoSum(TreeNode* root, int target)
{
	pair<int, int> result;
	stack<TreeNode*> staL;
	stack<TreeNode*> staR;
	auto curL = root;
	auto curR = root;
	int valL = -1, valR = -1;
	bool left = true; 
	bool right = true;
	while (1)
	{ 
		if (left)
		{ 
			while (curL) {  staL.push(curL); curL = curL->left; }
			valL = staL.top()->val;  curL = staL.top()->right; staL.pop();
			left = false;
		}
		if (right)
		{
			while (curR) {  staR.push(curR); curR = curR->right; }
			valR = staR.top()->val; curR = staR.top()->left; staR.pop();
			right = false;
		} 
		if (valL >= valR) {   return{}; }

		if (valL + valR == target) return{ valL, valR };
		if (valL + valR > target) { right = true; }
		else left = true; 
	} 
}

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

	print2(root);
	cout << endl;

	print3(root);
	cout << endl;

	for (int i = 0; i < 15; ++i)
	{
		auto ret = twoSum(root, i);
		cout <<i <<": " <<ret.first << " " << ret.second << endl;
	}
	return 0;
}
  
