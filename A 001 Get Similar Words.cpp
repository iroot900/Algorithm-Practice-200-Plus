//Given a list of words and a target word. Find all the words that's within K edit distance from target word

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

class TrieNode
{
public:
	unordered_map<char, TrieNode*> children;
	bool leaf = false;
	~TrieNode()
	{
		for (auto pir : children)
		{
			delete pir.second;
			pir.second = nullptr;
		}
	}
};

// trie is actualy extremely easy!!!!
class Trie
{
public:
	Trie() : root(new TrieNode) {}

	void add(const string& word)
	{
		auto node = root;
		for (int i = 0; i < (int)word.size(); ++i)
		{
			if (node->children.count(word[i]) == 0)
				(node->children)[word[i]] = new TrieNode;
			node = node->children[word[i]];
		}
		node->leaf = true;
	}

	~Trie() // very smart deal. 
	{
		if (root) { delete root; root = nullptr; }
	}
	
	// must recursively, have to go back. 
	// main logic.. start with root.  for each child. could get a new dp based on old dp. 
	// if new dp<=k and it's a leaf, add this word
	// hit the buttom, go up... dp>k and . go up...
	// when the wrd len is the same as word and dp is greater than k. no need to go further. 

	vector<string> getSimilar(int k, const string& word )
	{
		vector<string> result;
		vector<int> dp(word.size() + 1); 
		for (int i = 0; i <= (int)word.size(); ++i)	{dp[i] = i;}
		getSimilar( root, k, word, dp,  result, "");
		return result;
	}

	// traverse tree for start with empty and empty dp 
	// add child node and update current dp.
	void getSimilar(TrieNode* root, int k, const string& word, vector<int> dp, vector<string>& result, string solu)
	{
		auto node = root;
		for (auto pir : root->children)
		{
			string wrd = solu + pir.first; 
			vector<int> f = dp; 
			cout<< wrd <<":"<< endl;
			for (int i = 1; i < (int)dp.size() ; ++i)
			{ 
				if (pir.first!=word[i-1])
					f[i] = min(min(dp[i] + 1, f[i - 1] + 1), dp[i-1]+1);// delete lower and replace upper. 
				else f[i] = min(min(dp[i] + 1, f[i - 1] + 1), dp[i - 1]); // delete lower and move forward. 
				cout << f[i] << " ";
			}
			cout << endl;
			f[0] = wrd.size();
			//get the word for this path. 
			//check if valid. check if continue;
			if (f.back() > k&& wrd.size() >= word.size()) continue;
			if (f.back() <= k&&root->children[pir.first]->leaf)
			{
				result.push_back(wrd);
			}
			getSimilar(root->children[pir.first], k, word, f, result, wrd);
		}
	}

private:
	TrieNode* root;
};

int main()
{
	Trie trie;
	vector<string> words = {"this","that","tht","thate","then","thitst","ahis","ahat","ah","ata"};
	for (auto word : words)
	{
		trie.add(word);
	}

	vector<string> result;
	string word = "tha";
	result=trie.getSimilar(2,word);
	for (auto wrd : result) cout << wrd <<endl;
	cout << endl;
	return 0;
}
