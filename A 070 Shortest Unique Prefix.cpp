#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std; 

class TrieNode
{
public:
	bool leaf = true;
	int count = 0;
	unordered_map<char, TrieNode*> children;
	~TrieNode()
	{
		for (auto pir : children) delete pir.second;
	}
};
 
class Trie
{
public:
	Trie() :root(new TrieNode) {}
	~Trie() { if (root) delete root; }
 	void add(string & word)
	{
		auto cur = root;
		for (int i = 0; i < word.size(); ++i)
		{ 
			if (cur->children.count(word[i] )== 0)
				cur->children[word[i]] = new TrieNode;
			cur = cur->children[word[i]];
			cur->count++;
		}
		cur->leaf = true;
	}
  
	string prefix(string & word)
	{
		string ret;
		auto cur = root;
		for (int i = 0; i<word.size(); ++i)
		{
			if (cur->children.count(word[i] == 0)) return "";
			ret += word[i];
			if(cur->children[word[i]]->count == 1) return ret;
			cur = cur->children[word[i]];
		}
		return ret;
	}
private:
	TrieNode* root;
};

vector<string> shortestUniquePre(vector<string> wrds)
{
	Trie dict;
	for (auto wrd : wrds)
		dict.add(wrd);

	vector<string> ret;
	for (auto wrd : wrds)
	{
		ret.push_back(dict.prefix(wrd));
	}
	return ret;
}

int main()
{
	vector<string> strs1 = { "zebra", "dog", "duck" };
	for (auto str : strs1) cout << str << " ";
	cout << endl;
	auto prefixs1=shortestUniquePre(strs1);
	for (auto pre : prefixs1) cout << pre << " " << endl;
	cout << endl;


	vector<string> strs2 = { "zebra", "dog", "duck", "dove" };
	for (auto str : strs2) cout << str << " ";
	auto prefixs2 = shortestUniquePre(strs2);
	for (auto pre : prefixs2) cout << pre << " " << endl;
	cout << endl;
};
