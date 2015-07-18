int min_coins(vector<int>& coins, int target) {
    int m=coins.size();
    if(target==0) return 1; 
    
    vector<int> f(target+1,INT_MAX);//target+1
    f[0]=0;
    for(int i=1;i<=target;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(i-coins[j]>=0&&f[i-coins[j]]!=-1)
            {
                f[i]=min(f[i],f[i-coins[j]]+1);
            }
        }
    }
     
    return f[target]==INT_MAX?0:f[target];
}
