class WordDictionary {
public:
     
     class TrieNode
    {
        public:
        TrieNode():leaf(false) {};
        unordered_map<char, TrieNode*> children;
        bool leaf;
    };
     
    WordDictionary():root(new TrieNode()){};
    // Adds a word into the data structure.
    void addWord(string word) {
        int n=word.size();
        auto cur=root;
        for(int i=0;i<n;++i)
        {
            auto it=cur->children.find(word[i]);
            if(it==cur->children.end())
            {
                cur->children[word[i]]=new TrieNode(); 
            }
            cur=cur->children[word[i]];
        }
        cur->leaf=true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(word,root);
    }
    
    bool search(string word, TrieNode* root) {
        
        int n=word.size();
        auto cur=root;
        for(int i=0;i<n;++i)
        {
            if(word[i]=='.')
            {
                for(auto pir: cur->children)
                {
                    if(search(word.substr(i+1), pir.second)) 
                    return true;
                }
                return false;
            }
            else
            {
                auto it=cur->children.find(word[i]);
                if(it==cur->children.end())
                {
                    return false;
                }
                cur=cur->children[word[i]];
            }
        }
        return cur->leaf;
    }
    private:
    TrieNode* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
