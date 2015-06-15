class Solution {
public:
   vector<vector<string>> partition(string s) {
        
        int n=s.size();
        vector<vector<bool>> f(n,vector<bool> (n,false));
        vector<vector<string>> result;
        vector<string> solution;
        if(n==0) return result;

        f[0][0]=true;
        //1
        //1 2
        //1 2 3 
        for(int i=1;i<n;++i)
        {
            f[i][i]=true;
            f[i-1][i]=(s[i]==s[i-1]);
            for(int j=i-2;j>=0;--j)
            {
                f[j][i]=((s[i]==s[j])&&f[j+1][i-1]);
                
            }
        }
        
        DFS(0, f, s, result, solution);
        return result;
    }
    // 1 2 3 4  5 
    void DFS(int index, vector<vector<bool>>& f, const string &s, vector<vector<string>>& result, vector<string>& solution)
    {
        if(index==s.size()) {result.push_back(solution); return;}
        
        for(int i=index;i<s.size();++i)
        {
            if(f[index][i])
            {
                solution.push_back(s.substr(index,i-index+1));
                DFS(i+1, f, s, result, solution);
                solution.pop_back();
            }
        }
    }
};
