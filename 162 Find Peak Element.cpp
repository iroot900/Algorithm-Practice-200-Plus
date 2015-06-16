class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        
        // since gurrantted exist. 
        int left=0, right=n-1;
        
        while(left<=right)
        {
            // 1 2 
            // 2 1
            int mid=(left+right)>>1;
            if((mid==0&&nums[mid]>nums[mid+1])||(mid==n-1&&nums[mid]>nums[mid-1])||(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1])) return mid;
            if(mid>0&&nums[mid]<nums[mid-1])
            right=mid-1;
            else if(nums[mid]<nums[mid+1])
            left=mid+1;
        }
    }
};
