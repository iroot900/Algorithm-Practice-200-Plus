class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n=prices.size();
        if(n<=1) return profit;
        vector<int> f(n); // 
        int minP=prices[0];
        f[0]=0;
        for(int i=1;i<n;++i)
        {
            profit=max(profit,prices[i]-minP);// minus the min, best can get at this position. then update profit
            f[i]=profit;
            minP=min(minP,prices[i]);//update min. very clear logic!
        }
        
        vector<int> g(n); // 
        int maxP=prices[n-1];
        profit=0;
        g[n-1]=0;
        for(int i=n-2;i>=0;--i)
        {
            profit=max(profit,maxP-prices[i]);
            g[i]=profit;
            maxP=max(maxP,prices[i]);
        }
        
        profit=0;
        for(int i=0;i<n;++i)
        {
            profit=max(profit,g[i]+f[i]);
        }
        return profit;
    }
};
