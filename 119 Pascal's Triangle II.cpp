class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> f(rowIndex+1,0);
        f[0]=1;
        for(int i=0;i<=rowIndex;++i)
        {
            f[i]=1;
            for(int j=i-1;j>=1;--j)
            {
                f[j]=f[j]+f[j-1];
            }
        }
        return f;
    }
};
