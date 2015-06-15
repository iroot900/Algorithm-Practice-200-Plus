class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> f(n,0);
        vector<int> g(n,0);
        f[0]=0; 
        for(int i=1;i<n;++i)
        {
            if(ratings[i]>ratings[i-1]) f[i]=f[i-1]+1;
            else f[i]=0;
        }
        g[n-1]=0;
        for(int i=n-2;i>=0;--i)
        {
            if(ratings[i]>ratings[i+1]) g[i]=g[i+1]+1;
            else g[i]=0;
        }
        int result=0;
        for(int i=0;i<n;++i)
        result+=max(f[i],g[i]);
        result+=n;
        return result;
    }
};
