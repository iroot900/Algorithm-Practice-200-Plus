class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix.front().size();
        vector<vector<int>> f(m,vector<int>(n,0));
        int mlen=0;
        for(int i=0;i<m;++i)  
        {
            f[i][0]=matrix[i][0]-'0';
            if(matrix[i][0]=='1')
            mlen=1;
        }
        
        for(int i=0;i<n;++i)  
        {
            f[0][i]=matrix[0][i]-'0';
            if(matrix[0][i]=='1')
            mlen=1;
        }
        
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {
                if(matrix[i][j]=='1')
                {
                    f[i][j]=min(f[i-1][j-1],min(f[i-1][j],f[i][j-1]))+1;
                    mlen=max(mlen,f[i][j]);
                }
                else  f[i][j]=0;
            }
        }
        return mlen*mlen;
    }
};
