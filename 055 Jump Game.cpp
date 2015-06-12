class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return true;
        int jump=nums[0];
        for(int i=1;i<n;++i)
        {
            if(jump==0) return false;
            jump=max(jump-1,nums[i]);
        }
        return true;
    }
};
