class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left=0,right=n-1,up=0,down=n-1;
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int digit=1;
        while(1)
        {
            for(int i=left;i<=right;++i) matrix[up][i]=digit++;
            ++up;
            if(up>down) break;
            for(int i=up;i<=down;++i) matrix[i][right]=digit++;
            --right;
            if(left>right) break;
            for(int i=right;i>=left;--i) matrix[down][i]=digit++;
            --down;
            if(down<up) break;
            for(int i=down;i>=up;--i) matrix[i][left]=digit++;
            ++left;
            if(left>right) break;
        }
        return matrix;
    }
};
