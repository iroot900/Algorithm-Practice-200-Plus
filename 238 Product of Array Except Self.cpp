class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> f(n);
        if(n==0) return f;
        f[0]=1; //product till left;
        for(int i=1;i<n;++i)
        {
            f[i]=f[i-1]*nums[i-1];
        }
        
        int rightSum=1;
        for(int i=n-1;i>=0;--i)
        {
            f[i]=f[i]*rightSum;
            rightSum=nums[i]*rightSum;
        }
        return f;
    }
};
