class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon.front().size();
        vector<vector<int>> f(m,vector<int> (n,0));
        f[m-1][n-1]=max(0,-dungeon[m-1][n-1])+1;
        
        for(int i=m-2;i>=0;--i)
        {                       
            f[i][n-1]=max(1,-(dungeon[i][n-1]-f[i+1][n-1]));
            
        }
        
        for(int i=n-2;i>=0;--i)
        {                       
           f[m-1][i]=max(1,-(dungeon[m-1][i]-f[m-1][i+1]));
        }
        
        
        for(int i=m-2;i>=0;--i)
        {
            for(int j=n-2;j>=0;--j)
            {                        
                f[i][j]=max(1,-(dungeon[i][j]-min(f[i+1][j],f[i][j+1])));
            }
        }
        return f[0][0];
    }
};
