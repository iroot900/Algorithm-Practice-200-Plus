class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0) return 0;
        int n=grid.front().size();   
        
        vector<vector<int>> f(m,vector<int>(n,0));
        f[0][0]=grid[0][0];
        for(int i=1;i<m;++i)
        {
            f[i][0]=f[i-1][0]+grid[i][0];
        }
        
        for(int i=1;i<n;++i)
        {
            f[0][i]=f[0][i-1]+grid[0][i];
        }
        
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {
                f[i][j]=min(f[i-1][j],f[i][j-1])+grid[i][j];
            }
        }
        return f[m-1][n-1];
    }
};
