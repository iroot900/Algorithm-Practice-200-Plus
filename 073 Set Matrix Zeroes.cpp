class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m==0) return ;
        int n=matrix.front().size();
        // well the no space requirement makes this not ver efficient
        
        int firstcol=1, firstrow=1;
        for(int i=0;i<m;++i) // row.. if first colo is set as zeros.
        {
            if(matrix[i][0]==0) {firstcol=0;break;}
        }
        
        for(int i=0;i<n;++i)
        {
            if(matrix[0][i]==0) {firstrow=0;break;}
        }
        
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {
                if(matrix[i][j]==0)
                {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {
                if(i==0&&firstrow==0) matrix[i][j]=0;
                if(j==0&&firstcol==0) matrix[i][j]=0;
                if(matrix[0][j]==0||matrix[i][0]==0) matrix[i][j]=0;
            }
        }
        
        if(firstcol==0) 
        {
            for(int i=0;i<m;++i)
            matrix[i][0]=0;
        }
        if(firstrow==0) 
        {
            for(int i=0;i<n;++i)
            matrix[0][i]=0; 
        }
    }
};
