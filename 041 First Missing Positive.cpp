class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // sort it. and then negative or zero then go.   then for nums[i]=start++; go, if not. then start is the one.
        // 1 2 .. 100.  if something is missing then must be  some number smaller or equal -> 101 
        // another way. actually still sorting behind and very naive sort. put number in it's bucket then it's sorted. 
        // 100 bucket,  100 number betwenn at most, so each one could have a place for those in between. not in don't care.
        int n=nums.size();
        for(int i=0;i<n;++i)
        {   //nums[i]=5; put it the place it belongs to that's bucket 4.    
            while(0<nums[i]&&nums[i]<=n&&nums[nums[i]-1]!=nums[i]) // 5 is not in place...    number in 5, swap with current (5).
            swap(nums[nums[i]-1],nums[i]);  // now 5 is in place, and new nums[i] probally not.  keep change. nums[i]. 
        }
        for(int i=0;i<n;++i)
        {
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};
