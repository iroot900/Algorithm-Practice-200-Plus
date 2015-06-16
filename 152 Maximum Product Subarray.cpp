class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //for sum.   maxi sum end with i -> f[i-1]  nums[i].. 
        // for prod  nums[i], f[i-1]*nums[i];  
        int n=nums.size();
        if(n==0) return 0;
        vector<int> f(n), g(n);
        f[0]=nums[0];
        g[0]=nums[0];
        for(int i=1;i<n;++i)
        {
            if(nums[i]>0)
               {
                   f[i]=max(nums[i],f[i-1]*nums[i]);
                   g[i]=min(nums[i],g[i-1]*nums[i]);
               }
            else
               {
                   f[i]=max(nums[i],g[i-1]*nums[i]);
                   g[i]=min(nums[i],f[i-1]*nums[i]);
               }
        }
        return *max_element(begin(f),end(f));
    }
};
