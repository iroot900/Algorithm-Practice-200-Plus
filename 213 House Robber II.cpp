class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> f(n);
        f[0]=nums[0];
        f[1]=max(nums[0],nums[1]);
        if(n==2) return f[1];
        //start with the first house. and end with second last;
        //or start with the second, and end with last;
        for(int i=2;i<n-1;++i)
        {
            f[i]=max(f[i-1],f[i-2]+nums[i]);
        }
        int mmax=f[n-2];
        f[0]=0;
        f[1]=nums[1];
        for(int i=2;i<n;++i)
        {
            f[i]=max(f[i-1],f[i-2]+nums[i]);
        }
        return max(f[n-1],mmax);
    }
};
