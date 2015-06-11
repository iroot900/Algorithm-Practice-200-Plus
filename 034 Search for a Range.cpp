class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lower=lower_boundary(nums,  0,   nums.size()-1,   target);
        auto upper=upper_boundary(nums,  0,   nums.size()-1,   target);
        if(lower==upper) 
        {
            vector<int> result={-1,-1}; return result;
        }
        else
        {
            int l=lower;
            int r=upper;
            vector<int> result={l,r-1}; return result;
        }
    }
    // now there are duplicates 
    int lower_boundary(vector<int>& nums,int left, int right, int target)
    {
        if(left==right)
        {
            if(nums[left]>=target)
            return left;
            else return left+1;
        }
        
        int mid=(left+right)>>1;  //   [[[[[[2   2   ------/2]]]]]
        if(target<=nums[mid])   
        {        //greater or equal   0 0 0 0 1 1 1 3 3     [[0   1  2   3  4]]]
          lower_boundary(nums,  left,   mid,   target);
        }
        else  // small .let it go
          lower_boundary(nums,  mid+1,   right,   target);
    }
    
    int upper_boundary(vector<int>& nums,int left, int right, int target)
    {
        if(left==right)
        {
            if(nums[left]>target)
            return left;
            else return left+1;
        }
        //  2 2----/2
        int mid=(left+right)>>1;
        if(target<nums[mid])   
        {        //greater or equal   0 0 0 0 1 1 1 3 3     [[0   1  2   3  4]]]
          upper_boundary(nums,  left,   mid,   target);
        }
        else  // small .let it go
          upper_boundary(nums,  mid+1,   right,   target);
    }
};
