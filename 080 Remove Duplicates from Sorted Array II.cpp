class Solution {
public:

    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int count=1;
        int result=1;
        int p=1;
        /// 1 1 1 
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1]&&count<2)
            {
                ++count; ++ result;
                nums[p++]=nums[i];
            }
            else if(nums[i]!=nums[i-1])
            {
                ++result; count=1;
                nums[p++]=nums[i];
            }
        }
        return result;
    }
};
