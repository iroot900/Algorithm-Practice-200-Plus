class Solution {
public:
    int search(vector<int>& nums, int target) {
        return biSearch(nums, 0, nums.size()-1,target);
    }
    int biSearch(vector<int>& nums,int left,int right,int target)
    {
        if(left>right) return -1;
        int mid=(left+right)>>1;
        //get rid of half
        if(target==nums[mid]) return mid;
        // boundary condition..
        // 2 1   1 2    //  2  1  zhao 2 or 1
        //  little small boundary condition is important and handy , be smart.. also,  mid is alwary  on left part. 
        if(nums[left]<=nums[mid]) // the safe way. find the sorted half and tell if it's in it..
        {
            if(target>=nums[left]&&target<=nums[mid])
            biSearch(nums, left, mid,target);
            else biSearch(nums, mid+1, right,target);
        }
        else
        {
            if(target>=nums[mid]&&target<=nums[right])
            biSearch(nums, mid+1, right,target);
            else biSearch(nums, left, mid,target);
        }
    }
};
