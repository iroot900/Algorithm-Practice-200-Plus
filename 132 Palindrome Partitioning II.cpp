class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        if(n==0) return 0;
        vector<vector<bool>> f(n,vector<bool>(n,false));
        f[0][0]=true;
        vector<int> g(n,INT_MAX);
        g[0]=0;
          
        // very good two Palindrome
        // DP + DFS  DP+DP 
        // DP--> equation. -->get basic info-->then use it to solve.. there is a twist. more like real life problem. Nice!!!
        
        for(int i=1;i<n;++i)
        {
            // logic solid then no funny staff. Main logic+boundary!
            f[i][i]=true;
            g[i]=(g[i-1]+1);
            if(f[i-1][i]=(s[i]==s[i-1])) 
            g[i]=min(g[i],i>1?g[i-2]+1:0);// use min
            // minCut short not necessary less cut!
            for(int j=i-2;j>=0;--j)
            {
                f[j][i]=((s[i]==s[j])&&f[j+1][i-1]);
                if(f[j][i])
                g[i]=min(g[i],j>0?g[j-1]+1:0); // use min
            }
        } 
        return g[n-1];
    }
};
