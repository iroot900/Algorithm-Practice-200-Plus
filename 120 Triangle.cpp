class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int m=triangle.size();
        if(m==0) return 0;
        vector<int> f(m);
        f[0]=triangle[0][0];
        // 1 use small case to find the boundary no need to remmber it. 
        // and also the smallest will dot. like single one. no need to go even slightly more complicated
        for(int i=1;i<m;++i)
        {
            f[i]=f[i-1]+triangle[i][i];
            for(int j=i-1;j>=1;--j)
            {
                f[j]=min(f[j],f[j-1])+triangle[i][j];
            }
            f[0]+=triangle[i][0];
        }
        return *min_element(begin(f),end(f));
    }
};
