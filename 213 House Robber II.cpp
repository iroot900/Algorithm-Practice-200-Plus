class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n<3) return *max_element(begin(nums),end(nums));
        vector<int> f(n+1);
        f[1]=nums[0];
        f[2]=max(nums[0],nums[1]);
        // rub the first one, and not the last;
        // rub the second, and the last;
        for(int i=3;i<=n-1;++i)
        {
            // main logic. starting form 1 end n-1 . or 2 and n --->the max, but you'r not realy at 1 or n-1
            // exactly where to start or stop is determine by dynamics.
            // but they're in two catergories. 
            
            // starting from one, it's same, just end with n-1
            f[i]=max(f[i-2]+nums[i-1],f[i-1]);
        }
        
        vector<int> g(n+1);
        g[1]=0;
        g[2]=nums[1];
        for(int i=3;i<=n;++i)
        {
            //startring from 2. then 1 is zeros. just can't take it!
            g[i]=max(g[i-2]+nums[i-1],g[i-1]);
        }
        
        return max(f[n-1],g[n]);
    }
};
