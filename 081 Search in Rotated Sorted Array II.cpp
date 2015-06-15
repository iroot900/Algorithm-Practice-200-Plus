class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0, right=n-1;
        while(left<=right)
        {
            int mid=(left+right)>>1;
            if(nums[mid]==target) return true;
            // 1 // 1 2 // 2 1      1 2 3 4 5 6 7 8  4 5 6 7 
            // now duplicates. 
            if(nums[left]==nums[mid]) ++left; // main logic is too judge half is in order
            else if(nums[right]==nums[mid]) --right;  // if duplicates, can't judge then, before judge get rid of it. simply. 
            else{
                if(nums[left]<=nums[mid])
                {
                    if(nums[left]<=target&&target<nums[mid])
                    right=mid-1;
                    else 
                    left=mid+1;
                }
                else
                {
                    if(nums[mid]<target&&target<=nums[right])
                    left=mid+1;
                    else 
                    right=mid-1;
                }
            }
        }
        return false;
    }
};
