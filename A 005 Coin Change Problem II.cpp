int count_changes(vector<int>& coins, int target) {
    
    int n=coins.size();
    vector<int> f(target+1,0);
    f[0]=1;
    
    for(int i=0;i<n;++i)
    {
        for(int j=coins[i];j<=target;++j)
        f[j]+=f[j-coins[i]];
    }
    
    return f[target];
}
