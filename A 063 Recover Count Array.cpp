#include <iostream>
#include <stack>
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
	cout << root->val << " with left: "<<root->count<<endl;
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
			//ingeneral next. node
			// given value from start. then greedy do down get current. and down to meet new to update. 
			// next could be right->left->left->left
			// next could be no right. then upper one
			// so 
			// iterator stack  --- next right left or stack.
			// here, gurattee right then right or left
			// start, no stack no gurrante. get the current , then go down try to update. 

			//already at the current node. to find next node
			 
			TreeNode* next=root->right;//right exist. 
			while (next->left)
			{
				next = next->left;
			} 
			root->val = next->val;
			erase(root->right, next->val);//KEY. Don't change value of next. destroy BST. and can't find it. 
			//use root->right also. to avoid delete current node. 
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

  /*
          8 
    5
 3    7
1   4
 2
 */
 
vector<int> recoverArray(vector<int>& count)
{
	int n = count.size();
	if (n == 0) return {};
	
	TreeNode* root = nullptr;
	
	for (int i = 1; i <= n; ++i) add(root, i);
	
	vector<int> result;
	for (int i = 0; i < n; ++i)
	{
		int num = findKth(root, count[i]+1);
		result.push_back(num);
		erase(root, num);
	}
	return result;
}

int main()
{
	cout << "Count Array Testing: " << endl<<endl;
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

	for (int i = 1; i <= 7; ++i)
	{
		cout << "find " << i << "th: " << findKth(root, i) << endl;
	}
	cout << endl << "delete 8 3 5 7" << endl << endl;

	erase(root, 8);
	erase(root, 3);
	erase(root, 5);
	erase(root, 7);

	print(root);
	cout << endl;

	for (int i = 1; i <= 7; ++i)
	{
		cout << "find " << i << "th: " << findKth(root, i) << endl;
	}

	cout << endl;
	cout << "recover array problem: " << endl;
	vector<int> data = { 3, 0, 1, 0 };
	for (auto digit : data)
	{
		cout << digit << " ";
	}
	cout << endl;
	auto ret = recoverArray(data);

	for (auto digit : ret)
	{
		cout << digit << " ";
	}
	cout << endl;
	return 0;
}
