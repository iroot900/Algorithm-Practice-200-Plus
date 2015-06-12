class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> f(n,0); //max end with i;
        f[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            f[i]=max(nums[i],f[i-1]+nums[i]);
        }
        return *(max_element(begin(f),end(f)));
    }
};
