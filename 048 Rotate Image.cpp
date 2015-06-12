class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // you know that the idea is somehow    rotate and flipper over. how to get it back
        //   1  2            4   2            3   1
        //   3  4            3   1            4   2
        // swap diagnal -- know how ? think about   1  2  3  4
                                                //  5  6  7  8
                                                //  9  10 11 12
                                                //  13 14 15 16
        int n=matrix.size(); 
        for(int i=0;i<n-1;i++) //i=0 1 2 
        {
            for(int j=0;j<n-i-1;j++) //j=2 1 0
            {
                swap(matrix[i][j],matrix[n-j-1][n-i-1]);
            }
        }
        // flipper over then     
        for(int i=0;i<n/2;++i)    
        {
            for(int j=0;j<n;++j)
            {
                swap(matrix[i][j],matrix[n-i-1][j]);
            }
        }
    }
};
