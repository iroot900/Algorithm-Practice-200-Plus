class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        vector<vector<int>> result;
        if(n<3)  return result;
        for(int i=0;i<n-2;i++)
        {
            int left=i+1,right=n-1;
            int sum=-nums[i];
            while(left<right) // solve a sorted two sum problem .. three first+ 2 sum,,  four first+second+ 2 sum.
            {
                // -1 -1 0 1
                
                if(sum==nums[left]+nums[right])
                {
                    vector<int> temp={nums[i],nums[left],nums[right]};
                    result.push_back(temp);
                    ++left;
                    while(left<right&&nums[left]==nums[left-1]) ++left;
                    --right;
                    while(left<right&&nums[right]==nums[right+1]) --right;
                }
                else if(sum>nums[left]+nums[right])
                {
                    ++left;
                  //  if(left<right&&nums[])
                }
                else
                {
                    --right;
                }
            }
            // remember this is sort. if current a get or get not somthings.    next a can't get or get not more stuff. 
            while(nums[i+1]==nums[i]) ++i;
        }
        return result;
    }
};
