class Solution {
public:
    int findMin(vector<int>& nums) {
        int mvalue=INT_MAX; // use a min 
        int left=0, right=nums.size()-1;
        int mid=0;
        while(left<=right)
        {
            //it's all about get rid of staff. record things and get rid of staff, not find it now!!
            //get rid of all, then it's founed!
            // sorted then one might be the min. then go other. if equal.. .git rid of it. 
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
