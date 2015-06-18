class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode():leaf(false) {
    }
    bool leaf;
    unordered_map<char,TrieNode*> children;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        int n=s.size();
        auto cur=root;
        for(int i=0;i<n;++i)
        {
            auto it=cur->children.find(s[i]);
            if(it==cur->children.end())
            {
                cur->children[s[i]]=new TrieNode();
            }
            cur=cur->children[s[i]];
        }
        cur->leaf=true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        int n=key.size();
        auto cur=root;
        
        for(int i=0;i<n;++i)
        {
            auto it=cur->children.find(key[i]);
            if(it==cur->children.end())
            {
                return false;
            }
            cur=cur->children[key[i]];
        }
        
        return cur->leaf==true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int n=prefix.size();
        auto cur=root;
        
        for(int i=0;i<n;++i)
        {
            auto it=cur->children.find(prefix[i]);
            if(it==cur->children.end())
            {
                return false;
            }
            cur=cur->children[prefix[i]];
        }
        
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
