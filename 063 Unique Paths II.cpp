class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        if(m==0) return 1;
        int n=obstacleGrid.front().size();
        
        vector<vector<int>> f(m,vector<int> (n,0));
        for(int i=0;i<n;++i)
        {
            if(obstacleGrid[0][i]==1) 
            {
                while(i<n)
                f[0][i++]=0;
            }
            else f[0][i]=1;
        }
        
        for(int i=0;i<m;++i)
        {
            if(obstacleGrid[i][0]==1) 
            {
                while(i<m)
                f[i++][0]=0;
            }
            else f[i][0]=1; 
        }
        
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {
                if(obstacleGrid[i][j]==1) f[i][j]=0;
                else f[i][j]=f[i-1][j]+f[i][j-1];
                
            }
        }
        
        return f[m-1][n-1];
    }
};
