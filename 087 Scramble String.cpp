class Solution {
public:
    bool isScramble(string s1, string s2) {
        int m=s1.size(), n=s2.size();
        if(m!=n) return false;
        vector<vector<vector<bool>>> f(n+1,vector<vector<bool>> (n+1,vector<bool>(n+1,false))); 
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=m;++j)
            {
                f[i][j][1]=(s1[i-1]==s2[j-1]);
            }
        }
         
         for(int k=2;k<=m;++k)
         {
              for(int i=1;i<=m-k+1;++i)
              {
                 for(int j=1;j<=m-k+1;++j)
                 {
                     for(int p=1;p<k;++p)
                     {
                         if( (f[i][j][p]&&f[i+p][j+p][k-p]) || (f[i][j+k-p][p]&&f[i+p][j][k-p])  )
                         f[i][j][k]=true;
                     }
                 }
              }
         }
         return f[1][1][m];
    }
};
