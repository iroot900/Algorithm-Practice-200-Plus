class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
    int n=s.size();
    if(n==0) return false;
    vector<bool> f(n,false);
    for(int i=0;i<n;++i)
    {
        for(int j=i;j>=0;--j)
        {
            if((j==0||f[j-1])&&wordDict.find(s.substr(j,i-j+1))!=wordDict.end())
            f[i]=true;
        }
    }
    return f[n-1];
    }
};
