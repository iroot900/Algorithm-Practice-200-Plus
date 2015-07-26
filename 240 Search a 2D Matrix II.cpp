class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(); if(m<1) return false;
        int n=matrix.front().size();
        int left=n-1; int down=0;
        while(1)
        {
            while(down<m&&matrix[down][left]<target) ++down;
            if(down==m) return false;
            if(matrix[down][left]==target) return true;
            
            while(left>=0&&matrix[down][left]>target) --left;
            if(left<0) return false;
            if(matrix[down][left]==target) return true;
        } 
    }
};
