class Solution {
public:
     struct Node
    {
        Node():leaf(false){
            for(int i=0;i<26;i++)
            {
                children[i]=NULL;
            }
        }
        Node* children[26];
        bool leaf;
    };
    
    class Trie
    {
        public:
        Trie()
        {
            root=new Node();
        }
        
        void insert(const string& word)
        {
            auto cur=root;
            for(int i=0;i<word.size();i++)
            {
                auto it=cur->children[word[i]-'a'];
                if(it==NULL)
                cur->children[word[i]-'a']=new Node();
                cur=cur->children[word[i]-'a'];
            }
            cur->leaf=true;
        }
        
        bool isPrefix(const string& word)
        {
            auto cur=root;
            for(int i=0;i<word.size();i++)
            {
                auto it=cur->children[word[i]-'a'];
                if(it==NULL)
                return false;
                cur=cur->children[word[i]-'a'];
            }
            return true;
        }
        
        bool isWord(const string& word)
        {
            auto cur=root;
            for(int i=0;i<word.size();i++)
            {
                auto it=cur->children[word[i]-'a'];
                if(it==NULL)
                return false;
                cur=cur->children[word[i]-'a'];
            }
            return cur->leaf==true;
        }
        
        private:
        Node* root;
    };
    
    vector<string> findWords(vector<vector<char>> board, vector<string>& words) {
        unordered_set<string> result;
        if(board.size()==0) return vector<string> ();
        int m=board.size(),n=board.front().size();
        Trie dict;
        for(auto word:words)
        {
            dict.insert(word);
        }
        vector<vector<bool>> visited(m,vector<bool> (n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                string word;
               // vector<vector<bool>> visited(m,vector<bool> (n,false));
                 DFS(i,j,dict,word,board,result,visited);
            }
        }
        vector<string> final;
        for(auto item:result)
        final.push_back(item);
        return final;
    }
    
    void DFS(int i,int j,Trie& dict,string word,vector<vector<char>>&board,unordered_set<string> & result,vector<vector<bool>> &visited)
    {
            if(i<0||j<0||i==board.size()||j==board.front().size()) return;
            if(visited[i][j]) return ;
            word+=board[i][j];
            if(!dict.isPrefix(word)) return;
            if(dict.isWord(word))
            result.insert(word);
            visited[i][j]=true;
                DFS(i+1,j,dict,word,board,result,visited);
                DFS(i,j+1,dict,word,board,result,visited);
                DFS(i-1,j,dict,word,board,result,visited);
                DFS(i,j-1,dict,word,board,result,visited);
            visited[i][j]=false; 
    }
};
