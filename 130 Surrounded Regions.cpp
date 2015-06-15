class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        if(m<3) return;
        int n=board.front().size();
        for(int i=0;i<m;++i)
        {
            if(board[i][0]=='O')
            BFS(i, 0, board, m, n);
            if(board[i][n-1]=='O')
            BFS(i, n-1, board, m, n);
        }
        
        for(int i=0;i<n;++i)
        {
            if(board[0][i]=='O')
            BFS(0, i, board, m, n);
            if(board[m-1][i]=='O')
            BFS(m-1, i, board, m, n);
        }
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(board[i][j]=='.') board[i][j]='O';
                else board[i][j]='X';
            }
        }
    }
    
    void BFS(int i,int j, vector<vector<char>>& board,int m,int n)
    {
        queue<pair<int,int>> que;
        que.push(make_pair(i,j));
        board[i][j]='.';
        while(!que.empty())
        {
            auto pos=que.front();que.pop();
            int x=pos.first,y=pos.second;
            
            if(x>0&&board[x-1][y]=='O')
            {
                que.push(make_pair(x-1,y));
                board[x-1][y]='.';
            }
            
            if(y>0&&board[x][y-1]=='O')
            {
                que.push(make_pair(x,y-1));
                board[x][y-1]='.';
            }
            
            if(x+1<m&&board[x+1][y]=='O')
            {
                que.push(make_pair(x+1,y));
                board[x+1][y]='.';
            }
            
            if(y+1<n&&board[x][y+1]=='O')
            {
                que.push(make_pair(x,y+1));
                board[x][y+1]='.';
            }
        }
    }
};
