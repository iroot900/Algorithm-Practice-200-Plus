class Solution {
public:
    int findMin(vector<int>& nums) {
        int mvalue=INT_MAX;
        int left=0, right=nums.size()-1;
        int mid=0;
        while(left<=right)
        {
            mid=(left+right)>>1;
            if(nums[left]<nums[mid])
            {
                mvalue=min(mvalue,nums[left]);
                left=mid+1;
            }
            else if(nums[mid]<nums[right])
            {
                mvalue=min(mvalue,nums[mid]);
                right=mid-1;
            }
            else if(nums[mid]==nums[right])
            {
                mvalue=min(mvalue,nums[mid]);--right;
            }
            else if(nums[mid]==nums[left])
            {
                mvalue=min(mvalue,nums[mid]);++left;
            }
        }
        return mvalue;
    }
};
