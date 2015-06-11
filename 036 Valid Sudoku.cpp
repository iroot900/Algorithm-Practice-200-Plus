class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int n=board.size();
        vector<int> filled(n,-1);
        for(int i=0;i<n;++i)
        {
            vector<int> filledH=filled;
            vector<int> filledV=filled;
            for(int j=0;j<n;++j)
            {
                if(board[i][j]!='.')
                {
                    if(filledH[board[i][j]-'1']!=-1) return false;
                    else filledH[board[i][j]-'1']=j;
                }
                
                if(board[j][i]!='.')
                {
                    if(filledV[board[j][i]-'1']!=-1) return false;
                    else filledV[board[j][i]-'1']=j;
                }
            }
        }
        
        for(int i=0;i<n;i+=3)
        {
            for(int j=0;j<n;j+=3)
            {
                vector<int> filledB=filled;
                for(int k=0;k<3;++k)
                {
                     for(int t=0;t<3;++t)
                     {
                         if(board[i+k][j+t]!='.')
                         {
                            if(filledB[board[i+k][j+t]-'1']!=-1) return false;
                            else filledB[board[i+k][j+t]-'1']=(k*3)+t+1;
                         }
                     }
                }
            }
        }
        
    return true;
    }
};
