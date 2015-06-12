class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int n=matrix.size();
        if(n==0) return result;
        int left=0,right=matrix.front().size()-1,up=0,down=n-1;
       
       while(1)
       { 
            for(int i=left;i<=right;++i)  result.push_back(matrix[up][i]);
            up++;
            if(left>right||up>down) break;
            
            for(int i=up;i<=down;++i)  result.push_back(matrix[i][right]); 
            --right;
            if(left>right||up>down) break;
            
            for(int i=right;i>=left;--i)   result.push_back(matrix[down][i]); 
            --down;
            if(left>right||up>down) break;
            
            for(int i=down;i>=up;--i)  result.push_back(matrix[i][left]); 
            left++;
            if(left>right||up>down) break;
        }
        
        return result;
    }
};
