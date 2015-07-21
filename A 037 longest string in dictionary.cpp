#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class TrieNode
{
	public:
		~TrieNode()
		{
			for(auto child:children)
			{
				delete child.second;
			}
		}
		bool leaf=false;
		unordered_map<char, TrieNode*> children;

};

class Trie
{
	public:
		Trie():root(new TrieNode){}
		~Trie() {
			if(root) delete root;
		}

		void insert( string word)
		{
			auto node=root;
			for(int i=0;i<word.size();++i)
			{
				if(node->children.count(word[i])==0)
				{
					node->children[word[i]]=new TrieNode;
				}
				node=node->children[word[i]];
			}
			node->leaf=true;
		}
	

		void search( string& word, string solu, const unordered_set<char> &letters)
		{
			search(root, word,solu, letters);
		}

		void search(TrieNode* node, string& word, string solu, const unordered_set<char> &letters)
		{
			//it's like check if null. for trie check leaf. 
			//here check if it's a word and if larger than solu
			if(node->leaf) { if(solu.size()>word.size()) word=solu;}
			for(auto pir:node->children)
			{
				if(letters.count(pir.first)==1)
				{
					search(pir.second,word, solu+pir.first,letters);
				}	
			}
		}

	private:
		TrieNode* root;
};

string longestString( vector<string>& strs, string word)
{
	Trie dict;
	for(auto str:strs) { dict.insert(str); }
	unordered_set<char> letters;
	for(auto cha:word) { letters.insert(cha);}
	string result;
	dict.search(result,"",letters);
	return result;
}


int main()
{
	vector<string> strs={"abcde","abc","abbbc","abbbccca","abbbcccabbcx",};
	cout<<longestString(strs,"abc")<<endl;
}
