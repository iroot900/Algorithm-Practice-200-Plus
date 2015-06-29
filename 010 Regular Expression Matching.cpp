class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(), n=p.size();
        vector<vector<bool>> f(m+1,vector<bool> (n+1,false));
        f[0][0]=true;
        
        for(int i=0;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(p[j-1]!='.'&&p[j-1]!='*')
                {
                    if(i>0&&f[i-1][j-1]&&s[i-1]==p[j-1])
                    f[i][j]=true;
                }
                else if(p[j-1]=='.')
                {
                    if(i>0&&f[i-1][j-1])
                    f[i][j]=true;  
                }
                else if(j>1&&p[j-1]=='*')
                {
                    if(f[i][j-1]||f[i][j-2])
                    f[i][j]=true;
                    if(i>0&&(s[i-1]==p[j-2]||p[j-2]=='.')&&f[i-1][j])
                    f[i][j]=true;
                }
            }
        }
        return f[m][n];
    }
};
