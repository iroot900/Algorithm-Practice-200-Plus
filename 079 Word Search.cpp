class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        if(m==0) return false;
        int n=board.front().size();
        vector<vector<bool>> tracking(m,vector<bool>(n,false));
        vector<vector<bool>> visited;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
               // visited=tracking; // no need to use new one, find or not, will stack pop and make it back.
                if(DFS(0,i, j, board, word,tracking)) return true;
            }
        }
        return false;
    }
    
    bool DFS(int depth, int row,int col, const vector<vector<char>>& board, const string &word,vector<vector<bool>> &visited)
    {
        if(depth==word.size()) return true;
        if(col<0||row<0||row>=board.size()||col>=board.front().size()) return false;
        if(visited[row][col]) return false;
        if(board[row][col]==word[depth])
        {  
        visited[row][col]=true;
        auto ret=DFS(depth+1,row+1, col, board, word,visited)||DFS(depth+1,row, col+1, board, word,visited)||DFS(depth+1,row-1, col, board, word,visited)||DFS(depth+1,row, col-1, board, word,visited);
        visited[row][col]=false;// don't return directly . must undo visited.
        return ret; // use a variable hold value before return
        }
        else return false;
    }
};
