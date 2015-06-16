class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    int n=s.size();
    vector<string> result;
    if(n==0) return result;
    vector<bool> f(n,false);
    vector<vector<bool>> p(n,vector<bool>(n,false));
    for(int i=0;i<n;++i)
    {
        for(int j=i;j>=0;--j)
        {
            if((j==0||f[j-1])&&wordDict.find(s.substr(j,i-j+1))!=wordDict.end())
            {
               f[i]=true;
               p[j][i]=true;
            }
             
        }
    }
    DFS(0, f, p ,s, "", result);// this deep search is more efficient than start with s directly. don't have to check all, just go to the one that's [true], way more efficient.
    return result;
}
    void DFS(int index, vector<bool>& f, vector<vector<bool>> & p, const string &s, string solution, vector<string>& result)
    {
        if(!f[s.size()-1]) return;
        if(index==s.size()) {solution.pop_back();result.push_back(solution); return;}
        for(int i=index;i<s.size();++i)
        {
            if(f[i]&&p[index][i]) {
            DFS(i+1, f, p, s, solution+s.substr(index,i-index+1)+" ", result);
            }
        }
    }
};
