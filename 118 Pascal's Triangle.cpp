class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows,vector<int>());
        for(int i=0;i<numRows;++i)
        {
            triangle[i].push_back(1);
            int j=1;
            for(;j<i;++j)//i=2; 
            {
                triangle[i].push_back(triangle[i-1][j]+triangle[i-1][j-1]);
            }
            if(i>0) triangle[i].push_back(1);
        }
        return triangle;
    }
};
