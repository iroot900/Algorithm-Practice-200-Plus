class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size(), n=s2.size();
        if(m+n!=s3.size()) return false;
        vector<vector<bool>> f(m+1,vector<bool> (n+1,false)) ;
        
        for(int i=0;i<=m;++i)
        {
            f[i][0]=(s1.substr(0,i)==s3.substr(0,i));
        }
        
        for(int i=0;i<=n;++i)
        {
            f[0][i]=(s2.substr(0,i)==s3.substr(0,i));
        }
        
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                f[i][j]=(f[i-1][j]&&s3[i-1+j]==s1[i-1])||(f[i][j-1]&&s3[i+j-1]==s2[j-1]);
            }
        }
        
        return f[m][n];
    }
};
