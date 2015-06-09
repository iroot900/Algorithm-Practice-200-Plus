class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int result=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;++i)
        {
            int sum=target-nums[i];
            int left=i+1,right=n-1;
            while(left<right) // 2 sum problem
            {
                if(nums[left]+nums[right]==sum)
                {
                    return target;
                }
                else if(sum>nums[left]+nums[right])
                {
                    if(abs(target-result)>abs(target-nums[left]-nums[right]-nums[i]))
                    result=nums[left]+nums[right]+nums[i];
                    ++left;
                    while(left<right&&nums[left]==nums[left-1]) ++left;
                }
                else 
                {
                    if(abs(target-result)>abs(target-nums[left]-nums[right]-nums[i]))
                    result=nums[left]+nums[right]+nums[i];
                    --right;
                    while(left<right&&nums[right]==nums[right+1]) --right;
                }
            }
            while(i<n-2&&nums[i+1]==nums[i]) ++i;
        }
        return result;
    }
};
