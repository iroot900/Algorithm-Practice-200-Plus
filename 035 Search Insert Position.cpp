class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //auto it=lower_bound(begin(nums),end(nums),target);
        //return distance(nums.begin(),it);
        return biSearch(nums,0, nums.size()-1, target);
    }
    
    // lower bound is just binary plus left return . still think about one input.    1 ] 0~2
    int biSearch(vector<int>& nums,int left,int right, int target)
    {
        //1 ]  2
        if(left>right) return left;
        int mid=(left+right)>>1;
        if(nums[mid]==target) return mid;
        if(target<nums[mid])
        biSearch(nums,left, mid-1, target);
        else 
        biSearch(nums,mid+1, right, target);
    }
};
