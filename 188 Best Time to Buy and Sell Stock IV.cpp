class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // there is one local and global solution. I used it, don't like it!!
        // here used another way 
        int n=prices.size();
        if(n<2) return 0;
        if(k*2>=n) return profit(prices);// k>n-1,not right. sell at the price and buy at the price. it's not two transaction!!
        vector<int> profit(2*k+1,-100);// choose 2K number, with - ,+ ,- ,+ ,- ,+,
        
        profit[0]=0; // if we choose nothings, at lease we'll get 0
      
        // find at most 2*k number, which give us the best sum. 
        // start from one number. add another one, see if we can improve our choosen. 
        // the ith added new one as the last one and see if it help improve 
        // start check last one (most number) and then, of course could also improve less choosen number. 
        for(int i=0;i<n;++i)
        {
            for(int j=min(i+1,2*k);j>0;--j) // the most far you can get is j..()
            {
                // when i's small, not k yet, basically, when new show up. we'll add it.  
                // for minus, we'll add it, basically we don't care about it's really result, it serve the even number. 
                // up the last one first, and then go back. see if previous could be update also, use the new one as last.
                // we're keep updating it. 
                // also, since we keep new one's all the time, so more is not always better. 
                if(j&1)   profit[j]=max(profit[j],profit[j-1]-prices[i]);
                else  profit[j]=max(profit[j],profit[j-1]+prices[i]);
            }
        } 
        return *max_element(begin(profit),end(profit));// have to choose the best. 
    }
    
    int profit(vector<int>& prices)
    {
        int ret=0;
        for(int i=1;i<prices.size();i++)
        {
            ret+=max(prices[i]-prices[i-1],0);
        }
        return ret;
    }
};
