class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       // here use a another more general algorithm to solve 2-D matrix search. 
       // 1 2 3 4
       // 3 4 5 6
       // 5 6 9 10 
       //start from last column ..it's greater than left upper half.  so could be use to check condition and get rid of half
       //then number is smaller, so get rid of the right lower. coz it's all bigger. 
       
       int m=matrix.size();
       if(m==0) return false;
       int n=matrix.front().size();
       
       int col=n-1,row=0;
       
       while(col>=0&&row<=m-1)
       {
           while(row<=m-1)// row down
           {
               if(matrix[row][col]==target) return true;
               if(matrix[row][col]<target) ++row;
               else break;
           }
           if(row>m-1) break;
           while(col>=0)
           {
               if(matrix[row][col]==target) return true;
               if(matrix[row][col]>target) --col;
               else break;
           }
       }
       return false;
       /*
        // first > last,  so it's actually sort.  regular binary search would be good. a little index justification..
        int m=matrix.size();
        if(m==0) return false;
        int n=matrix.front().size();
        // 1 2 3  012 345  / 3  %   
        // 4 5 6    
        int left=0, right=m*n-1;
        while(left<=right)
        {
            int mid=(left+right)>>1;
            if(matrix[mid/n][mid%n]==target)
            return true;
            else if(matrix[mid/n][mid%n]>target)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return false;*/
    }
};
