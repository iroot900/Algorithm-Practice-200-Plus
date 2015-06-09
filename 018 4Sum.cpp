class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int> > result;
        if(n<4) return result;
        sort(begin(nums),end(nums));
        for(int i=0;i<n-3;++i)
        {
            for(int j=i+1;j<n-2;++j)
            {
                int left=j+1,right=n-1;
                int sum=target-nums[i]-nums[j];
                while(left<right)
                {
                    if(nums[left]+nums[right]==sum)
                    {
                        vector<int> temp={nums[i],nums[j],nums[left],nums[right]};
                        result.push_back(temp);
                        ++left;//rember it's sorted and it's two sum. one determine the other
                        while(left<right&&nums[left]==nums[left-1]) ++left;
                        --right;
                        while(left<right&&nums[right]==nums[right+1]) --right;
                    }
                    else if(nums[left]+nums[right]<sum)
                    {
                        ++left;
                      //  while(left<right&&nums[left]==nums[left-1]) ++left;
                    }
                    else
                    {
                        --right;
                      //  while(left<right&&nums[right]==nums[right+1]) --right;
                    }
                }
                while(j<n-2&&nums[j+1]==nums[j]) ++j;
            }
            while(i<n-3&&nums[i+1]==nums[i]) ++i;
        }
        return result;
    }
};
