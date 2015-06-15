class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        
        vector<vector<string> > result; vector<string> path;
        unordered_map<string, vector<string> > father;
        
        queue<string> que;
        unordered_map<string,int> visited;
        for(auto word:dict) visited[word]=0;
        
        que.push(start);
        visited[start]=1;
        while(!que.empty())
        {
            string cur=que.front(); que.pop();
            if(cur==end) break;
            for(auto word:neighbor(cur,end,dict))
            {
                if(visited[word]==0||visited[word]==visited[cur]+1)
                {
                    if (visited[word]==0 ) que.push(word);
                    father[word].push_back(cur);
                    visited[word]=visited[cur]+1;
                }
            }
        }
        path.push_back(end);
        DFS(father,end,start,result, path);
        
        return result;
        
    }
    
    
       vector<string> neighbor(string& left, string end,unordered_set<string>& wordDict)
    {
        vector<string> result;
        for(int i=0;i<left.size();i++)
        {
            for(char cha='a';cha<='z';cha++)
                {
                    if(left[i]!=cha)
                    {
                        char temp=left[i];
                        left[i]=cha;
                        if (wordDict.find(left)!=wordDict.end()) result.push_back(left);
                        left[i]=temp;
                    }
                }
        }
        return result;
    }
    
    
    void DFS(unordered_map<string, vector<string> > & father, const string& cur,const string& start,vector<vector<string> >& result, vector<string>& path)
    {
        if(cur==start) {reverse(path.begin(),path.end());result.push_back(path);reverse(path.begin(),path.end());return; }
           
        for(auto fathers:father[cur])
        {
            path.push_back(fathers);
            DFS(father, fathers,start,result, path);
            path.pop_back();
        }
    }
};
