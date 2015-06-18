class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int m=grid.size();
        if(m==0) return 0;
        int n=grid.front().size();
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]=='1')
                BFS(grid, i, j,count , m, n);
            }
        }
        return count;
    }
    
    void BFS(vector<vector<char>>& grid,int i,int j,int& count ,int m,int n)
    {
        queue<pair<int,int>> que;
        que.push(make_pair(i,j));
        grid[i][j]='0';
        while(!que.empty())
        {
            auto pos=que.front();que.pop();
            int x=pos.first,y=pos.second;
            if(x>0&&grid[x-1][y]=='1')
            {
                que.push(make_pair(x-1,y));
                grid[x-1][y]='0';
            }
            if(y>0&&grid[x][y-1]=='1')
            {
                que.push(make_pair(x,y-1));
                grid[x][y-1]='0';
            }
            if(x+1<m&&grid[x+1][y]=='1')
            {
                que.push(make_pair(x+1,y));
                grid[x+1][y]='0';
            }
            if(y+1<n&&grid[x][y+1]=='1')
            {
                que.push(make_pair(x,y+1));
                grid[x][y+1]='0';
            }
        }
        ++count;
    }
};
